obj-m += memory.o

all:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules

load:
	@printf "Carregando o Modulo \n"
	sudo insmod memory.ko
	sudo mknod /dev/memory c 60 0
	sudo chmod 666 /dev/memory
	@printf "Listando modulos \n"
	lsmod | less
	@printf "Mostrando o log feito pelo modulo\n"

unload: 
	@printf "Removendo o Modulo\n"
	sudo rmmod memory
	sudo rm /dev/memory
	@sleep 1

test:
	@printf "Escrevendo no memory\n"
	echo -n abcdef > /dev/memory
	@printf "Lendo do memory\n"	
	cat /dev/memory
	@printf "\n"

clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean

