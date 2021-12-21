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

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		len;
	char	*a;
	int		i;

	if (!s || !f)
		return (NULL);
	i = 0;
	len = ft_strlen(s);
	a = malloc(sizeof(char) * (len + 1));
	if (!a)
		return (NULL);
	while (i < len)
	{
		a[i] = (*f)(i, s[i]);
		i++;
	}
	a[i] = '\0';
	return (a);
}
