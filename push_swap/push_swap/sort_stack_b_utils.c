/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sosrt_stack_b_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 09:29:06 by                   #+#    #+#             */
/*   Updated: 2021/12/13 09:32:16 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	rotate_before_push_b(t_list **stack_b, int position, int size)
{
	if (position < size - position)
		while (position--)
			rotate_b(stack_b);
	else
		while (position++ < size)
			reverse_rotate_b(stack_b);
}

void	rotate_ab(t_list **stack_a, t_list **stack_b, int pos, t_values vals)
{
	int	size;

	size = ft_lstsize(*stack_b);
	if (pos < size - pos)
		while (pos--)
			rotate_b(stack_b);
	else
		while (pos++ < size)
			reverse_rotate_b(stack_b);
	if (vals.upwards > vals.downwards)
		while (vals.upwards--)
			rotate_a(stack_a);
	else
		while (vals.downwards--)
			reverse_rotate_a(stack_a);
}

void	rotate_else(t_list **stack_a, t_list **stack_b, int pos, t_values vals)
{
	int	size;

	size = ft_lstsize(*stack_b);
	if (pos - vals.upwards <= size - pos - vals.downwards && vals.upwards)
	{
		while (pos-- && vals.upwards--)
			rotate_rotate(stack_a, stack_b);
		while (pos-- >= 0)
			rotate_b(stack_b);
		while (vals.upwards-- > 0)
			rotate_a(stack_a);
	}
	else if (pos - vals.upwards > size - pos - vals.downwards && vals.downwards)
	{
		while (pos++ < size && vals.downwards--)
			reverse_rotate_rotate(stack_a, stack_b);
		while (pos++ <= size)
			reverse_rotate_b(stack_b);
		while (vals.downwards-- > 0)
			reverse_rotate_a(stack_a);
	}
	else
		rotate_ab(stack_a, stack_b, pos, vals);
}

void	rotate(t_list **stack_a, t_list **stack_b, int position, t_values vals)
{
	int	size;

	size = ft_lstsize(*stack_b);
	if (position <= size - position && vals.upwards > 0)
	{
		while (position-- && vals.upwards--)
			rotate_rotate(stack_a, stack_b);
		while (position-- >= 0)
			rotate_b(stack_b);
		while (vals.upwards-- > 0)
			rotate_a(stack_a);
	}
	else if ((position > size - position && vals.downwards > 0))
	{
		while (position++ < size && vals.downwards--)
			reverse_rotate_rotate(stack_a, stack_b);
		while (position++ <= size)
			reverse_rotate_b(stack_b);
		while (vals.downwards-- > 0)
			reverse_rotate_a(stack_a);
	}
	else
		rotate_else(stack_a, stack_b, position, vals);
}

void	rotate_max_elem_up(t_list **stack_b, int size, int i)
{
	int		max;
	int		position;
	t_list	*elem;

	elem = (*stack_b);
	max = INT_MIN;
	while (elem)
	{
		if (elem->content > max)
		{
			max = elem->content;
			position = i;
		}
		elem = elem->next;
		i++;
	}
	rotate_before_push_b(stack_b, position, size);
}
