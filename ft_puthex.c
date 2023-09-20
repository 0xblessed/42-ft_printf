/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amunoz-b <amunoz-b@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 17:57:31 by amunoz-b          #+#    #+#             */
/*   Updated: 2023/09/20 17:58:08 by amunoz-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void filtrohex(int contador, int numero, int flag)
{
    char *str;

    str = malloc(sizeof(char) * 17);
    if (!str)
        return ;
    if (flag == 0)
        str = "0123456789ABCDEF";
    else if (flag == 1)
        str = "0123456789abcdef";
    if (contador > 0 || numero > 0)
    {
        filtrohex(contador / 16, contador % 16, flag);
    }
    ft_putchar(str[numero]);
}

void    ft_puthex_may(unsigned int numero, int *len)
{
   if (numero < 0)
    {
        numero *= -1;
    }
    if (numero == 0)
    {
        ft_putchar('0');
        return ;
    }
    filtrohex(numero / 16, numero % 16, 0);
    ft_putchar('\n');
}

void    ft_puthex_min(unsigned int numero, int *len)
{
   if (numero < 0)
        numero *= -1;
    if (numero == 0)
    {
        ft_putchar('0');
        return ;
    }
    filtrohex(numero / 16, numero % 16, 1);
    ft_putchar('\n');
}

void    ft_puthex_long(unsigned long numero, int *len)
{
    int x;
    if (x == 0)
    {
        ft_putchar('0');
        ft_putchar('x');
        x = 1;
    }
   if (numero < 0)
        numero *= -1;
    if (numero == 0)
    {
        ft_putchar('0');
        return ;
    }
    filtrohex(numero / 16, numero % 16, 1);
    ft_putchar('\n');
}