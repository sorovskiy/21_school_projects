/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 15:33:27 by                   #+#    #+#             */
/*   Updated: 2021/12/17 15:33:28 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>

char	**ft_split(char const *s, char c);
int		ft_strncmp(char *s1, char *s2, unsigned int n);
char	*ft_strjoin(char *s1, char *s2);
void	free_split_str(char **str_arr);
void	ft_puterr_fd(char *s, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_here_doc(int argc, char **argv);
int		get_next_line(char **line);
int		ft_open_file(char *str, int i);
int		ft_strlen(char *str);
void	ft_perror(char *str);
void	ft_perror_message(char *str, char *str2);

#endif //PIPEX_BONUS_H
