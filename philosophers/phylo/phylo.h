/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phylo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 14:36:50 by                   #+#    #+#             */
/*   Updated: 2022/01/05 17:44:37 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PHYLO_H
# define PHYLO_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_phylo
{
	int				n;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*r_fork;
	struct timeval	last_eat;
	int				*someone_dead;
	struct timeval	start_time;
	int				tt_eat;
	int				tt_sleap;
	int				eat_count;
	int				alive;
}	t_phylo;

typedef struct s_args
{
	int				n;
	pthread_mutex_t	*forks;
	t_phylo			*phylo;
	pthread_t		*threads;
	int				tt_die;
	int				tt_eat;
	int				tt_sleap;
	int				eat_count;
	struct timeval	start_time;
	int				dead;
}	t_args;

int		ft_atoi(char *str);
void	show_error_and_exit(void);
long	time_calc(struct timeval start);
void	init_f(pthread_mutex_t	*forks, t_phylo *phylo, int n, t_args *args);
void	init_args(int argc, char **argv, t_args *args);

#endif //PHYLO_H
