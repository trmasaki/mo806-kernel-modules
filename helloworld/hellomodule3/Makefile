obj-m += hello.o

all:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules

load:
	@printf "Carregando o Modulo \n"
	sudo insmod hello.ko
	@printf "Listando modulos \n"
	lsmod | less
	@printf "Mostrando o log feito pelo modulo"
	tail /var/log/messages

unload: 
	@printf "Removendo o Modulo\n"
	sudo rmmod hello
	@sleep 1
	tail /var/log/messages

clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean
