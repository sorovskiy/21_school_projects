/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 13:40:56 by                   #+#    #+#             */
/*   Updated: 2021/12/07 14:01:28 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	swap_a(t_list **lst)
{
	if (ft_swap(lst))
		return ;
	write(1, "sa\n", 3);
}

void	swap_b(t_list **lst)
{
	if (ft_swap(lst))
		return ;
	write(1, "sb\n", 3);
}

void	swap_swap(t_list **lst_a, t_list **lst_b)
{
	int	i1;
	int	i2;

	i1 = ft_swap(lst_a);
	i2 = ft_swap(lst_b);
	if (i1 && i2)
		return ;
	write(1, "ss\n", 3);
}
