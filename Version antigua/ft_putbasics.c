/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putbasics.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amunoz-b <amunoz-b@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 17:05:44 by amunoz-b          #+#    #+#             */
/*   Updated: 2023/10/03 17:06:15 by amunoz-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr(char *str, int *len, int *error)
{
	size_t	i;

	i = 0;
	if (str == NULL)
	{
		ft_putstr("(null)", len, error);
		return ;
	}
	while (str[i])
		ft_putchar(str[i++], len, error);
}

void	ft_putentero(int n, int *len, int *error)
{
	if (n == INT_MIN)
	{
		//if (write(1, "-2147483648", 11) == -1)
		ft_putstr("-2147483648", len, error);
		return ;
	}
	else
	{
		if (n < 0)
		{
			ft_putchar('-', len, error);
			n = -n;
		}
		if (n >= 10)
		{
			ft_putentero(n / 10, len, error);
			ft_putentero(n % 10, len, error);
		}
		else
			ft_putchar(n % 10 + 48, len, error);
	}
}

void	ft_putentero_un(unsigned int n, int *len, int *error)
{
	if (n >= 10)
	{
		ft_putentero(n / 10, len, error);
		ft_putentero(n % 10, len, error);
	}
	else
		ft_putchar((n % 10) + '0', len, error);
}
