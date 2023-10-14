/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amunoz-b <amunoz-b@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 15:11:39 by amunoz-b          #+#    #+#             */
/*   Updated: 2023/10/14 15:20:49 by amunoz-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	f;

	f = strlen(src);
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

void	filtrohex(unsigned int numero, int flag, int *len)
{
	char	*str;

	str = malloc(sizeof(char) * 17);
	if (!str)
		return ;
	if (flag == 0)
		ft_strlcpy(str, "0123456789ABCDEF", 17);
	else if (flag == 1)
		ft_strlcpy(str, "0123456789abcdef", 17);
	if (numero >= 16)
		filtrohex(numero / 16, flag, len);
	ft_putchar(str[numero % 16], len);
	free(str);
}

void	ft_puthex_may(unsigned int numero, int *len)
{
	if (numero == 0)
	{
		ft_putchar('0', len);
		return ;
	}
	filtrohex(numero, 0, len);
}

void	ft_puthex_min(unsigned int numero, int *len)
{
	if (numero == 0)
	{
		ft_putchar('0', len);
		return ;
	}
	filtrohex(numero, 1, len);
}

void	ft_puthex_p(unsigned long numero, int *len, int x)
{
	char	buffer[17];
	int		i;

	i = 16;
	if (x == 0)
	{
		ft_putchar('0', len);
		ft_putchar('x', len);
		x = 1;
	}
	if (numero == 0)
	{
		ft_putchar('0', len);
		return ;
	}
	buffer[i] = '\0';
	while (numero > 0 && i > 0)
	{
		i--;
		buffer[i] = "0123456789abcdef"[numero % 16];
		numero /= 16;
	}
	ft_putstr(&buffer[i], len);
}
