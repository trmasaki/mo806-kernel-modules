//<memory initial>=
/* Necessary includes for device drivers */
#include <linux/init.h>
//#include <linux/config.h>
#include <linux/module.h>
#include <linux/kernel.h> /* printk() */
#include <linux/slab.h> /* kmalloc() */
#include <linux/fs.h> /* everything... */
#include <linux/errno.h> /* error codes */
#include <linux/types.h> /* size_t */
#include <linux/proc_fs.h>
#include <linux/fcntl.h> /* O_ACCMODE */
#include <asm/system.h> /* cli(), *_flags */
#include <asm/uaccess.h> /* copy_from/to_user */

MODULE_LICENSE("Dual BSD/GPL");

/* Declaration of memory.c functions */
int memory_open(struct inode *inode, struct file *filp);
int memory_release(struct inode *inode, struct file *filp);
ssize_t memory_read(struct file *filp, char *buf, size_t count, loff_t *f_pos);
ssize_t memory_write(struct file *filp, char *buf, size_t count, loff_t *f_pos);
void memory_exit(void);
int memory_init(void);

/* Structure that declares the usual file */
/* access functions */
struct file_operations memory_fops = {
  read: memory_read,
  write: memory_write,
  open: memory_open,
  release: memory_release
};

/* Declaration of the init and exit functions */
module_init(memory_init);
module_exit(memory_exit);

/* Global variables of the driver */
/* Major number */
int memory_major = 60;
/* Buffer to store data */
char *memory_buffer;


//<memory init module> =
int memory_init(void) {
  int result;

  printk(KERN_INFO "funcao memory_init() foi chamada\n");
  /* Registering device */
  result = register_chrdev(memory_major, "memory", &memory_fops);
  if (result < 0) {
    printk(
      "<1>memory: cannot obtain major number %d\n", memory_major);	
    return result;
  }

  /* Allocating memory for the buffer */
  //memory_buffer = kmalloc(1, GFP_KERNEL); 
  memory_buffer = kmalloc(3, GFP_KERNEL); 
  if (!memory_buffer) { 
    result = -ENOMEM;
    goto fail; 
  } 
//  memset(memory_buffer, 0, 1);
memset(memory_buffer, 0, 3);
  printk("<1>Inserting memory module\n"); 
  return 0;

  fail: 
    memory_exit(); 
    return result;
}

//<memory exit module> =
void memory_exit(void) {
  /* Freeing the major number */
  unregister_chrdev(memory_major, "memory");

  /* Freeing buffer memory */
  if (memory_buffer) {
    kfree(memory_buffer);
  }

  printk("<1>Removing memory module\n");
  printk(KERN_INFO "funcao memory_exit() foi chamada\n");
}

//<memory open> =
int memory_open(struct inode *inode, struct file *filp) {
  printk(KERN_INFO "funcao memory_open() foi chamada\n");
  /* Success */
  return 0;
}

//<memory release> =
int memory_release(struct inode *inode, struct file *filp) {
   printk(KERN_INFO "funcao memory_release() foi chamada\n");
  /* Success */
  return 0;
}

//<memory read> =
ssize_t memory_read(struct file *filp, char *buf, 
                    size_t count, loff_t *f_pos) { 
 
  printk(KERN_INFO "funcao memory_read() foi chamada\n");
  /* Transfering data to user space */ 
// copy_to_user(buf,memory_buffer,1;
  copy_to_user(buf,memory_buffer,3);

  /* Changing reading position as best suits */ 
  if (*f_pos == 0) { 
//    *f_pos+=1; 
    *f_pos+=3; 
    return 1; 
  } else { 
    return 0; 
  }
}


//<memory write> =
ssize_t memory_write( struct file *filp, char *buf,
                      size_t count, loff_t *f_pos) {

  char *tmp;
  printk(KERN_INFO "funcao memory_write() foi chamada\n");
  tmp=buf+count-1;
  //copy_from_user(memory_buffer,tmp,1);
  copy_from_user(memory_buffer,buf,3);
  return 1;
}

