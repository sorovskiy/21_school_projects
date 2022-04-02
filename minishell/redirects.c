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
	if (s[*i] == '>')
		++(*i);
	while (is_space(s[++(*i)]))
		;
}

int	create_file(char *file_name, const char *s, int *fd)
{
	if (*s == '<')
		fd[0] = open(file_name, O_RDONLY);
	else if (*(s + 1) == '>')
		fd[1] = open(file_name, O_WRONLY | O_CREAT | O_APPEND, 0644);
	else if (*s == '>')
		fd[1] = open(file_name, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	else
		printf("shit happened in redirect computing\n");
	if (errno != 0)
		printf("minishell: %s\n", strerror(errno));
	return errno;
}

char	*redirects(char *s, int *i, int *fd, char **env)
{
	int j;
	int start;

	char *file_name;
	char *tmp1, *tmp3;
	char *res;

	start = *i - 1;
	skip_space(s, i);
	printf("s: %s\n", &s[*i]);
	printf("ch: %c\n", s[start + 1]);

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

	create_file(file_name, &s[start + 1], fd);


	tmp1 = ft_substr(s, 0, start + 1);
	tmp3 = ft_strdup(s + *i);

	printf("tmp1: %s\n", tmp1);
	printf("tmp3: %s\n", tmp3);


	res = ft_strjoin(tmp1, tmp3);
	printf("res1: %s\n\n", res);

	free(s);
	free(tmp1);
	free(tmp3);
	free(file_name);

	return res;
}