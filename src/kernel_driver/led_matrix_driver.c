#include "led_matrix_driver.h"

static int dev_major = 0;

/********************************************************************************
 * Struct for all the available file operations
 ********************************************************************************/
static const struct file_operations fops = {
	.owner = THIS_MODULE,
	.open = dev_open,
	.release = dev_release,
	.unlocked_ioctl = dev_ioctl,
	.read = dev_read,
	.write = dev_write
};

/********************************************************************************
 * Add an event to the device
 ********************************************************************************/
static int dev_uevent(struct device *dev, struct kobj_uevent_env *env) {
	add_uevent_var(env, "DEVMODE=%#o", 0666);
	return 0;
}

/********************************************************************************
 * Initialize the device
 ********************************************************************************/
static int __init dev_init(void) {
	// Initialize the device itself
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
	printk(KERN_INFO "Init GPIO Led Matrix Driver\r\n");

    init_all_gpios();
	return 0;
}

/********************************************************************************
 * Unregister the device
 ********************************************************************************/
static void __exit dev_exit(void)
{
    exit_all_gpios();

	// Remove and unregister the device
	device_destroy(dev_class, MKDEV(dev_major, 0));
	class_unregister(dev_class);
	class_destroy(dev_class);
	unregister_chrdev_region(MKDEV(dev_major, 0), MINORMASK);
	printk(KERN_INFO "Unregister GPIO Led Matrix Driver\r\n");
	return;
}

/********************************************************************************
 * Open the device from User App
 ********************************************************************************/
static int dev_open(struct inode *inode, struct file *file)
{
	printk(KERN_INFO "GPIO LED Driver started access\n");
	return 0;
}

/********************************************************************************
 * Close the device from User App
 ********************************************************************************/
static int dev_release(struct inode *inode, struct file *file)
{
	printk(KERN_INFO "GPIO LED Matrix Driver stopped access\n");
	return 0;
}

/********************************************************************************
 * Read the device from CMD
 ********************************************************************************/
static ssize_t dev_read(struct file *file, char __user *buf, size_t count, loff_t *offset)
{
	int len;
	char buffer[128];
	uint8_t gpio_value;
	printk(KERN_INFO "GPIO LED Matrix Driver read\n");

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

/********************************************************************************
 * Write to the device from CMD
 ********************************************************************************/
static ssize_t dev_write(struct file *file, const char __user *buf, size_t count, loff_t *offset)
{
	uint8_t data;
	int ret = copy_from_user(&data, buf, 1);
	if(ret == 0) pr_info("GPIO LED Matrix Driver write success\n");
	if(data == '1') {
		// action
	}
	if(data == '0') {
		// action
	}
	return count;
}

/********************************************************************************
 * IO-Control Operations
 ********************************************************************************/
static long dev_ioctl(struct file *file, unsigned int cmd, unsigned long arg)
{
	printk("GPIO LED Matrix Driver IOCT accessed\n");
	switch(cmd) {
		case CMD_1: {

			break;
		}
		case CMD_2: {
			
			break;
		}
		case CMD_3: {
			
			break;
		}
		default:
			pr_err("Unkown command! \n");
		break;
	}
	return 0;
}

/********************************************************************************
 * Link the init end exit functions
 ********************************************************************************/
module_init(dev_init);
module_exit(dev_exit);

/********************************************************************************
 * Signing of the Kernel Driver
 ********************************************************************************/
MODULE_LICENSE("GPL");
MODULE_AUTHOR("Simon Obermeier & Anton Kraus");
MODULE_DESCRIPTION("LED Matrix Driver");
MODULE_VERSION("1.0");
