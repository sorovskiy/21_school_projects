/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 18:22:46 by                   #+#    #+#             */
/*   Updated: 2022/01/30 18:35:20 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef MINISHELL_H
# define MINISHELL_H

#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <limits.h>
#include <errno.h>
#include <string.h>

typedef struct s_list
{
	int				fd0;
	int				fd1;
	char**			com;
	char*			pre_com;
	int				pipe;
	struct s_list	*next;
}	t_list;


char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strdup(const char *s);
int		ft_isalnum(int ch);
int		ft_strlen(char *str);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
int		ft_strncmp(char *s1, char *s2, unsigned int n);
char	*slash(char *s, int *i);
char	*gap(char *s, int *i);
char	*gap2(char *s, int *i, char **env);
void	gaps(char *s, int *i);
char	*dollar(char *s, int *i, char **env);
void	parser(t_list *elem, char **env);
int 	pre_parser(char *s);
int		stack_init(char *s, t_list **stack);
void	ft_lstprint(t_list *lst);
char	*redirects(char *s, int *i, t_list *elem, char **env);
char	**ft_split(char const *s, char c);

void	ft_push(t_list **lst, t_list *new);
t_list	*ft_lstnew(char* content, int *fd, int pipe);
t_list	*ft_pop(t_list **lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void 	error_exit(char *s, char tok);

#endif //MINISHELL_H
