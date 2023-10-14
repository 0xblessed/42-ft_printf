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

int	ft_putchar(int c, int *len, int *error)
{
	if (write(1, &c, 1) == -1)
		*error = -1;
	(*len)++;
	return (*len);
}

void	comprueba_tipo(char *str, va_list ap, int *len, int *error)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			if (str[i + 1] == 'd' || str[i + 1] == 'i')
				ft_putentero(va_arg(ap, int), len, error);
			else if (str[i + 1] == 's')
				ft_putstr(va_arg(ap, char *), len, error);
			else if (str[i + 1] == 'p')
				ft_puthex_p(va_arg(ap, unsigned long), len, 0, error);
			else if (str[i + 1] == 'u')
				ft_putentero_un(va_arg(ap, unsigned int), len, error);
			else if (str[i + 1] == '%')
				ft_putchar('%', len, error);
			else if (str[i + 1] == 'x')
				ft_puthex_min(va_arg(ap, unsigned int), len, error);
			else if (str[i + 1] == 'X')
				ft_puthex_may(va_arg(ap, unsigned int), len, error);
			else if (str[i + 1] == 'c')
				ft_putchar(va_arg(ap, int), len, error);
			i++;
			if (*error < 0)
				break;
		}
		else
			ft_putchar(str[i], len, error);
		if (*error < 0)
		{
			break;
		}
		i++;
	}
}

int	ft_printf(char const *str, ...)
{
	va_list	ap;
	int		len;
	int		error;

	len = 0;
	error = 0;
	va_start(ap, str);
	comprueba_tipo((char *)str, ap, &len, &error);
	va_end(ap);
	if (error < 0)
	{
		return (-1);
	}
	return (len);
}
