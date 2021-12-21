/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 10:59:17 by                   #+#    #+#             */
/*   Updated: 2021/12/13 17:46:41 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	ft_atoi(char *str)
{
	int	i;
	int	k;
	int	flag;

	i = 0;
	k = 1;
	flag = 0;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '+' || *str == '-')
		if (*str++ == '-')
			k = -1;
	while (*str >= '0' && *str <= '9')
	{
		flag = 1;
		i = i * 10 + (*str - '0') * k;
		str++;
		if ((k == 1 && i < 0) || (k == -1 && i > 0))
			show_error_and_exit();
	}
	if (flag == 0 || *str != '\0')
		show_error_and_exit();
	return (i);
}

int	check_sorting(t_list **stack1)
{
	t_list	*tmp;

	tmp = *stack1;
	while (tmp->next)
	{
		if (tmp->content > tmp->next->content)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}
