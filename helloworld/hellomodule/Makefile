obj-m += hello.o

all:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules

load:
	@printf "Carregando o Modulo \n"
	sudo insmod hello.ko
	@printf "Listando modulos \n"
	lsmod | tail
	@printf "Mostrando o log feito pelo modulo"
	tail -f /var/log/messages

unload: 
	@printf "Removendo o Modulo\n"
	rmmod hello

clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean
