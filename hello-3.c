#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>

static char *hello_data __initdata = "4.4.0-71-generic" ;

static int __init hello_3_init(void) {
	printk(KERN_INFO "Welcome to kernel programming - %s\n", hello_data) ;
	return 0 ;
}

static void __exit hello_3_exit(void) {
	printk(KERN_INFO "Goodbye kernel\n") ;
}

module_init(hello_3_init) ;
module_exit(hello_3_exit) ;
