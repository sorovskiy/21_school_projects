/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 10:16:11 by                   #+#    #+#             */
/*   Updated: 2021/12/13 09:39:52 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	ft_swap(t_list **lst)
{
	t_list	*tmp1;
	t_list	*tmp2;

	if (!(*lst) || (*lst)->next == NULL)
		return (1);
	tmp1 = ft_pop(lst);
	tmp2 = ft_pop(lst);
	ft_push(lst, tmp1);
	ft_push(lst, tmp2);
	return (0);
}

int	ft_rotate(t_list **lst)
{
	t_list	*tmp1;

	if (!(*lst) || (*lst)->next == NULL)
		return (1);
	tmp1 = ft_pop(lst);
	ft_lstadd_back(lst, tmp1);
	return (0);
}

int	ft_reverse_rotate(t_list **lst)
{
	t_list	*last;
	t_list	*second;

	if (!(*lst) || (*lst)->next == NULL)
		return (1);
	second = *lst;
	while ((*lst)->next->next)
		(*lst) = (*lst)->next;
	last = (*lst);
	(*lst) = (*lst)->next;
	(*lst)->next = second;
	last->next = NULL;
	return (0);
}

t_list	*ft_pop(t_list **lst)
{
	t_list	*el;

	if (!lst || !(*lst))
		return (NULL);
	el = *lst;
	*lst = el->next;
	el->next = NULL;
	return (el);
}

void	ft_push(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}
