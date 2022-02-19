/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 18:19:13 by                   #+#    #+#             */
/*   Updated: 2022/01/30 18:24:40 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (*str != '\0')
	{
		str++;
		i++;
	}
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		i;

	i = 0;
	if (!s1 || !s2)
		return (NULL);
	str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (NULL);
	while (*s1)
		str[i++] = *s1++;
	while (*s2)
		str[i++] = *s2++;
	str[i] = '\0';
	return (str);
}

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

char	*ft_strdup(const char *s)
{
	int		i;
	char	*a;

	i = 0;
	while (s[i] != '\0')
		i++;
	a = malloc(sizeof(*s) * i + 1);
	if (a == NULL)
		return (a);
	i = 0;
	while (s[i] != '\0')
	{
		a[i] = s[i];
		i++;
	}
	a[i] = '\0';
	return (a);
}


