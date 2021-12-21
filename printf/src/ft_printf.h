/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 09:56:45 by                   #+#    #+#             */
/*   Updated: 2021/11/01 12:47:52 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int	ft_printf(const char *s, ...);
int	putstr(char *s);
int	ft_putnbr(int n);
int	ft_putnbr_p(long long int n);
int	ft_putnbr_base(unsigned long long int n, char *str, int base);

#endif //FT_PRINTF_H
