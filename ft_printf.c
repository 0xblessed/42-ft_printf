/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amunoz-b <amunoz-b@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 16:33:44 by amunoz-b          #+#    #+#             */
/*   Updated: 2023/09/19 16:33:48 by amunoz-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>

void ft_putchar(int c)
{ 
    write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	size_t	i;
	if (str == NULL)
		return ;
	i = 0;
	while (str[i])
		ft_putchar(str[i++]);
}

void ft_putentero(int n, int *len)
{
    if (n > 10)
    {

		ft_putentero(n / 10, len);
		ft_putentero(n % 10, len`);
	}
	else
	{
		ft_putchar(n % 10 + 48, len);
		if (*len == -1)
			return ;
	}
}

void comprueba_tipo(char *str, va_list ap)
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
            else if(str[i + 1] == 'p')//unsigned long
                ft_puthex_min(va_arg(ap, unsigned long));
            else if(str[i + 1] == 'u')//unsigned int
                ft_imprime("\nEs un unsigned int\n");
            else if(str[i + 1] == '%')
                ft_putchar('%');
            else if(str[i + 1] == 'x')
                ft_puthex_min(va_arg(ap, unsigned int));
            else if(str[i + 1] == 'X')
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
    va_list    ap;
    int i = 0;

    va_start(ap, str);
    comprueba_tipo((char *)str, ap);
    va_end(ap);
    return 0;
}

int main()
{
    int a, b;
    int j = 6;
    char *str = "Hola";
    a = ft_printf("Carlos tiene %d %i %s anos\n", j, j, str);
    b = printf("Carlos tiene %d anos", j);

    printf("\nOriginal:%d\nMi funcion:%d", b, a);

    return (0);
}
