/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ephantom <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 11:28:47 by ephantom          #+#    #+#             */
/*   Updated: 2021/12/17 17:25:34 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex_bonus.h"

void	ft_perror(char *str)
{
	perror(str);
	exit(EXIT_FAILURE);
}

void	ft_perror_message(char *str, char *str2)
{
	perror(str);
	ft_putstr_fd(str2, 2);
	ft_putstr_fd("\n", 2);
	exit(EXIT_FAILURE);
}

void	ft_puterr_fd(char *s, int fd)
{
	if (!s)
		return ;
	while (*s != '\0')
	{
		write(fd, s, 1);
		s++;
	}
	exit(1);
}

static void	ft_add(int i, char buffer, char **line, char *join)
{
	join[i++] = buffer;
	join[i] = '\0';
	free(*line);
	*line = join;
}

int	get_next_line(char **line)
{
	int		i;
	int		num;
	char	*join;
	char	buffer[1];

	i = 0;
	(*line) = (char *) malloc(sizeof(char) * 1);
	if (!(*line) || !line)
		return (-1);
	(*line)[0] = '\0';
	num = 1;
	while ((num > 0) && buffer[0] != '\n')
	{
		num = read(0, buffer, 1);
		join = (char *) malloc(sizeof(char) * ((ft_strlen(*line)) + 2));
		if (!join)
			return (-1);
		while ((*line)[i])
		{
			join[i] = (*line)[i];
			i++;
		}
		ft_add(i, buffer[0], line, join);
	}
	return (num);
}
