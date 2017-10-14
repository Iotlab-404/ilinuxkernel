#include <linux/module.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

MODULE_INFO(vermagic, VERMAGIC_STRING);

__visible struct module __this_module
__attribute__((section(".gnu.linkonce.this_module"))) = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

static const struct modversion_info ____versions[]
__used
__attribute__((section("__versions"))) = {
	{ 0x3df5362e, __VMLINUX_SYMBOL_STR(module_layout) },
	{ 0x2175a04e, __VMLINUX_SYMBOL_STR(single_release) },
	{ 0x55dee550, __VMLINUX_SYMBOL_STR(seq_read) },
	{ 0xe3b0a403, __VMLINUX_SYMBOL_STR(seq_lseek) },
	{ 0xa958dc38, __VMLINUX_SYMBOL_STR(proc_remove) },
	{ 0x298e95f2, __VMLINUX_SYMBOL_STR(proc_create_data) },
	{ 0x27e1a049, __VMLINUX_SYMBOL_STR(printk) },
	{ 0x56d4ca56, __VMLINUX_SYMBOL_STR(seq_printf) },
	{ 0x6a8c661a, __VMLINUX_SYMBOL_STR(pv_mmu_ops) },
	{ 0x9c1d4d7, __VMLINUX_SYMBOL_STR(pv_cpu_ops) },
	{ 0x9b6340b6, __VMLINUX_SYMBOL_STR(current_task) },
	{ 0xc111a16e, __VMLINUX_SYMBOL_STR(single_open) },
	{ 0xbdfb6dbb, __VMLINUX_SYMBOL_STR(__fentry__) },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=";


MODULE_INFO(srcversion, "084923B3E35E7901D43A632");
