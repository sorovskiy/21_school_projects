/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 15:17:17 by                   #+#    #+#             */
/*   Updated: 2021/12/17 15:17:18 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>

char	**ft_split(char const *s, char c);
int		ft_strncmp(char *s1, char *s2, unsigned int n);
char	*ft_strjoin(char *s1, char *s2);
void	free_split_str(char **str_arr);
void	ft_puterr_fd(char *s, int fd);
int		ft_strlen(char *str);
void	ft_perror(char *str);

#endif //PIPEX_H
