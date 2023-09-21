#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void ft_putchar(int c)
{
    write(1, &c, 1);
}

size_t  ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
        size_t  i;
        size_t  f;

        f = ft_strlen(src);
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
    int x = 0;
    if (x == 0)
    {
        ft_putchar('j');
        ft_putchar('0');
        ft_putchar('x');
        x = 1;
    }
    if (numero < 0)
        numero *= -1;
    if (numero == 0)
    {
        ft_putchar('0');
        return;
    }
    filtrohex(numero, 1);
}

void comprueba_tipo(char *str, va_list ap)
{
    int i = 0;
    while (str[i])
    {
        if (str[i] == '%')
        {
            if (str[i + 1] == 'p') //unsigned long
                ft_puthex_min(va_arg(ap, unsigned long));
            else if (str[i + 1] == 'x')
                ft_puthex_min(va_arg(ap, unsigned int));
            else if (str[i + 1] == 'X')
                ft_puthex_may(va_arg(ap, unsigned int));
            i++;
        }
        else
            ft_putchar(str[i]);
        i++;
    }
}

int ft_printf(char const *str, ...)
{
    va_list ap;
    int i = 0;

    va_start(ap, str);
    comprueba_tipo((char *)str, ap);
    va_end(ap);
    return 0;
}

int main()
{
    printf("Original : Mayus %X Minusculas %x  la p %p\n", 22352, 222, (void *)445);
    ft_printf("Mía      : Mayus %X Minusculas %x  la p %p\n", 22352, 222, (void *)445);

    printf("Original : Mayus %X Minusculas %x  la p %p\n", 255, 15, (void *)1234);
    ft_printf("Mía      : Mayus %X Minusculas %x  la p %p\n", 255, 15, (void *)1234);

    printf("Original : Mayus %X Minusculas %x  la p %p\n", 0, 0, (void *)0);
    ft_printf("Mía      : Mayus %X Minusculas %x  la p %p\n", 0, 0, (void *)0);

    printf("Original : Mayus %X Minusculas %x  la p %p\n", 4563, 0, (void *)0);
    ft_printf("Mía      : Mayus %X Minusculas %x  la p %p\n", 4563, 0, (void *)0);

    printf("Original : Mayus %X Minusculas %x  la p %p\n", 33, 0, (void *)0);
    ft_printf("Mía      : Mayus %X Minusculas %x  la p %p\n", 33, 0, (void *)0);

    printf("Original : Mayus %X Minusculas %x  la p %p\n", 6, 0, (void *)0);
    ft_printf("Mía      : Mayus %X Minusculas %x  la p %p\n", 6, 0, (void *)0);

    return (0);
}
