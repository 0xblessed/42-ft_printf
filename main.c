/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amunoz-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 18:02:01 by amunoz-b          #+#    #+#             */
/*   Updated: 2023/10/14 15:22:42 by amunoz-b         ###   ########.fr       */
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

void	comprueba_letra(char *str, va_list ap, int *len, int i)
{
	if (str[i + 1] == 'd' || str[i + 1] == 'i')
		ft_putentero(va_arg(ap, int), len);
	else if (str[i + 1] == 's')
		ft_putstr(va_arg(ap, char *), len);
	else if (str[i + 1] == 'p')
		ft_puthex_p(va_arg(ap, unsigned long), len, 0);
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
}

void	comprueba_tipo(char *str, va_list ap, int *len)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			comprueba_letra(str, ap, len, i);
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
