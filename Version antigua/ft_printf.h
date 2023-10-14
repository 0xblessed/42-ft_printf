#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

int ft_putchar(int c, int *len, int *error);
void	ft_putstr(char *str, int *len, int *error);
int ft_printf(char const *str, ...);
void    comprueba_tipo(char *str, va_list ap, int *len, int *error);
void    ft_puthex_long(unsigned long numero, int *len, int *error);
void    ft_puthex_min(unsigned int numero, int *len, int *error);
void    ft_puthex_may(unsigned int numero, int *len, int *error);
void    ft_puthex_p(unsigned long numero,  int *len, int x, int *error);
void    filtrohex(unsigned int numero, int flag, int *len, int *error);
size_t  ft_strlcpy(char *dst, const char *src, size_t dstsize);
void	ft_putentero(int n, int *len, int *error);
void	ft_putentero_un(unsigned int n, int *len, int *error);
