/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 14:33:59 by                   #+#    #+#             */
/*   Updated: 2022/01/07 11:05:43 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "phylo.h"

void	check_death(t_phylo *phylo, pid_t pid)
{
	long	tmp;

	tmp = time_calc(phylo->last_eat);
	if (tmp > phylo->tt_die)
	{
		sem_wait(phylo->sem_pr);
		printf("%ld %d died\n", tmp, phylo->n);
		kill(pid, SIGKILL);
	}
}

void	lock_forks(t_phylo *phylo, pid_t pid)
{
	sem_wait(phylo->sem_fork);
	check_death(phylo, pid);
	sem_wait(phylo->sem_pr);
	printf("%ld %d has taken a fork\n", time_calc(phylo->start_time), phylo->n);
	sem_post(phylo->sem_pr);
	sem_wait(phylo->sem_fork);
	check_death(phylo, pid);
	sem_wait(phylo->sem_pr);
	printf("%ld %d has taken a fork\n", time_calc(phylo->start_time), phylo->n);
	gettimeofday(&(phylo->last_eat), NULL);
	printf("%ld %d is eating\n", time_calc(phylo->start_time), phylo->n);
	sem_post(phylo->sem_pr);
	usleep(phylo->tt_eat * 1000);
	sem_post(phylo->sem_fork);
	sem_post(phylo->sem_fork);
	if (phylo->eat_count != -1)
		phylo->eat_count -= 1;
}

void	*meal(void *args)
{
	t_phylo	*phyl;
	int		pid;

	phyl = (t_phylo *) args;
	pid = fork();
	if (pid == 0)
	{
		if (phyl->n % 2 != 0)
			usleep((phyl->tt_eat - (phyl->tt_eat / 10)) * 1000);
		while (phyl->eat_count)
		{
			lock_forks(phyl, pid);
			check_death(phyl, pid);
			sem_wait(phyl->sem_pr);
			printf("%ld %d is sleeping\n", time_calc(phyl->start_time), phyl->n);
			sem_post(phyl->sem_pr);
			usleep(phyl->tt_sleap * 1000);
			check_death(phyl, pid);
			sem_wait(phyl->sem_pr);
			printf("%ld %d is thinking\n", time_calc(phyl->start_time), phyl->n);
			sem_post(phyl->sem_pr);
		}
		exit(0);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_args	args;
	int		status;
	int		i;

	init_args(argc, argv, &args);
	init_f(args.phylo, args.n, &args);
	if (args.n == 1)
	{
		usleep((args.tt_die + 20) * 1000);
		printf("%d %d died\n", args.tt_die, 1);
		return (0);
	}
	i = -1;
	while (++i < args.n)
		meal(&args.phylo[i]);
	while (waitpid(-1, &status, 0) > 0)
		;
	sem_unlink("sem_fork");
	sem_unlink("sem_pr");
}
