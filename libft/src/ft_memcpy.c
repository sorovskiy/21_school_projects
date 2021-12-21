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

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned long	i;
	char			*dests;
	const char		*srcs;

	i = 0;
	srcs = (const char *)src;
	dests = (char *)dest;
	if (dest == NULL && src == NULL)
		return (NULL);
	while (i < n)
	{
		*dests = *srcs;
		i++;
		srcs++;
		dests++;
	}
	return (dest);
}
