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

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char			*dests;
	const char		*srcs;
	char			*ldests;
	const char		*lsrcs;

	srcs = src;
	dests = dest;
	if (dest == NULL && src == NULL)
		return (NULL);
	if (dests < srcs)
		while (n--)
			*dests++ = *srcs++;
	else
	{
		ldests = dests + (n - 1);
		lsrcs = srcs + (n - 1);
		while (n--)
			*ldests-- = *lsrcs--;
	}
	return (dest);
}
