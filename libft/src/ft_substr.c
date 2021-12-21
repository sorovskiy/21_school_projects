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

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	int		i;
	size_t	minlen;

	i = 0;
	if (!s)
		return (NULL);
	minlen = len;
	if (ft_strlen(s) - start < len && ft_strlen(s) - start > 0)
		minlen = ft_strlen(s) - start;
	if (ft_strlen(s) - (int)len <= 0)
		minlen = 0;
	str = malloc(sizeof(char) * (minlen + 1));
	if (!str)
		return (NULL);
	while ((start-- > 0) && *s)
		s++;
	while (len-- && *s)
	{
		str[i] = *s;
		s++;
		i++;
	}
	str[i] = '\0';
	return (str);
}
