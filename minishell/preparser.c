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

void error_exit(char *s, char tok)
{
	if (tok == 0)
		printf("minishell: %s\n", s);
	else
		printf("minishell: %s \'%c\'\n", s, tok);
	exit(1);
}

void gaps(char *s, int *i)
{
	if (s[*i] == '\'')
	{
		while (s[++*i] != '\'' && s[*i] != '\0')
			;
		if (s[*i] == '\0')
			error_exit("synthax error: not paired quotes", 0);
	}
	if (s[*i] == '\"')
	{
		while (s[++*i] != '\"' && s[*i] != '\0')
			if (s[*i] == '\\' && s[*i + 1] == '\"')
				(*i)++;
		if (s[*i] == '\0')
			error_exit("synthax error: not paired quotes", 0);
//		printf("s: %s, s[i]: %c\n", s, s[*i]);
//		printf("s: %s, s[i]: %s\n", s, s + *i);
	}
}


int pre_parser(char *s)
{
	int i;

	i = -1;
	if (s[i + 1] == ';' || s[i + 1] == '|' )
		error_exit("synthax error near unexpected token", s[i + 1]);
	while(s[++i])
	{
		if (s[i] == '|' && s[i + 1] == ';')
			error_exit("synthax error near unexpected token", s[i]);
		if (s[i] == ';' && (s[i + 1] == '|' || s[i + 1] == ';'))
			error_exit("synthax error near unexpected token", s[i]);
		if (s[i] == '\'' || s[i] == '\"')
			gaps(s, &i);
		if (s[i] == '\\' &&  s[i + 1] != '\0')
			i += 1;
	}
	if (s[i - 1] == '\\')
		error_exit("synthax error near unexpected token", s[i - 1]);
	return 1;
}

