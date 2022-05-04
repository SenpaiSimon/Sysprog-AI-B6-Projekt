// Includes
#include <linux/init.h>
#include <linux/module.h>
#include <linux/cdev.h>
#include <linux/device.h>
#include <linux/kernel.h>
#include <linux/fs.h>
#include <linux/uaccess.h>
#include <linux/ioctl.h>
#include <linux/gpio.h>

// Defines
#define DEVICE_NAME "led_matrix"

// TODO
#define GPIO_4 4

#define CMD_1 _IOR('a', 'a', int32_t*)
#define CMD_2 _IOR('a', 'b', int32_t*)
#define CMD_3 _IOR('a', 'c', int32_t*)

// Structs
static struct class *dev_class = NULL;
static struct cdev cdev;
static int dev_major = 0;

// Const structs
static const struct file_operations fops =
{
	.owner = THIS_MODULE,
	.open = dev_open,
	.release = dev_release,
	.unlocked_ioctl = dev_ioctl,
	.read = dev_read,
	.write = dev_write
};

// Prototypes
static int dev_uevent(struct device *dev, struct kobj_uevent_env *env);
static int __init dev_init(void);
static void __exit dev_exit(void);
static int dev_open(struct inode *inode, struct file *file);
static int dev_release(struct inode *inode, struct file *file);
static ssize_t dev_read(struct file *file, char __user *buf, size_t count, loff_t *offset);
static ssize_t dev_write(struct file *file, const char __user *buf, size_t count, loff_t *offset);
static long dev_ioctl(struct file *file, unsigned int cmd, unsigned long arg);
