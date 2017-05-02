#include <linux/module.h>
#include <linux/moduleparam.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/stat.h>

MODULE_LICENSE("GPL") ;
MODULE_AUTHOR("Tushaar Gangarapu") ;

static short int short_var = 1 ;
static int int_var = 420 ;
static long int long_var = 9999 ;
static char *string_var = "kernel" ;
static int int_array[2] = { -1, -1 } ;
static int arr_argc = 0 ;

module_param(short_var, short, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP) ;
MODULE_PARM_DESC(short_var, "A short integer") ;
module_param(int_var, int, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH) ;
MODULE_PARM_DESC(int_var, "An integer") ;
module_param(long_var, long, S_IRUSR) ;
MODULE_PARM_DESC(long_var, "A long integer") ;
module_param(string_var, charp, 0000) ;
MODULE_PARM_DESC(string_var, "A character string") ;

module_param_array(int_array, int, &arr_argc, 0000) ;
MODULE_PARM_DESC(int_array, "An array of integers") ;

static int __init hello_5_init(void) {
	int i;
	printk(KERN_INFO "Hello, world \n=============\n") ;
	printk(KERN_INFO "short_var is a short integer: %hd\n", short_var) ;
	printk(KERN_INFO "int_var is an integer: %d\n", int_var) ;
	printk(KERN_INFO "long_var is a long integer: %ld\n", long_var) ;
	printk(KERN_INFO "string_var is a string: %s\n", string_var) ;

	for (i = 0; i < (sizeof int_array / sizeof (int)); i++) {
		printk(KERN_INFO "int_array[%d] = %d\n", i, int_array[i]);
	}
	printk(KERN_INFO "Got %d arguments for int_array.\n", arr_argc);
	return 0;
}

static void __exit hello_5_exit(void) {
	printk(KERN_INFO "Goodbye, world\n");
}

module_init(hello_5_init);
module_exit(hello_5_exit);
