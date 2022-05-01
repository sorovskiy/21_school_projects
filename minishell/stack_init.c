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
	char	*new_s;
	int		pipe;

	pipe = 0;
	if (s[*i] == '|')
		pipe = 1;
	ft_lstadd_back(stack, ft_lstnew(ft_substr(s, 0, *i), fd, pipe));
	while ((s[*i + 1] == ' ' || s[*i + 1] == '\t'))
		(*i)++;
	new_s = ft_strdup(s + *i + 1);
	free(s);

	*i = 0;
	fd[0] = 0;
	fd[1] = 1;
	return new_s;
}

int stack_init(char *s, t_list **stack)
{
	int i;
	int fd[2];

	if (pre_parser(s) != 0)
		return 1;
	i = -1;
	fd[0] = 0;
	fd[1] = 1;
	while(s[++i])
	{
		if (s[i] == '|' || s[i] == ';')
			s = stack_add_elem(s, &i, stack, fd);
		if (s[i] == '\'' || s[i] == '\"')
			gaps_redir(s, &i);
		if (s[i] == '\\' &&  s[i + 1] != '\0')
			i += 1;
	}

	ft_lstadd_back(stack, ft_lstnew(s, fd, 0));
	return 0;
}

