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

static int	wordcount(const char *s, char c)
{
	int	i;
	int	ans;

	i = 0;
	ans = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
		{
			ans++;
		}
		i++;
	}
	return (ans);
}

static int	letcount(const char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] != c && s[i] != '\0')
		i++;
	return (i);
}

static void	vdcpy(const char *s, char *word, int *i, char c)
{
	int	j;

	j = 0;
	while (s[*i] != c && s[*i] != '\0')
	{
		word[j++] = s[*i];
		*i = *i + 1;
	}
	word[j] = '\0';
}

static char	**clean(char **dst)
{
	unsigned int	i;

	i = 0;
	while (dst[i])
		free(dst[i++]);
	free(dst);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	int		words;
	char	**out;
	int		i;
	int		wi;

	if (!s)
		return (NULL);
	words = wordcount(s, c);
	wi = 0;
	i = 0;
	out = (char **)malloc(sizeof(char **) * (words + 1));
	if (!out)
		return (NULL);
	while (wi < words)
	{
		while (s[i] == c)
			i++;
		out[wi] = (char *)malloc(sizeof(char) * (letcount(s + i, c) + 1));
		if (!out[wi])
			return (clean(out));
		vdcpy(s, out[wi++], &i, c);
	}
	out[wi] = NULL;
	return (out);
}
