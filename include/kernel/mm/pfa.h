#ifndef PFA_H
#define PFA_H

static void set_frame(uint32_t frame_addr);

static void clear_frame(uint32_t frame_addr);
static uint32_t test_frame(uint32_t frame_addr);
static uint32_t first_frame();
void alloc_frame(page_t *page, int is_kernel, int is_writeable);
void free_frame(page_t *page);
void init_paging();
void switch_page_directory(page_directory_t *dir);
page_t *get_page(uint32_t addr, int make, page_directory_t *dir);
void page_fault(regs r);

#endif


