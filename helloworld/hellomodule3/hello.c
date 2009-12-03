#include <linux/init.h>	
#include <linux/module.h>	
#include <linux/kernel.h>	

MODULE_LICENSE("GPL");

static int __init hello_inicia(void)
{
	printk(KERN_INFO "funcao hello_inicia() foi chamada\n");
	return 0;
}

static void __exit hello_finaliza(void)
{
	printk(KERN_INFO "funcao hello_finaliza() foi chamada\n");
}

module_init(hello_inicia);
module_exit(hello_finaliza);
