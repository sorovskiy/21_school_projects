/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_b.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 11:57:16 by                   #+#    #+#             */
/*   Updated: 2021/12/13 09:48:34 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	show_error_and_exit(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

void	rotate_before_push_stack_a(t_list **stack_a, int position, int size)
{
	if (position < size - position)
		while (position--)
			rotate_a(stack_a);
	else
		while (position++ < size)
			reverse_rotate_a(stack_a);
}

void	sort_for_3(t_list **stack)
{
	int	a;
	int	b;
	int	c;

	a = (*stack)->content;
	b = (*stack)->next->content;
	c = (*stack)->next->next->content;
	if ((b > c) && (c > a))
	{
		swap_a(stack);
		rotate_a(stack);
	}
	else if ((b > a) && (a > c))
		reverse_rotate_a(stack);
	else if ((c > a) && (a > b))
		swap_a(stack);
	else if ((a > c) && (c > b))
		rotate_a(stack);
	else if ((a > b) && (b > c))
	{
		swap_a(stack);
		reverse_rotate_a(stack);
	}
}

void	rotate_min_elem_up(t_list **stack_b, int size, int i)
{
	int		min;
	int		position;
	t_list	*elem;

	elem = (*stack_b);
	min = INT_MAX;
	while (elem)
	{
		if (elem->content < min)
		{
			min = elem->content;
			position = i;
		}
		elem = elem->next;
		i++;
	}
	rotate_before_push_stack_a(stack_b, position, size);
}

void	sort_for_5(t_list **stack_a, t_list **stack_b, int size)
{
	int	size_b;

	while (size > 3)
	{
		rotate_min_elem_up(stack_a, size, 0);
		size--;
		push_b(stack_a, stack_b);
	}
	sort_for_3(stack_a);
	size_b = ft_lstsize(*stack_b);
	while (size_b--)
		push_a(stack_a, stack_b);
}
