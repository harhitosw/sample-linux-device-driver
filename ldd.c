#include<linux/init.h>
#include<linux/module.h>
#include<linux/proc_fs.h>
MODULE_LICENSE("GPL");
MODULE_AUTHOR("Harsh H. Oswal <oswalharsh30@gmail.com>");
MODULE_DESCRIPTION("An attempt to learn about device drivers in Linux.");
static struct proc_dir_entry * cus_proc_entry;

static ssize_t driver_read(struct file * file_pointer, char  *user_space_buffer, size_t count, loff_t * offset){
    printk("Reading some data");
    char msg[] = "Ack!\n";
    size_t len = strlen(msg);
     if (*offset >= len){
        return 0;
     }
      int res;
      res = copy_to_user(user_space_buffer,msg,len);
     *offset += len;
    return len;
}
// assign function pointer to driver_read
struct proc_ops driver_ops = {
    // refer https://github.com/torvalds/linux/blob/master/include/linux/proc_fs.h for proc_ops struct
    .proc_read = driver_read
};


static int harsh_init_driver(void){
    // this one entry which we will be creating in proc file system
    printk("IN INIT : adding entry from proc \n");
    // ls /proc/ shall show HarshDriver listed
    cus_proc_entry = proc_create("HarshDriver",0, NULL, &driver_ops);
    printk("IN INIT : added entry from proc \n");
    return 0;
}

static void harsh_deinit_driver(void){
printk("IN DENINIT : removing entry from proc \n");
proc_remove(cus_proc_entry);
printk("IN DENINIT : removed entry from proc");
}

// refer https://www.kernel.org/doc/html/latest/driver-api/basics.html for more info

module_init(harsh_init_driver);
module_exit(harsh_deinit_driver);

