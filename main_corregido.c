/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amunoz-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 18:02:01 by amunoz-b          #+#    #+#             */
/*   Updated: 2023/09/23 18:05:11 by amunoz-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(int c, int *len)
{
	if (write(1, &c, 1) == -1)
		return (-1);
	(*len)++;
	return (*len);
}

void	ft_putstr(char *str, int *len)
{
	size_t	i;

	if (str == NULL)
		return ;
	i = 0;
	while (str[i])
		ft_putchar(str[i++], len);
}

void	ft_putentero(int n, int *len)
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
		ft_putchar(n % 10 + 48, len);
}

void	ft_putentero_un(unsigned int n, int *len)
{
	if (n > 10)
	{
		ft_putentero(n / 10, len);
		ft_putentero(n % 10, len);
	}
	else
		ft_putchar((n % 10) + '0', len);
}

void	comprueba_tipo(char *str, va_list ap, int *len)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			if (str[i + 1] == 'd' || str[i + 1] == 'i')
				ft_putentero(va_arg(ap, int), len);
			else if (str[i + 1] == 's')
				ft_putstr(va_arg(ap, char *), len);
			else if (str[i + 1] == 'p')
			{
				ft_putchar('0', len);
				ft_putchar('x', len);
				ft_puthex_min(va_arg(ap, unsigned long), len);
			}
			else if (str[i + 1] == 'u')
				ft_putentero_un(va_arg(ap, unsigned int), len);
			else if (str[i + 1] == '%')
				ft_putchar('%', len);
			else if (str[i + 1] == 'x')
				ft_puthex_min(va_arg(ap, unsigned int), len);
			else if (str[i + 1] == 'X')
				ft_puthex_may(va_arg(ap, unsigned int), len);
			else if (str[i + 1] == 'c')
				ft_putchar(va_arg(ap, int), len);
			i++;
		}
		else
			ft_putchar(str[i], len);
		i++;
	}
}

int	ft_printf(char const *str, ...)
{
	va_list	ap;
	int		len;

	len = 0;
	va_start(ap, str);
	comprueba_tipo((char *)str, ap, &len);
	va_end(ap);
	return (len);
}