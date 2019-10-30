KERNEL_DIR := /lib/modules/$(shell uname -r)/build
PWD := $(shell pwd)

obj-m := my_module.o

my_module-objs := main.o

default:
	$(MAKE) -C $(KERNEL_DIR) SUBDIRS=$(PWD) modules

clean:
	$(MAKE) -C $(KERNEL_DIR) SUBDIRS=$(PWD) clean
	rm *~
