/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra_rrb_rrr_operations.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 14:23:09 by                   #+#    #+#             */
/*   Updated: 2021/12/07 14:34:54 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	reverse_rotate_a(t_list **lst)
{
	if (ft_reverse_rotate(lst))
		return ;
	write(1, "rra\n", 4);
}

void	reverse_rotate_b(t_list **lst)
{
	if (ft_reverse_rotate(lst))
		return ;
	write(1, "rrb\n", 4);
}

void	reverse_rotate_rotate(t_list **lst_a, t_list **lst_b)
{
	int	i1;
	int	i2;

	i1 = ft_reverse_rotate(lst_a);
	i2 = ft_reverse_rotate(lst_b);
	if (i1 && i2)
		return ;
	write(1, "rrr\n", 4);
}
