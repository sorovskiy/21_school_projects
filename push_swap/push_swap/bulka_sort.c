/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_b.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 11:57:16 by                   #+#    #+#             */
/*   Updated: 2021/12/14 09:42:21 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	find_up_low_pos(t_list **stack_a, int min, int max, t_values *vals)
{
	int		k;
	t_list	*elem;

	k = 0;
	elem = *stack_a;
	while (elem && (elem->index < min || elem->index > max))
	{
		elem = elem->next;
		k++;
	}
	if (elem)
		vals->upwards = k;
	k = 0;
	elem = *stack_a;
	while (elem)
	{
		if (elem->index >= min && elem->index <= max)
			vals->downwards = k;
		elem = elem->next;
		k++;
	}
}

int	find_value_by_position(t_list **stack_a, int position)
{
	t_list	*tmp;

	tmp = *stack_a;
	while (position--)
		tmp = tmp->next;
	return (tmp->content);
}

int	find_nearest(int min, int max, t_list **stack_a, t_values *a)
{
	int	n;

	n = ft_lstsize(*stack_a);
	a->upwards = 0;
	a->downwards = -1;
	find_up_low_pos(stack_a, min, max, a);
	if (a->downwards == -1)
		return (0);
	a->downwards = n - a->downwards;
	if (a->upwards < a->downwards)
	{
		a->downwards = 0;
		a->value = find_value_by_position(stack_a, a->upwards);
	}
	else
	{
		a->value = find_value_by_position(stack_a, n - a->downwards);
		a->upwards = 0;
	}
	return (1);
}

void	bulka_sort(t_list **stack_a, t_list **stack_b, const int n, int part)
{
	int			i;
	int			min;
	int			max;
	t_values	up_down_val;

	i = 0;
	while (i <= part)
	{
		min = n / part * i;
		max = n / part * (i + 1) - 1;
		while (find_nearest(min, max, stack_a, &up_down_val))
		{
			find_nearest(min, max, stack_a, &up_down_val);
			sort_stack_b(stack_b, stack_a, up_down_val);
			push_b(stack_a, stack_b);
		}
		i++;
	}
	rotate_max_elem_up(stack_b, n, 0);
	while ((*stack_b))
		push_a(stack_a, stack_b);
}
