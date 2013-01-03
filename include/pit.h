/* AlphaOS v0.1
 * Copyright (c) 2012, Robert Schofield and Matthew Carey
 * All rights reserved.
 */

#ifndef PIT_H
#define PIT_H

void timer_phase(int hz);
void timer_handler(struct regs *r);
void timer_install(void);
void timer_wait(int ticks);
void timer_test(void);

int do_nothing(void);

#endif
