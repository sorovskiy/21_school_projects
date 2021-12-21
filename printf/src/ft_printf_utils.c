/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 13:47:25 by                   #+#    #+#             */
/*   Updated: 2021/11/01 12:47:58 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	putstr(char *s)
{
	int	n;

	n = 0;
	if (!s)
	{
		n += write(1, "(null)", 6);
		return (n);
	}
	while (*s)
	{
		write(1, s++, 1);
		n++;
	}
	return (n);
}

int	ft_putnbr(int n)
{
	char	a;
	int		i;

	i = 0;
	if (n < 0)
	{
		i += write(1, "-", 1);
		a = '0' - (n % 10);
		if (n / -10 != 0)
			 i += ft_putnbr(n / -10);
		i += write(1, &a, 1);
		return(i);
	}
	a = (n % 10) + '0';
	if (n >= 10)
		i += ft_putnbr(n / 10);
	i += write(1, &a, 1);
	return (i);
}

int	ft_putnbr_p(long long int n)
{
	int	i;

	i = 0;
	i += write(1, "0x", 2);
	i += ft_putnbr_base(n, "0123456789abcdef", 16);
	return (i);
}

int	ft_putnbr_base(unsigned long long int n, char *str, int base)
{
	char	a;
	int		i;

	i = 0;
	if (n == 0)
	{
		write(1, str, 1);
		return (++i);
	}
	if (n > 0)
	{
		a = str[n % base];
		if (n / base != 0)
			i += ft_putnbr_base(n / base, str, base);
		i += write(1, &a, 1);
	}
	return (i);
}
