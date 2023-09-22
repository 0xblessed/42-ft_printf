#include "ft_printf.h"

void ft_putchar(int c)
{
    write(1, &c, 1);
    (*len)++;
}

void    ft_putstr(char *str)
{
        size_t  i;
        if (str == NULL)
                return ;
        i = 0;
        while (str[i])
                ft_putchar(str[i++]);
}

void ft_putentero(int n)
{
    if (n > 10)
    {

                ft_putentero(n / 10);
                ft_putentero(n % 10);
        }
        else
        {
                ft_putchar(n % 10 + 48);
        }
}
void ft_putentero_un(unsigned int n)
{
    if (n > 10)
    {

                ft_putentero(n / 10);
                ft_putentero(n % 10);
        }
        else
        {
                ft_putchar(n % 10 + 48);
        }
}

void comprueba_tipo(char *str, va_list ap, int *len)
{
    int i = 0;
   while (str[i])
    {
        if (str[i] == '%')
        {
            if (str[i + 1] == 'd' || str[i + 1] == 'i')
                ft_putentero(va_arg(ap, int));
            else if (str[i + 1] == 's')
                ft_putstr(va_arg(ap, char *));
            else if(str[i + 1] == 'p')
            {
                ft_putchar('0');
                ft_putchar('x');
                ft_puthex_min(va_arg(ap, unsigned long));
            }
            else if(str[i + 1] == 'u')
                ft_putentero_un(va_arg(ap,unsigned int));
            else if(str[i + 1] == '%')
                ft_putchar('%');
            else if(str[i + 1] == 'x')
                ft_puthex_min(va_arg(ap, unsigned int));
            else if(str[i + 1] == 'X')
                ft_puthex_may(va_arg(ap, unsigned int));
            else if(str[i + 1] == 'c')
                ft_putchar(va_arg(ap, int));
            i++;
        }
        else
            ft_putchar(str[i]);
        i++;
    }
}

int ft_printf(char const *str, ...)
{
    va_list    ap;
    int *len = 0;

    va_start(ap, str);
    comprueba_tipo((char *)str, ap, len);
    va_end(ap);
    return 0;
}

/*
int main()
{
    ft_printf("Mi nombre %s tiene un total de %d %i letras, el nano es el numero 33 pero en puntero void es %p, en minusculas es %x y al contrario es %X", "Pepe", 4,4, (void *)33,33,33);
    ft_printf("\nSi por ejemplo hago %% imprime eso no?, y mi letra favorita es %c por es la numero %u ", 'z', (unsigned int)27);
    
    printf("\n");
    
    printf("Mi nombre %s tiene un total de %d %i letras, el nano es el numero 33 pero en puntero void es %p, en minusculas es %x y al contrario es %X", "Pepe", 4,4, (void *)33,33,33);
    printf("\nSi por ejemplo hago %% imprime eso no?, y mi letra favorita es %c por es la numero %u ", 'z', (unsigned int)27);
}*/
