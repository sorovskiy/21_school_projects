/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 14:53:53 by                   #+#    #+#             */
/*   Updated: 2022/01/06 13:03:31 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "phylo.h"

long	time_calc(struct timeval start)
{
	struct timeval	dif;
	struct timeval	curr;

	gettimeofday(&curr, NULL);
	dif.tv_sec = curr.tv_sec - start.tv_sec;
	dif.tv_usec = curr.tv_usec - start.tv_usec;
	return ((dif.tv_sec * 1000) + (dif.tv_usec / 1000));
}

void	show_error_and_exit(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

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
