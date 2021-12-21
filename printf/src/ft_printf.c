/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 10:07:28 by                   #+#    #+#             */
/*   Updated: 2021/11/01 12:58:41 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	evaluate(const char *s, va_list ap, char *hex, char *hup)
{
	int		n;
	char	c;

	n = 0;
	if (*s == '%')
		n += (int)write(1, "%", 1);
	if (*s == 'c')
	{
		c = va_arg(ap, int);
		n += (int)write(1, &c, 1);
	}
	if (*s == 's')
		n += putstr(va_arg(ap, char *));
	if (*s == 'p')
		n += ft_putnbr_p(va_arg(ap, long long int));
	if (*s == 'd' || *s == 'i')
		n += ft_putnbr(va_arg(ap, int));
	if (*s == 'u')
		n += ft_putnbr_base(va_arg(ap, unsigned int), "0123456789", 10);
	if (*s == 'x')
		n += ft_putnbr_base((unsigned int)va_arg(ap, long long int), hex, 16);
	if (*s == 'X')
		n += ft_putnbr_base((unsigned int)va_arg(ap, long long int), hup, 16);
	return (n);
}

int	ft_printf(const char *s, ...)
{
	int		n;
	va_list	ap;
	char	*hex;
	char	*hex_up;

	hex = "0123456789abcdef";
	hex_up = "0123456789ABCDEF";
	n = 0;
	va_start(ap, s);
	while (*s)
	{
		if (*s == '%')
		{
			s++;
			n += evaluate(s, ap, hex, hex_up);
		}
		else
		{
			n++;
			write(1, s, 1);
		}
		s++;
	}
	va_end(ap);
	return (n);
}
