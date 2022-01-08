/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phylo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 14:36:50 by                   #+#    #+#             */
/*   Updated: 2022/01/07 11:12:09 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PHYLO_H
# define PHYLO_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>
# include "semaphore.h"
# include <signal.h>

typedef struct s_phylo
{
	int				n;
	struct timeval	last_eat;
	struct timeval	start_time;
	int				tt_eat;
	int				tt_sleap;
	int				eat_count;
	sem_t			*sem_fork;
	sem_t			*sem_pr;
	int				tt_die;
}	t_phylo;

typedef struct s_args
{
	int				n;
	t_phylo			*phylo;
	int				tt_die;
	int				tt_eat;
	int				tt_sleap;
	int				eat_count;
	struct timeval	start_time;
	sem_t			*sem_fork;
	sem_t			*sem_pr;
}	t_args;

int		ft_atoi(char *str);
void	show_error_and_exit(void);
long	time_calc(struct timeval start);
void	init_f(t_phylo *phylo, int n, t_args *args);
void	init_args(int argc, char **argv, t_args *args);

#endif //PHYLO_H
