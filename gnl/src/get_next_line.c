/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlexie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 10:50:20 by jlexie            #+#    #+#             */
/*   Updated: 2021/07/23 10:50:39 by jlexie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"
#include <stdio.h>

int	chk_line_end(char *buf)
{
	while (*buf)
	{
		if (*buf == '\n')
			return (1);
		buf++;
	}
	return (0);
}

void	strtrim(char *s, char *ost)
{
	while (*s != '\n')
		s++;
	s++;
	while (*s)
	{
		*ost++ = *s;
		*s = '\0';
		s++;
	}
	*ost = '\0';
}

int	buf_not_empty(char *buf, char *line)
{
	if (*buf)
	{
		free(line);
		line = ft_strdup(buf);
		if (chk_line_end(buf))
		{
			strtrim(line, buf);
			return (1);
		}
	}
	return (0);
}

char	*read_file2(int fd, char *buf, char *line)
{
	int	n;

	n = read(fd, buf, BUFFER_SIZE);
	buf[n] = '\0';
	while (n > 0)
	{
		line = ft_strjoin(line, buf);
		if (chk_line_end(buf))
		{
			strtrim(line, buf);
			return (line);
		}
		n = read(fd, buf, BUFFER_SIZE);
		buf[n] = '\0';
		if (n == 0)
			return (line);
	}
	return (line);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	buf[BUFFER_SIZE + 1];

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	line = malloc(sizeof(char) * 1);
	if (!line)
		return (NULL);
	line[0] = '\0';
	if (*buf)
	{
		free(line);
		line = ft_strdup(buf);
		if (chk_line_end(buf))
		{
			strtrim(line, buf);
			return (line);
		}
	}
	line = read_file2(fd, buf, line);
	if (line[0] != '\0')
		return (line);
	free(line);
	return (NULL);
}
