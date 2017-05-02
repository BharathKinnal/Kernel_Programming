#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>	
#define AUTHOR "Tushaar Gangarapu"
#define DESC   "A sample kernel program"

static int __init init_hello_4(void) {
	printk(KERN_INFO "Welcome to kernel programming\n") ;
	return 0 ;
}

static void __exit cleanup_hello_4(void) {
	printk(KERN_INFO "Goodbye kernel\n") ;
}

module_init(init_hello_4) ;
module_exit(cleanup_hello_4) ;

MODULE_LICENSE("Dual MIT/GPL") ;
MODULE_AUTHOR(AUTHOR) ;
MODULE_DESCRIPTION(DESC) ;
MODULE_SUPPORTED_DEVICE("testdevice") ;
