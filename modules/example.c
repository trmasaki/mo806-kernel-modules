#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/init.h>
#include <linux/fs.h>

MODULE_AUTHOR("Ricardo");
MODULE_DESCRIPTION("Simples módulo de demonstração: Hello world");
MODULE_VERSION("1.0");
MODULE_ALIAS("HELLO mo806");
MODULE_LICENSE("GNU");



int init_module(void){
	
	printk(KERN_ALERT "Hello world - MO806\n");
	
	return 0;
}

void cleanup_module(void){	

	printk(KERN_ALERT "Goodbye - MO806!\n");
}

