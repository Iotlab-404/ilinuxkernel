 #include <linux/module.h>    
 #include <linux/proc_fs.h>    
 #include <linux/sched.h>
 #include <asm/uaccess.h>
 #include <asm/desc.h>
 #include <asm/pgtable.h>
 #include <asm/desc.h>
 //#include <asm/system.h>
#include <asm/paravirt.h>
#include <linux/seq_file.h>

 static char modname[] = "sys_reg";
 struct gdtr_struct{
	short limit;
	unsigned long address __attribute__((packed));
  };

 static unsigned int cr0,cr3,cr4;
// static struct gdtr_struct gdtr;
static struct desc_ptr gdtr;
 static int my_proc_show( struct seq_file *m, void *v )
 {
	struct mm_struct *mm;

	mm = current->active_mm;
	cr0 = read_cr0();
    cr3 = read_cr3();
	cr4 = __read_cr4();
	//asm(" sgdt gdtr");
	native_store_gdt(&gdtr);

	seq_printf( m, "cr4=%08X  ", cr4 );
	seq_printf( m, "PSE=%X  ", (cr4>>4)&1 );
	seq_printf( m, "PAE=%X  ", (cr4>>5)&1 );
	seq_printf( m, "\n" );
	seq_printf( m, "cr3=%08X cr0=%08X\n",cr3,cr0);
	seq_printf( m, "pgd:0x%08X\n",(unsigned int)mm->pgd);
	seq_printf( m, "gdtr address:%lX, limit:%X\n", gdtr.address,gdtr.size);
//	len += seq_printf( m, "cpu_gdt_table address:0x%08lX\n", cpu_gdt_table);

	return 0;
}
static int mytest_proc_open(struct inode *inode, struct file *file)
{
	return single_open(file, my_proc_show, inode->i_private);
}

static int mytest_proc_write(struct seq_file *seq, const void *data, size_t len)
{
	seq_printf(seq, "my_test_proc_write\n");
	return 0;
}

static const struct file_operations mytest_proc_fops = {
 .owner = THIS_MODULE,
 .open  = mytest_proc_open,
 .read  = seq_read,
 .write  = mytest_proc_write,
 .llseek  = seq_lseek,
 .release = single_release,
};




struct proc_dir_entry *de = NULL;
static int __init my_proc_init( void )
 {
	printk( "<1>\nInstalling \'%s\' module\n", modname );
	//create_proc_info_entry( modname, 0, NULL, my_get_info );
	de = proc_create( modname, 0644, NULL, &mytest_proc_fops );
	return	0;  
 }


static void __exit my_proc_exit( void )
 {
	//remove_proc_entry( modname, NULL );
	proc_remove( de );
	printk( "<1>Removing \'%s\' module\n", modname );
 }

 MODULE_LICENSE("GPL");
 module_init(my_proc_init);
 module_exit(my_proc_exit);
