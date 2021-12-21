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

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	unsigned long	i;

	i = 0;
	while (i < size - 1 && src[i] != '\0' && size > 0)
	{
		dst[i] = src[i];
		i++;
	}
	if (i != 0 || size == 1 || src[0] == '\0' )
		dst[i] = '\0';
	while (src[i] != '\0')
		i++;
	return ((int)i);
}
