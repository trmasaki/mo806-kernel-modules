See following url for building instructions
http://www.cyberciti.biz/tips/build-linux-kernel-module-against-installed-kernel-source-tree.html

hello.ko is kernel module file. To see information about module, enter:
$ modinfo hello.ko 

To load kernel module, enter:
$ sudo insmod hello.ko
or
$ sudo modprobe hello

To list installed Linux kernel module, enter:
$ lsmod
$ lsmod | grep hello


To remove hello Linux kernel module, enter:
$ rmmod hello
This module just logs message to a log file called /var/log/messages (/var/log/syslog), enter:
$ tail -f /var/log/messages
