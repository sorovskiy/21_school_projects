/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra_rb_rr_operations.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 14:01:32 by                   #+#    #+#             */
/*   Updated: 2021/12/07 14:01:32 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	rotate_a(t_list **lst)
{
	if (ft_rotate(lst))
		return ;
	write(1, "ra\n", 3);
}

void	rotate_b(t_list **lst)
{
	if (ft_rotate(lst))
		return ;
	write(1, "rb\n", 3);
}

void	rotate_rotate(t_list **lst_a, t_list **lst_b)
{
	int	i1;
	int	i2;

	i1 = ft_rotate(lst_a);
	i2 = ft_rotate(lst_b);
	if (i1 && i2)
		return ;
	write(1, "rr\n", 3);
}
