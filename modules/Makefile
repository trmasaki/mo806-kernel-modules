
obj-m += moduleMO806.o
#obj-m += template.o

TARGET = moduleMO806

INSTALL_DIR = /lib/modules/$(shell uname -r)

all:
	make -C $(INSTALL_DIR)/build M=$(PWD) modules

clean:
	make -C $(INSTALL_DIR)/build M=$(PWD) clean

install:
	install -d $(INSTALL_DIR)/misc
	install -c $(TARGET).ko $(INSTALL_DIR)/misc
