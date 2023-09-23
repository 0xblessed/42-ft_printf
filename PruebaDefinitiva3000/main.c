#include "ft_printf.h"

void ft_putchar(int c, int *len)
{
    write(1, &c, 1);
    (*len)++;
}

void    ft_putstr(char *str, int *len)
{
        size_t  i;
        if (str == NULL)
        return ;
        i = 0;
        while (str[i])
        ft_putchar(str[i++], len);
}

void ft_putentero(int n,  int *len)
{
    if (n < 0)
    {
        ft_putchar('-', len);
        n = -n;
    }
    if (n > 10)
    {

        ft_putentero(n / 10, len);
        ft_putentero(n % 10, len);
    }
    else
    {
        ft_putchar(n % 10 + 48, len);
    }
}
void ft_putentero_un(unsigned int n,  int *len)
{
    if (n > 10)
    {

        ft_putentero(n / 10, len);
        ft_putentero(n % 10, len);
    }
    else
    {
        ft_putchar(n % 10 + 48, len);
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
                ft_putentero(va_arg(ap, int), len);
            else if (str[i + 1] == 's')
                ft_putstr(va_arg(ap, char *), len);
            else if(str[i + 1] == 'p')
            {
                ft_putchar('0', len);
                ft_putchar('x', len);
                ft_puthex_min(va_arg(ap, unsigned long), len);
            }
            else if(str[i + 1] == 'u')
                ft_putentero_un(va_arg(ap,unsigned int), len);
            else if(str[i + 1] == '%')
                ft_putchar('%', len);
            else if(str[i + 1] == 'x')
                ft_puthex_min(va_arg(ap, unsigned int), len);
            else if(str[i + 1] == 'X')
                ft_puthex_may(va_arg(ap, unsigned int), len);
            else if(str[i + 1] == 'c')
                ft_putchar(va_arg(ap, int), len);
            i++;
        }
        else
            ft_putchar(str[i], len);
        i++;
    }
}

int ft_printf(char const *str, ...)
{
    va_list    ap;

    int len = 0;
    va_start(ap, str);
    comprueba_tipo((char *)str, ap, &len);
    va_end(ap);
    return len;
}


/*int main()
{
    //ft_printf("Mi nombre %s tiene un total de %d %i letras, el nano es el numero 33 pero en puntero void es %p, en minusculas es %x y al contrario es %X", "Pepe", 4,4, (void *)33,33,33);
    //ft_printf("\nSi por ejemplo hago %% imprime eso no?, y mi letra favorita es %c por es la numero %u ", 'z', (unsigned int)27);
    int l = ft_printf("Cara huevo %d\n", 3000);
    printf("%d", l);
    printf("\n");
    l = printf("Cara huevo %d\n", 3000);
    printf("%d", l);
    
    //printf("Mi nombre %s tiene un total de %d %i letras, el nano es el numero 33 pero en puntero void es %p, en minusculas es %x y al contrario es %X", "Pepe", 433,4, (void *)33,33,33);
    //printf("\nSi por ejemplo hago %% imprime eso no?, y mi letra favorita es %c por es la numero %u ", 'z', (unsigned int)27);
}
*/
int main() {
    int len;

    // Prueba de cadena de formato simple
    len = ft_printf("Hello, World!\n");
    printf("ft_printf: %d\n", len);
    len = printf("Hello, World!\n");
    printf("printf: %d\n", len);
    
    // Prueba de cadena de formato con enteros
    len = ft_printf("Entero: %d, %i\n", 42, -42);
    printf("ft_printf: %d\n", len);
    len = printf("Entero: %d, %i\n", 42, -42);
    printf("printf: %d\n", len);
    
    // Prueba de cadena de formato con punteros
    len = ft_printf("Puntero: %p\n", (void *)12345);
    printf("ft_printf: %d\n", len);
    len = printf("Puntero: %p\n", (void *)12345);
    printf("printf: %d\n", len);
    
    // Prueba de cadena de formato con caracteres
    len = ft_printf("Caracter: %c\n", 'A');
    printf("ft_printf: %d\n", len);
    len = printf("Caracter: %c\n", 'A');
    printf("printf: %d\n", len);

    // Prueba de cadena de formato con cadenas
    len = ft_printf("Cadena: %s\n", "Test String");
    printf("ft_printf: %d\n", len);
    len = printf("Cadena: %s\n", "Test String");
    printf("printf: %d\n", len);

    // Prueba de cadena de formato con valores hexadecimales
    len = ft_printf("Hexadecimal: %x, %X\n", 255, 255);
    printf("ft_printf: %d\n", len);
    len = printf("Hexadecimal: %x, %X\n", 255, 255);
    printf("printf: %d\n", len);

    return 0;
}
