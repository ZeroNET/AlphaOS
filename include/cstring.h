#ifndef CSTRING_H
#define CSTRING_H

#include "stddef.h"

void *memcpy(void *dst, const void *src, size_t num);

void *memmove(void *dst, const void *src, size_t num);

char *strcpy(char *dst, const char *src);

char *strncpy(char *dst, const char *src, size_t num);

char *strcat(char *dst, const char *src);

char *strncar(char *dst, const char *src, size_t num);

int memcmp(const void *ptr, const void *ptr_, size_t num);

int strcmp(const char *str, const char *str_);

int strcoll(const char *str, const char *str_);

int strncmp(const char *str, const char *str_, size_t num);

size_t strxfrm(char *dst, const char *src, size_t num);

const void *memchr(const void *ptr, int value, size_t num);

char *strchr(const char *str, int character);

size_t strcspan(const char *str, const char *str_);

char *strpbrk(const char *str, const char *str_);

char *strrchr(const char *str, int character);

size_t strspan(const char *str, const char *str_);

char *strstr(const char *str, const char *str_);

char *strtok(char *str, const char *delimiters);

void *memset(void *ptr, int value, size_t num);

char *strerror(int errnum);

size_t strlen(const char *str);

#endif //CSTRING_H