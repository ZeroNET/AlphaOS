/* AlphaOS v0.1
 * Copyright (c) 2012, Robert Schofield and Matthew Carey
 * All rights reserved.
 */

#include <core.h>
#include <text.h>
#include <gdt.h>
#include <idt.h>
#include <isrs.h>
#include <irq.h>
#include <kernel/paging.h>
#include <types.h>
#include <kernel/kmalloc.h>
#include <pit.h>
#include <fs.h>
#include <multiboot.h>

#define DIE(msg) die(msg, __FILE__, __LINE__)
void show_intro(void);
extern uint32_t placement_address;

void main(struct multiboot *mboot_header, uint32_t initial_stack) 
{ 
  clear();
  gdt_install();
  idt_install();
  isrs_install();
  irq_install();
  timer_install();
  uint32_t initrd_location = *(uint32_t*)mboot_header->mods_addr;
  uint32_t initrd_end = *(u32int*)(mboot_header->mods_addr+4);
  // Don't trample our module with placement accesses, please!
  placement_address = initrd_end;
  init_paging();
  fs_root = initialise_initrd((uint32_t*)initrd_location);
  __asm__ __volatile__ ("sti");
  timer_wait(15);

  clear();

  kprintc("AlphaOS Kernel - Version 0.1                                                    ", BLUE, WHITE);
  kputs("Copyright (c) 2012, Robert Schofield and Matthew Carey");
  kputs("All rights reserved."); 
  print_to_point("Status bar: Will include information about HDD usage, RAM usage, etc.           ", 1, 25, BLUE, WHITE);
  int i = 0;
  struct dirent *node = 0;
  while ( (node = readdir_fs(fs_root, i)) != 0)
  {
    printf("Found file ");
    printf(node->name);
    fs_node_t *fsnode = finddir_fs(fs_root, node->name);

    if ((fsnode->flags&0x7) == FS_DIRECTORY)
      printf("\n\t(directory)\n");
    else
    {
      printf("\n\t\tcontents:\t");
      char buf[256];
      u32int sz = read_fs(fsnode, 0, 256, buf);
      printf("'%s'\n",buf);
    }
    i++;
  }
  /*
  timer_wait(40);
  kprintf("\n\n*** Now switching to VGA mode...\n");
  timer_wait(10);
  vga_initialize(320, 200, 256); */
  
  for(;;);
}

