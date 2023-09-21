#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int ft_printf(char const *str, ...);
void comprueba_tipo(char *str, va_list ap);
void ft_puthex_long(unsigned long numero);
void ft_puthex_min(unsigned int numero);
void ft_puthex_may(unsigned int numero);
void filtrohex(unsigned int numero, int flag);
size_t  ft_strlcpy(char *dst, const char *src, size_t dstsize);
void ft_putchar(int c);
