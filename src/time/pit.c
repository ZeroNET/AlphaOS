/* AlphaOS v0.1
 * Copyright (c) 2012, Robert Schofield and Matthew Carey
 * All rights reserved.
 */

#include <core.h>
#include <pit.h>

volatile int timer_ticks = 0;

void timer_phase(int hz)
{
  int divisor = 1193810 / hz;
  outportb(0x43, 0x36);
  outportb(0x40, divisor & 0xFF);
  outportb(0x40, divisor >> 8);
}

void timer_handler(struct regs *r)
{
  timer_ticks++;
}

void timer_install()
{ 
  irq_install_handler(0, timer_handler, "PIT");
}

void timer_wait(int ticks)
{
  unsigned int end = ticks + timer_ticks;
  
  while(end > timer_ticks)
  {
    __asm__ __volatile__("hlt");
  }
}

/* This is a dummy function for the timer. I don't currently feel like
 * finding a legitimate solution. This will eventually be improved
 * as we move through the development process.                         */
int do_nothing(void)
{
  return;
}

