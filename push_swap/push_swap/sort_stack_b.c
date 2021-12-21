/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_b.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 11:57:16 by                   #+#    #+#             */
/*   Updated: 2021/12/12 18:29:39 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	rotate_before_push_a(t_list **stack_a, int upwards_a, int downwards_a)
{
	if (upwards_a > downwards_a)
		while (upwards_a--)
			rotate_a(stack_a);
	else
		while (downwards_a--)
			reverse_rotate_a(stack_a);
}

void	rotate_max_up(t_list **stack_b, int i, t_list **stack_a, t_values vals)
{
	int		max;
	int		position;
	t_list	*elem;

	position = 0;
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
	rotate(stack_a, stack_b, position, vals);
}

void	if_first_is_bigger(t_list **stack_b, t_list **stack_a, t_values vals)
{
	int		position;
	t_list	*elem;

	elem = (*stack_b);
	position = 0;
	while (elem->content > vals.value)
	{
		position++;
		elem = elem->next;
	}
	rotate(stack_a, stack_b, position, vals);
}

void	if_first_is_less(t_list **stack_b, t_list **stack_a, t_values vals)
{
	int		position;
	int		i;
	t_list	*elem;

	i = 0;
	elem = (*stack_b);
	position = 0;
	while (elem)
	{
		if (elem->content > vals.value)
			position = i;
		elem = elem->next;
		i++;
	}
	rotate(stack_a, stack_b, ++position, vals);
}

void	sort_stack_b(t_list **stack_b, t_list **stack_a, t_values val)
{
	t_list	*elem;
	int		biggest;
	int		lowest;

	biggest = 1;
	lowest = 1;
	elem = *stack_b;
	while (elem)
	{
		if (elem->content > val.value)
			biggest = 0;
		else
			lowest = 0;
		elem = elem->next;
	}
	if (biggest == 1 || lowest == 1)
		rotate_max_up(stack_b, 0, stack_a, val);
	else if ((*stack_b)->content > val.value)
		if_first_is_bigger(stack_b, stack_a, val);
	else if (ft_lstlast(*stack_b)->content < val.value)
		if_first_is_less(stack_b, stack_a, val);
	else
		rotate_before_push_a(stack_a, val.upwards, val.downwards);
}
