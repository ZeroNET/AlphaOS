// multiboot.h -- Declares the multiboot info structure.
//                Made for JamesM's tutorials <www.jamesmolloy.co.uk>

#ifndef MULTIBOOT_H
#define MULTIBOOT_H

#include "types.h"

#define MULTIBOOT_FLAG_MEM     0x001
#define MULTIBOOT_FLAG_DEVICE  0x002
#define MULTIBOOT_FLAG_CMDLINE 0x004
#define MULTIBOOT_FLAG_MODS    0x008
#define MULTIBOOT_FLAG_AOUT    0x010
#define MULTIBOOT_FLAG_ELF     0x020
#define MULTIBOOT_FLAG_MMAP    0x040
#define MULTIBOOT_FLAG_CONFIG  0x080
#define MULTIBOOT_FLAG_LOADER  0x100
#define MULTIBOOT_FLAG_APM     0x200
#define MULTIBOOT_FLAG_VBE     0x400

struct multiboot
{
    int32_t flags;
    int32_t mem_lower;
    int32_t mem_upper;
    int32_t boot_device;
    int32_t cmdline;
    int32_t mods_count;
    int32_t mods_addr;
    int32_t num;
    int32_t size;
    int32_t addr;
    int32_t shndx;
    int32_t mmap_length;
    int32_t mmap_addr;
    int32_t drives_length;
    int32_t drives_addr;
    int32_t config_table;
    int32_t boot_loader_name;
    int32_t apm_table;
    int32_t vbe_control_info;
    int32_t vbe_mode_info;
    int32_t vbe_mode;
    int32_t vbe_interface_seg;
    int32_t vbe_interface_off;
    int32_t vbe_interface_len;
}  __attribute__((packed));

typedef struct multiboot_header multiboot_header_t;

#endif
