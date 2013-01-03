/* AlphaOS v0.1
 * Copyright (c) 2012, Robert Schofield and Matthew Carey
 * All rights reserved.
 */

#ifndef TEXT_H
#define TEXT_H

#include "core.h"

#define BLACK         0
#define BLUE          1
#define GREEN         2
#define CYAN          3
#define RED           4
#define MAGENTA       5
#define BROWN         6
#define LIGHT_GREY    7
#define DARK_GREY     8
#define LIGHT_BLUE    9
#define LIGHT_GREEN   10
#define LIGHT_CYAN    11
#define LIGHT_RED     12
#define LIGHT_MAGENTA 13
#define LIGHT_BROWN   14
#define WHITE         15


void put(char c);

void clear();

void kprint(char *c);

void kputs(char *c);

void put_c(char c, u8int backColour, u8int foreColour);

void print(char c);

void kprintc(char *c, u8int bg, u8int fg);

void error(char *c);

void kprintf(char const *fmt, ...);

char *sprintf(char *str, char const *fmt, ...);

#endif