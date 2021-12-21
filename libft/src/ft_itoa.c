/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlexie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 10:50:20 by jlexie            #+#    #+#             */
/*   Updated: 2021/07/23 10:50:39 by jlexie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	size(int n)
{
	int	size;

	size = 0;
	if (n == 0)
		return (1);
	if (n == -2147483648)
		return (12);
	if (n < 0)
	{
		size++;
		n = n * -1;
	}
	while (n > 0)
	{
		n = n / 10;
		size++;
	}
	return (size);
}

static void	max_int(char *a, int *n)
{
	if (*n == -2147483648)
		ft_strlcpy(a, "-2147483648", 12);
}

char	*ft_itoa(int n)
{
	char	*a;
	int		i;

	i = size(n);
	a = malloc(sizeof(char) * (i + 1));
	if (!a)
		return (NULL);
	max_int(a, &n);
	a[i--] = '\0';
	if (n == 0)
	{
		a[0] = '0';
		return (a);
	}
	if (n < 0)
	{
		n = n * (-1);
		a[0] = '-';
	}
	while (n > 0)
	{
		a[i--] = (n % 10) + '0';
		n = n / 10;
	}
	return (a);
}
