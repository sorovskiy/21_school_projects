/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 14:33:59 by                   #+#    #+#             */
/*   Updated: 2022/01/06 12:12:57 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "phylo.h"

void	lock_forks(t_phylo *phylo)
{
	pthread_mutex_lock(phylo->l_fork);
	if (!*phylo->someone_dead)
		printf("%ld %d has taken a fork\n",
			   time_calc(phylo->start_time), phylo->n);
	pthread_mutex_lock(phylo->r_fork);
	if (!*phylo->someone_dead)
		printf("%ld %d has taken a fork\n",
			   time_calc(phylo->start_time), phylo->n);
	gettimeofday(&(phylo->last_eat), NULL);
	if (!*phylo->someone_dead)
		printf("%ld %d is eating\n", time_calc(phylo->start_time), phylo->n);
	usleep(phylo->tt_eat * 1000);
	pthread_mutex_unlock(phylo->l_fork);
	pthread_mutex_unlock(phylo->r_fork);
}

void	*meal(void *args)
{
	t_phylo	*phyl;

	phyl = (t_phylo *) args;
	if (phyl->n % 2 != 0)
		usleep((phyl->tt_eat - (phyl->tt_eat / 10)) * 1000);
	while (phyl->eat_count && !*phyl->someone_dead)
	{
		lock_forks(phyl);
		if (phyl->eat_count != -1)
			phyl->eat_count -= 1;
		if (!*phyl->someone_dead)
			printf("%ld %d is sleeping\n", time_calc(phyl->start_time), phyl->n);
		usleep(phyl->tt_sleap * 1000);
		if (!*phyl->someone_dead)
			printf("%ld %d is thinking\n", time_calc(phyl->start_time), phyl->n);
	}
	return (0);
}

void	*observation(void *args_v)
{
	t_args	*args;
	int		i;

	args = (t_args *) args_v;
	while (1)
	{
		i = -1;
		usleep(2000);
		while (++i < args->n)
		{
			if (time_calc(args->phylo[i].last_eat) > args->tt_die
				&& args->phylo[i].eat_count != 0)
			{
				*args->phylo[i].someone_dead = 1;
				printf("phylosopher %d died\n", args->phylo[i].n);
				return (NULL);
			}
		}
	}
}

int	main(int argc, char **argv)
{
	t_args	args;
	int		i;

	init_args(argc, argv, &args);
	init_f(args.forks, args.phylo, args.n, &args);
	pthread_create(&args.threads[args.n], NULL, observation, &args);
	i = -1;
	if (args.n == 1)
	{
		usleep((args.tt_die + 20) * 1000);
		return (0);
	}
	while (++i < args.n)
		pthread_create(&args.threads[i], NULL, meal, &args.phylo[i]);
	i = -1;
	while (++i < args.n)
		pthread_join(args.threads[i], NULL);
}
