#include "printf.h"

void ft_putchar(int c)
{
    write(1, &c, 1);
}

size_t  ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
        size_t  i;
        size_t  f;

        f = strlen(src);
        if (src[f] != '\0')
        {
                f++;
        }
        if (!dst || !src)
                return (0);
        if (dstsize > 0)
        {
                i = 0;
                while (src[i] != '\0' && i < (dstsize - 1))
                {
                        dst[i] = src[i];
                        i++;
                }
                dst[i] = '\0';
        }
        return (f);
}

void filtrohex(unsigned int numero, int flag)
{
    char *str;

    str = malloc(sizeof(char) * 17);
    if (!str)
        return ;
    if (flag == 0)
        ft_strlcpy(str, "0123456789ABCDEF", 17);
    else if (flag == 1)
        ft_strlcpy(str, "0123456789abcdef", 17);

    if (numero >= 16)
        filtrohex(numero / 16, flag);
    
    ft_putchar(str[numero % 16]);
    free(str);
}

void ft_puthex_may(unsigned int numero)
{
    if (numero == 0)
    {
        ft_putchar('0');
        return;
    }
    filtrohex(numero, 0);
}

void ft_puthex_min(unsigned int numero)
{
    if (numero == 0)
    {
        ft_putchar('0');
        return;
    }
    filtrohex(numero, 1);
}

void ft_puthex_long(unsigned long numero)
{
    if (numero < 0)
        numero *= -1;
    if (numero == 0)
    {
        ft_putchar('0');
        return;
    }
    filtrohex(numero, 1);
}