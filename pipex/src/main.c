/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 15:09:59 by                   #+#    #+#             */
/*   Updated: 2021/12/17 15:15:03 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex.h"

void	ft_perror(char *str)
{
	perror(+str);
	exit(EXIT_FAILURE);
}

char	*find_path(char **env, char **args)
{
	int		i;
	char	**paths;
	char	*path2;

	i = -1;
	while (env[++i])
		if (!ft_strncmp(env[i], "PATH=", 5))
			paths = ft_split(env[i] + 5, ':');
	i = 0;
	while (paths[i])
	{
		if (args[0][0] == '/')
			path2 = args[0];
		else
			path2 = ft_strjoin(paths[i++], *args);
		if (!access (path2, 0))
		{
			free_split_str(paths);
			return (path2);
		}
		free(path2);
	}
	return (NULL);
}

int	child1(int *my_pipe, char **env, char **argv)
{
	int		pid;
	int		fd_in;
	char	**command;

	pid = fork();
	if (pid == -1)
		ft_perror("pipex: error when forking: ");
	if (pid == 0)
	{
		close(my_pipe[0]);
		dup2(my_pipe[1], 1);
		close(my_pipe[1]);

		fd_in = open(argv[1], O_RDONLY);
		if (fd_in < 0)
			ft_perror(argv[1]);
		dup2(fd_in, 0);
		close(fd_in);

		command = ft_split(argv[2], ' ');
		if (execve(find_path(env, command), command, env) == -1)
			ft_perror("pipex: first command not found");
	}
	return (pid);
}

int	main(int argc, char **argv, char **env)
{
	int		fd_out;
	int		my_pipe[2];
	char	**command1;

	if (argc != 5)
		ft_puterr_fd("error: synthax: ./pipex infile cmd1 cmd2 outfile\n", 2);
	if (pipe(my_pipe) == -1)
		ft_perror("pipex: error when creating the pipe: ");

	child1(my_pipe, env, argv);

	fd_out = open(argv[4], O_RDWR | O_TRUNC | O_CREAT, 0666);
	if (fd_out < 0)
		ft_perror(argv[4]);
	dup2(fd_out, 1);
	dup2(my_pipe[0], 0);
	close(fd_out);
	close(my_pipe[0]);
	close(my_pipe[1]);
	command1 = ft_split(argv[3], ' ');

	if (execve(find_path(env, command1), command1, env) == -1)
		ft_perror("pipex: second command not found");
}
