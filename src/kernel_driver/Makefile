obj-m += led_matrix_driver.o
# led_matrix_driver-objs := gpio_inits/gpio_init.o
KDIR = /lib/modules/$(shell uname -r)/build

# INCLUDES = -I$(src)/gpio_inits

# ccflags-y := $(INCLUDES)
ccflags-y += -std=gnu99

all: default clean
default:
	make -C $(KDIR) M=$(shell pwd) modules
clean:
	@rm -rf *.o .*.cmd .*.flags *.mod.c *.order *.mod .*.o.d
	@rm -rf .*.*.cmd *.symvers *~ *.*~ TODO.*
	@rm -rf .tmp*
	@rm -rf .tmp_versions
	@rm -rf gpio_inits/*.o gpio_inits/.*.o.d gpio_inits/.*.o.cmd
disclean: clean
	@rm -rf *.ko
install: default clean
	@sudo insmod led_matrix_driver.ko
	@rm -rf *.ko