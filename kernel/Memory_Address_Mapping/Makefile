
ifneq	($(KERNELRELEASE),)
obj-m	:= dram.o sys_reg.o

else
KDIR	:= /lib/modules/$(shell uname -r)/build
PWD	:= $(shell pwd)

all: modules app

app: fileview mem_map

fileview:
	g++ -o fileview fileview.cpp -D_LARGEEFILE64_SOURCE
mem_map:
	gcc -o mem_map mem_map.c

modules:
	$(MAKE) -C $(KDIR) SUBDIRS=$(PWD) modules 
clean: app_clean
	$(MAKE) -C $(KDIR) SUBDIRS=$(PWD) clean

app_clean:
	-rm -rf fileview mem_map
endif

