/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_list_funcs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 13:02:56 by                   #+#    #+#             */
/*   Updated: 2021/12/07 13:02:56 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

int	is_space(char c)
{
	if (c == ' ' || c == '\t')
		return 1;
	return 0;
}

void	skip_space(char *s, int *i)
{
	while (is_space(s[++(*i)]))
		;
}

char	*redirects(char *s, int *i, int *fd, char **env)
{
	int j;
	int k;
	int start;

	int len;
	char *file_name;
	char *key, *value, *tmp1, *tmp3;
	char *res1, *res2;

	start = *i - 1;
	skip_space(s, i);
	printf("s: %s\n\n", &s[*i]);

	j = *i;
	while(s[++(*i)] && !is_space(s[*i]))
	{
		if (s[*i] == '\'')
			s = gap(s, i);
		if (s[*i] == '\"')
			s = gap2(s, i, env);
		if (s[*i] == '\\')
			s = slash(s, i);
		if (s[*i] == '$')
			s = dollar(s, i, env);
	}
	file_name = ft_substr(s, j, *i - j);
	printf("file_name: %s\n\n", file_name);


	printf("s: %s\n\n", &s[*i]);

	tmp1 = ft_substr(s, 0, start + 1);
	tmp3 = ft_strdup(s + *i);

//	printf("tmp1: %s\n", tmp1);
//	printf("tmp2: %s\n", value);
	printf("tmp3: %s\n", tmp3);


	res1 = ft_strjoin(tmp1, tmp3);
	printf("res1: %s\n\n", res1);


//	*i = j - 1;
//	if (res1)
//	{
//		res2 = ft_strjoin(res1, tmp3);
//		*i = *i + ft_strlen(value);
//	}
//
//
//	free(key);
//	free(value);
//	free(tmp1);
//	free(tmp3);
//	free(res1);
//
////	printf("i: %d, j: %d\n", *i, j);
////	printf("res: %s\n", res2);
//
//	free(s);
////	*i = *i - 1;
	return res2;
}