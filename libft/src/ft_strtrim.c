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

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	int		i;
	int		len;
	int		j;

	i = 0;
	if (!s1 || !set)
		return (NULL);
	while (ft_strchr(set, s1[i]) && s1[i])
		i++;
	len = ft_strlen(s1 + i);
	while (ft_strchr(set, s1[len + i - 1]) && s1[i])
		len--;
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	j = 0;
	while (j < len)
		str[j++] = s1[i++];
	str[j] = '\0';
	return (str);
}
