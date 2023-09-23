#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void ft_putchar(int c, int *len);
int ft_printf(char const *str, ...);
void comprueba_tipo(char *str, va_list ap, int *len);
void ft_puthex_long(unsigned long numero, int *len);
void ft_puthex_min(unsigned int numero, int *len);
void ft_puthex_may(unsigned int numero, int *len);
void filtrohex(unsigned int numero, int flag, int *len);
size_t  ft_strlcpy(char *dst, const char *src, size_t dstsize);
