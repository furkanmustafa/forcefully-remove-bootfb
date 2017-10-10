#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>

#include <linux/resource_ext.h>

static resource_size_t bootfb_start = 0;
static resource_size_t bootfb_end = 0;

static int __init remover_module_init(void)
{
    printk(KERN_INFO "forcefully-remove-bootfb loaded\n");

    if (sizeof(resource_size_t) != 8) {
        // lol
        printk(KERN_ERR "Herp derp what is a programming?\n");
    } else {
        printk(KERN_INFO "forcefully-remove-bootfb 0x%llx-0x%llx\n",
            bootfb_start, bootfb_end);
        if (bootfb_start == 0 && bootfb_end == 0) {
            printk(KERN_ERR "forcefully-remove-bootfb needs addresses!\n");
        } else {
            // Do the actual removal here
            __release_region(&iomem_resource,
                bootfb_start, bootfb_end - bootfb_start + 1);
        }
    }
    return 0;
}

static void __exit remover_module_exit(void)
{
    printk(KERN_INFO "forcefully-remove-bootfb unloaded\n");
}

module_init(remover_module_init);
module_exit(remover_module_exit);

module_param(bootfb_start, ullong, 0000);
module_param(bootfb_end, ullong, 0000);

MODULE_LICENSE("Dual BSD/GPL");
MODULE_AUTHOR("Robert Ou <address@hidden>");
MODULE_DESCRIPTION("Forcefully removes BOOTFB I/O resource");
