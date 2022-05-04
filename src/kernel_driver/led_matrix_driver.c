#include "led_matrix_driver.h"

static const struct file_operations fops = {
	.owner = THIS_MODULE,
	.open = dev_open,
	.release = dev_release,
	.unlocked_ioctl = dev_ioctl,
	.read = dev_read,
	.write = dev_write
};

static int dev_uevent(struct device *dev, struct kobj_uevent_env *env) {
	add_uevent_var(env, "DEVMODE=%#o", 0666);
	return 0;
}

static int __init dev_init(void) {
    // Init of the device itself
	int err;
	dev_t dev;
	err = alloc_chrdev_region(&dev, 0, 1, DEVICE_NAME);
	dev_major = MAJOR(dev);
	dev_class = class_create(THIS_MODULE, DEVICE_NAME);
	dev_class->dev_uevent = dev_uevent;
	cdev_init(&cdev, &fops);
	cdev.owner = THIS_MODULE;
	cdev_add(&cdev, MKDEV(dev_major, 0), 1);
	device_create(dev_class, NULL, MKDEV(dev_major, 0), NULL, DEVICE_NAME);
	printk(KERN_INFO "Hello from %s\n", __func__);

	// init all the needed gpios
    init_all_gpios();
	return 0;
}

static void __exit dev_exit(void)
{
    // free up all the GPIOS 
    exit_all_gpios();

    // Remove the device
	device_destroy(dev_class, MKDEV(dev_major, 0));
	class_unregister(dev_class);
	class_destroy(dev_class);
	unregister_chrdev_region(MKDEV(dev_major, 0), MINORMASK);
	printk(KERN_INFO "Good Bye from %s\n", __func__);
	return;
}

static int dev_open(struct inode *inode, struct file *file)
{
	printk(KERN_INFO "Device open\n");
	return 0;
}

static int dev_release(struct inode *inode, struct file *file)
{
	printk(KERN_INFO "Device close\n");
	return 0;
}

static ssize_t dev_read(struct file *file, char __user *buf, size_t count, loff_t *offset)
{
	int len;
	char buffer[128];
	uint8_t gpio_value;
	printk(KERN_INFO "Device read\n");

    // actual output to user
	gpio_value = gpio_get_value(H_GPIO_1);
	len = snprintf(buffer, sizeof(buffer), "GPIO_4: %d\n", gpio_value);
	if(copy_to_user(buf, buffer, len) > 0) 
		pr_err("dev_read(): ERROR\n");
	if(*offset == 0) {
		*offset += len;
		return len;
	} else {
		return 0;
	}
}

static ssize_t dev_write(struct file *file, const char __user *buf, size_t count, loff_t *offset)
{
	uint8_t data;
	int ret = copy_from_user(&data, buf, 1);
	if(ret == 0) pr_info("Write successful!\n");
	if(data == '1') {
		// action
	}
	if(data == '0') {
		// action
	}
	return count;
}

static long dev_ioctl(struct file *file, unsigned int cmd, unsigned long arg)
{
	printk("Device ioctl\n");
	switch(cmd) {
		case CMD_1: {
			gpio_set_value(H_GPIO_1, arg);
			break;
		}
		case CMD_2: {
			gpio_set_value(H_GPIO_1, 1);
			break;
		}
		case CMD_3: {
			gpio_set_value(H_GPIO_1, 0);
			break;
		}
		default:
			pr_err("Unkown command! \n");
		break;
	}
	return 0;
}

module_init(dev_init);
module_exit(dev_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Simon Obermeier & Anton Kraus");
MODULE_DESCRIPTION("LED Matrix Driver");
MODULE_VERSION("1.0");
