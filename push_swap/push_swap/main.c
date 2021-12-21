/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 13:44:00 by                   #+#    #+#             */
/*   Updated: 2021/12/14 10:17:00 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"
#include <stdio.h>

int	stack_init(t_list **lst, char *str)
{
	char	**str_arr;
	int		i;
	int		n;

	*lst = NULL;
	str_arr = ft_split(str, ' ');
	i = 0;
	while (str_arr[i] != NULL)
		i++;
	n = i;
	while (--i >= 0)
		ft_push(lst, ft_lstnew(ft_atoi(str_arr[i])));
	i = 0;
	while (str_arr[i])
	{
		free(str_arr[i]);
		i++;
	}
	free(str_arr);
	return (n);
}

int	stack_init2(t_list **stack_a, int argc, char **argv)
{
	int	n;

	*stack_a = NULL;
	n = 0;
	while (argc-- > 1)
	{
		ft_push(stack_a, ft_lstnew(ft_atoi(argv[argc])));
		n++;
	}
	return (n);
}

void	set_stack_indexes(t_list **stack_a, const int n, int j, int i)
{
	int		min;
	int		pos;
	t_list	*stack;

	while (j < n)
	{
		stack = *stack_a;
		i = 0;
		pos = 0;
		min = INT_MAX;
		while (stack)
		{
			if (++i && stack->content < min && stack->index == -1)
			{
				min = stack->content;
				pos = i - 1;
			}
			stack = stack->next;
		}
		stack = *stack_a;
		i = 0;
		while (i++ < pos)
			stack = stack->next;
		stack->index = j++;
	}
}

void	check_duplicates(t_list *stack)
{
	t_list	*tmp1;
	t_list	*tmp2;
	int		i;

	tmp1 = stack;
	i = ft_lstsize(stack);
	while (i > 0)
	{
		tmp2 = tmp1->next;
		while (tmp2)
		{
			if (tmp1->content == tmp2->content)
				show_error_and_exit();
			tmp2 = tmp2->next;
		}
		tmp1 = tmp1->next;
		i--;
	}
}

void ft_lstprint(t_list *lst)
{
	while (lst)
	{
		printf("%d - %d\n", lst->content, lst->index);
		lst = lst->next;
	}
}

int	main(int argc, char **argv)
{
	int		n;
	t_list	*stack_a;
	t_list	*stack_b;

	n = 0;
	if (argc < 2)
		show_error_and_exit();
	else if (argc == 2)
		n = stack_init(&stack_a, argv[1]);
	else
		n = stack_init2(&stack_a, argc, argv);
	set_stack_indexes(&stack_a, n, 0, 0);
	check_duplicates(stack_a);



	if (!check_sorting(&stack_a))
		return (0);
	if (n == 2 && (stack_a->content > stack_a->next->content))
		swap_a(&stack_a);
	else if (n == 3)
		sort_for_3(&stack_a);
	else if (n <= 7)
		sort_for_5(&stack_a, &stack_b, n);
	else if (n <= 100)
		bulka_sort(&stack_a, &stack_b, n, 6);
	else
		bulka_sort(&stack_a, &stack_b, n, 13);

}
