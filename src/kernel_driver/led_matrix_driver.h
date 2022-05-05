#ifndef __LED_MATRIX_DRIVER__
#define __LED_MATRIX_DRIVER__

/********************************************************************************
 * Includes from external Librarys
 ********************************************************************************/
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

/********************************************************************************
 * Includes from internal Librarys
 ********************************************************************************/
#include "gpio_inits/gpio_pins.h"
#include "gpio_inits/gpio_init.h"
#include "ioct_cmd.h"

/********************************************************************************
 * Global Defines
 ********************************************************************************/
#define DEVICE_NAME "led_matrix"

/********************************************************************************
 * Structs
 ********************************************************************************/
static struct class *dev_class = NULL;
static struct cdev cdev;

/********************************************************************************
 * Function Prototypes
 ********************************************************************************/
static int dev_uevent(struct device *dev, struct kobj_uevent_env *env);
static int __init dev_init(void);
static void __exit dev_exit(void);
static int dev_open(struct inode *inode, struct file *file);
static int dev_release(struct inode *inode, struct file *file);
static ssize_t dev_read(struct file *file, char __user *buf, size_t count, loff_t *offset);
static ssize_t dev_write(struct file *file, const char __user *buf, size_t count, loff_t *offset);
static long dev_ioctl(struct file *file, unsigned int cmd, unsigned long arg);

#endif