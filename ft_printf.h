/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amunoz-b <amunoz-b@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 15:07:34 by amunoz-b          #+#    #+#             */
/*   Updated: 2023/10/14 15:10:33 by amunoz-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

int		ft_putchar(int c, int *len);
void	ft_putstr(char *str, int *len);
int		ft_printf(char const *str, ...);
void	comprueba_tipo(char *str, va_list ap, int *len);
void	comprueba_letra(char *str, va_list ap, int *len, int i);
void	ft_puthex_long(unsigned long numero, int *len);
void	ft_puthex_min(unsigned int numero, int *len);
void	ft_puthex_may(unsigned int numero, int *len);
void	ft_puthex_p(unsigned long numero, int *len, int x);
void	filtrohex(unsigned int numero, int flag, int *len);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
void	ft_putentero(int n, int *len);
void	ft_putentero_un(unsigned int n, int *len);
