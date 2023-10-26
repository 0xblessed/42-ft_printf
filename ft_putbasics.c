/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putbasics.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amunoz-b <amunoz-b@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 17:05:44 by amunoz-b          #+#    #+#             */
/*   Updated: 2023/10/14 17:44:44 by amunoz-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(const char *c)
{
	size_t	i;

	i = 0;
	while (c[i] != '\0')
	{
		i++;
	}
	return (i);
}

void	ft_putstr(char *str, int *len)
{
	size_t	i;

	i = 0;
	if (str == NULL)
	{
		ft_putstr("(null)", len);
		return ;
	}
	while (str[i])
		ft_putchar(str[i++], len);
}

void	ft_putentero(int n, int *len)
{
	if (n == INT_MIN)
	{
		ft_putstr("-2147483648", len);
		return ;
	}
	else
	{
		if (n < 0)
		{
			ft_putchar('-', len);
			n = -n;
		}
		if (n >= 10)
		{
			ft_putentero(n / 10, len);
			ft_putentero(n % 10, len);
		}
		else
			ft_putchar(n % 10 + 48, len);
	}
}

void	ft_putentero_un(unsigned int n, int *len)
{
	if (n >= 10)
	{
		ft_putentero(n / 10, len);
		ft_putentero(n % 10, len);
	}
	else
		ft_putchar((n % 10) + '0', len);
}
