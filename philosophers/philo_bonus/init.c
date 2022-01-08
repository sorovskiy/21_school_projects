/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 19:24:28 by                   #+#    #+#             */
/*   Updated: 2022/01/07 11:17:44 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "phylo.h"

int a;

void	init_f(t_phylo *phylo, int n, t_args *args)
{
	int				i;

	i = -1;
	while (++i < n)
	{
		phylo[i].n = i + 1;
		phylo[i].start_time = args->start_time;
		phylo[i].last_eat = args->start_time;
		phylo[i].tt_eat = args->tt_eat;
		phylo[i].tt_sleap = args->tt_sleap;
		phylo[i].tt_eat = args->tt_eat;
		phylo[i].eat_count = args->eat_count;
		phylo[i].sem_fork = args->sem_fork;
		phylo[i].tt_die = args->tt_die;
		phylo[i].sem_pr = args->sem_pr;
	}
}

void	init_args(int argc, char **argv, t_args *args)
{
	if (argc != 5 && argc != 6)
		show_error_and_exit();
	args->n = ft_atoi(argv[1]);
	args->phylo = malloc(sizeof(t_phylo) * args->n);
	args->tt_die = ft_atoi(argv[2]);
	args->tt_eat = ft_atoi(argv[3]);
	args->tt_sleap = ft_atoi(argv[4]);
	args->eat_count = -1;
	sem_unlink("sem_fork");
	sem_unlink("sem_pr");
	args->sem_fork = sem_open("sem_fork", O_EXCL | O_CREAT, 0666, args->n);
	args->sem_pr = sem_open("sem_pr", O_EXCL | O_CREAT, 0666, 1);
	if (argc == 6)
		args->eat_count = ft_atoi(argv[5]);
	gettimeofday(&args->start_time, NULL);
}
