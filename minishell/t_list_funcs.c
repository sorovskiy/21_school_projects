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

t_list	*ft_lstnew(char *content, int pipe)
{
	t_list	*elem;

	elem = malloc(sizeof(t_list));
	if (!elem)
		return (NULL);
	elem->pre_com = content;
	elem->fd0 = 0;
	elem->fd1 = 1;
	elem->pipe = pipe;
	elem->next = NULL;
	return (elem);
}

void	ft_lstprint(t_list *lst)
{
	while (lst)
	{
		printf("!%s! - %20d - %d - %d\n",
			lst->pre_com, lst->fd0, lst->fd1, lst->pipe);
		lst = lst->next;
	}
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*el;

	if (!new || !lst)
		return ;
	if (!(*lst))
	{
		*lst = new;
		return ;
	}
	el = *lst;
	while (el->next)
		el = el->next;
	el->next = new;
}

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}
