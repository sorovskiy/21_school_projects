/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 18:24:06 by                   #+#    #+#             */
/*   Updated: 2022/01/30 20:21:16 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

void parser(char *s, char **env)
{
	int i;

	i = -1;
	while(s[++i])
	{
		if (s[i] == '\'')
		{
			s = gap(s, &i);
			printf("s: %s, s[i]: %c\n", s, s[i]);
		}
		if (s[i] == '\"')
		{
			s = gap2(s, &i, env);
			printf("s: %s, s[i]: %c\n", s, s[i]);
		}
		if (s[i] == '\\')
			s = slash(s, &i);
		if (s[i] == '$')
			s = dollar(s, &i, env);

	}
}

char *dollar(char *s, int *i, char **env)
{
	int j;
	int k;
	int len;
	char *key, *value, *tmp1, *tmp3;
	char *res1, *res2;

	j = *i;
	while (ft_isalnum(s[++(*i)]))
		;
	if (j == *i - 1)
		return s;
	key = ft_substr(s, j + 1, *i - j - 1);
	len = ft_strlen(key);
	k = -1;
	while (env[++k])
		if (!ft_strncmp(env[k], key, len) && env[k][len] == '=')
			break;

	value = NULL;
	if (env[k])
		value = ft_substr(env[k], len + 1, ft_strlen(env[k]) - len);

	tmp1 = ft_substr(s, 0, j);
	tmp3 = ft_strdup(s + *i);

//	printf("tmp1: %s\n", tmp1);
//	printf("tmp2: %s\n", value);
//	printf("tmp3: %s\n", tmp3);


	res1 = ft_strjoin(tmp1, value);

	free(value);
	free(key);

	if (res1)
		res2 = ft_strjoin(res1, tmp3);
	else // если ключа нет
		res2 = ft_strjoin(tmp1, tmp3);
	free(tmp1);
	free(tmp3);
	free(res1);

//	printf("i: %d, j: %d\n", *i, j);
//	printf("res: %s\n", res2);

	free(s);
	*i = *i - 1;
	return res2;
}

char *slash(char *s, int *i)
{
	char *tmp1, *tmp2;
	char *res;

	tmp1 = ft_substr(s, 0, *i);
	tmp2 = ft_strdup(s + *i + 1);
//	printf("tmp1: %s\n", tmp1);
//	printf("tmp2: %s\n", tmp2);

	res = ft_strjoin(tmp1, tmp2);
	free(tmp1);
	free(tmp2);

	printf("res: %s\n", res);

	free(s);

	return res;
}

char *gap(char *s, int *i)
{
	int j;
	char *tmp1, *tmp2, *tmp3;
	char *res1, *res2;

	j = *i;
	while (s[++(*i)] != '\'')
		;
	tmp1 = ft_substr(s, 0, j);
	tmp2 = ft_substr(s, j + 1, *i - j - 1);
	tmp3 = ft_strdup(s + *i + 1);
//	printf("tmp1: %s\n", tmp1);
//	printf("tmp2: %s\n", tmp2);
//	printf("tmp3: %s\n", tmp3);

	res1 = ft_strjoin(tmp1, tmp2);
	free(tmp1);
	free(tmp2);

	res2 = ft_strjoin(res1, tmp3);
	free(tmp3);
	free(res1);
//	printf("i: %d, j: %d\n", *i, j);

//	printf("res: %s\n", res2);

	free(s);
	*i = *i - 1;
	return res2;
}

char *gap2(char *s, int *i, char **env)
{
	int j;
	char *tmp1, *tmp2, *tmp3;
	char *res1, *res2;

	j = *i;
	while (s[++(*i)] != '\"')
	{
		if (s[*i] == '\\' && (s[*i + 1] == '$' || s[*i + 1] == '\\' || s[*i + 1] == '\"'))
			s = slash(s, i);
		if (s[*i] == '$')
			s = dollar(s, i, env);
	}
	tmp1 = ft_substr(s, 0, j);
	tmp2 = ft_substr(s, j + 1, *i - j - 1);
	tmp3 = ft_strdup(s + *i + 1);
	//	printf("tmp1: %s\n", tmp1);
	//	printf("tmp2: %s\n", tmp2);
	//	printf("tmp3: %s\n", tmp3);

	res1 = ft_strjoin(tmp1, tmp2);
	free(tmp1);
	free(tmp2);

	res2 = ft_strjoin(res1, tmp3);
	free(tmp3);
	free(res1);
	//	printf("i: %d, j: %d\n", *i, j);

	//	printf("res: %s\n", res2);

	free(s);
	*i = *i - 1;
	return res2;
}