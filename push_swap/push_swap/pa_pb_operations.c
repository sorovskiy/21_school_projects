/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa_pb_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 15:50:09 by                   #+#    #+#             */
/*   Updated: 2021/12/07 16:18:18 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	push_a(t_list **lst_a, t_list **lst_b)
{
	if (!(*lst_b))
		return ;
	ft_push(lst_a, ft_pop(lst_b));
	write(1, "pa\n", 3);
}

void	push_b(t_list **lst_a, t_list **lst_b)
{
	if (!(*lst_a))
		return ;
	ft_push(lst_b, ft_pop(lst_a));
	write(1, "pb\n", 3);
}
