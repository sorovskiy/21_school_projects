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

void gaps_redir(char *s, int *i)
{
	if (s[*i] == '\'')
	{
		while (s[++*i] != '\'' && s[*i] != '\0')
			;
	}
	if (s[*i] == '\"')
	{
		while (s[++*i] != '\"' && s[*i] != '\0')
			if (s[*i] == '\\' && s[*i + 1] == '\"')
				(*i)++;
	}
}

char *stack_add_elem(char *s, int *i, t_list **stack, int *fd)
{
	char	*tmp;
	char	*to_process;
	int		pipe;

	to_process = ft_substr(s, 0, *i);
	//pre_parsing
	{

	}
	pipe = 0;
	if (s[*i] == '|')
		pipe = 1;
	ft_lstadd_back(stack, ft_lstnew(ft_substr(s, 0, *i), fd, pipe));
	while ((s[*i + 1] == ' ' || s[*i + 1] == '\t'))
		(*i)++;
	tmp = ft_strdup(s + *i + 1);
	free(s);
	s = tmp;
	printf("res: %s\n", s);
	*i = 0;
	fd[0] = 0;
	fd[1] = 1;
	return s;
}

char	*redir_process(char *s, int *fd, int *i)
{
//	int j;
//	char *fname;
//
//	++(*i);
//	while(s[*i] && (s[*i] == ' ' || s[*i] == '\t'))
//		(*i)++;
//	j = *i;
//	while (ft_isalnum(s[*i]))
//		(*i)++;
//
//	// проверить на то, есть ли имя файла перед завершением команды
//	if (j == *i - 1)
//		return s;
//	fname = ft_substr(s, j + 1, *i - j - 1);
//	len = ft_strlen(key);
//	k = -1;
}

int stack_init(char *s, t_list **stack)
{
	int i;
	int fd[2];

	i = -1;
	fd[0] = 0;
	fd[1] = 1;
	printf("fd[0]: %d, fd[1]: %d\n", fd[0], fd[1]);
	while(s[++i])
	{
//		if (s[i] == '>' || s[i] == '<')
//			s = redir_process(s, fd, &i);
		if (s[i] == '|' || s[i] == ';')
			s = stack_add_elem(s, &i, stack, fd);
		if (s[i] == '\'' || s[i] == '\"')
			gaps_redir(s, &i);
		if (s[i] == '\\' &&  s[i + 1] != '\0')
			i += 1;
	}

	ft_lstadd_back(stack, ft_lstnew(s, fd, 0));
	return 1;
}

