/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 19:24:28 by                   #+#    #+#             */
/*   Updated: 2022/01/05 17:44:37 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "phylo.h"

void	init_f(pthread_mutex_t	*forks, t_phylo *phylo, int n, t_args *args)
{
	int				i;

	i = -1;
	while (++i < n)
	{
		phylo[i].n = i + 1;
		phylo[i].l_fork = &forks[i];
		phylo[i].r_fork = &forks[i + 1];
		phylo[i].start_time = args->start_time;
		phylo[i].last_eat = args->start_time;
		phylo[i].tt_eat = args->tt_eat;
		phylo[i].tt_sleap = args->tt_sleap;
		phylo[i].tt_eat = args->tt_eat;
		phylo[i].eat_count = args->eat_count;
		phylo[i].alive = 1;
		phylo[i].someone_dead = &args->dead;
	}
	phylo[i - 1].r_fork = &forks[0];
	if (i == 1)
		pthread_mutex_lock(&forks[0]);
}

void	init_args(int argc, char **argv, t_args *args)
{
	int	i;

	if (argc != 5 && argc != 6)
		show_error_and_exit();
	args->n = ft_atoi(argv[1]);
	args->forks = malloc(sizeof(pthread_mutex_t) * (args->n + 1));
	args->phylo = malloc(sizeof(t_phylo) * args->n);
	args->threads = malloc(sizeof(pthread_t) * (args->n + 1));
	args->tt_die = ft_atoi(argv[2]);
	args->tt_eat = ft_atoi(argv[3]);
	args->tt_sleap = ft_atoi(argv[4]);
	args->eat_count = -1;
	args->dead = 0;
	if (argc == 6)
		args->eat_count = ft_atoi(argv[5]);
	gettimeofday(&args->start_time, NULL);
	i = -1;
	while (++i < args->n + 1)
		pthread_mutex_init(&args->forks[i], NULL);
}
