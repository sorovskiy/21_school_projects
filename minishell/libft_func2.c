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

int	is_space(char c)
{
	if (c == ' ' || c == '\t')
		return (1);
	return (0);
}

char	*ft_strjoin_free_source(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		s1_i;
	int		s2_i;

	i = 0;
	s1_i = 0;
	s2_i = 0;
	if (!s1 || !s2)
		return (NULL);
	str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (NULL);
	while (s1[s1_i])
		str[i++] = s1[s1_i++];
	while (s2[s2_i])
		str[i++] = s2[s2_i++];
	str[i] = '\0';
	free(s1);
	free(s2);
	return (str);
}

