#ifndef LED_MATRIX_DRIVERs
#define LED_MATRIX_DRIVER

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
#include <stdbool.h>

// own includes
#include "gpio_inits/gpio_pins.h"
#include "gpio_inits/gpio_init.h"

// Defines
#define DEVICE_NAME "led_matrix"

// Commands for IOCT
#define CMD_1 _IOW('a', 'a', int32_t*)
#define CMD_2 _IOW('a', 'b', int32_t*)
#define CMD_3 _IOW('a', 'c', int32_t*)

// Structs
static struct class *dev_class = NULL;
static struct cdev cdev;
static int dev_major = 0;

// Prototypes
static int dev_uevent(struct device *dev, struct kobj_uevent_env *env);
static int __init dev_init(void);
static void __exit dev_exit(void);
static int dev_open(struct inode *inode, struct file *file);
static int dev_release(struct inode *inode, struct file *file);
static ssize_t dev_read(struct file *file, char __user *buf, size_t count, loff_t *offset);
static ssize_t dev_write(struct file *file, const char __user *buf, size_t count, loff_t *offset);
static long dev_ioctl(struct file *file, unsigned int cmd, unsigned long arg);

#endif