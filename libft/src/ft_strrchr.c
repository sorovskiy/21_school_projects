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
char	*ft_strrchr(const char *s, int c)
{
	const char	*start;

	start = s;
	while (*s)
		s++;
	while (*s != (char)c && s != start)
		s--;
	if (s == start && *s != (char)c)
		return ((void *)0);
	return ((char *)s);
}
