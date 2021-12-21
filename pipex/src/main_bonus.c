/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 14:46:24 by                   #+#    #+#             */
/*   Updated: 2021/12/17 17:28:18 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex_bonus.h"

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

void	child1(char **env, char *argv)
{
	int		pid;
	int		my_pipe[2];
	char	**command;

	if (pipe(my_pipe) == -1)
		ft_perror("pipex: error when creating the pipe: ");
	pid = fork();
	if (pid == -1)
		ft_perror("pipex: error when forking: ");
	if (pid == 0)
	{
		close(my_pipe[0]);
		dup2(my_pipe[1], 1);
		close(my_pipe[1]);
		command = ft_split(argv, ' ');
		if (execve(find_path(env, command), command, env) == -1)
			ft_perror_message("pipex: command not found", argv);
	}
	if (pid > 0)
	{
		dup2(my_pipe[0], 0);
		close(my_pipe[0]);
		close(my_pipe[1]);
	}
}

void	last_process(char **argv, char **env, int i)
{
	char	**command1;

	command1 = ft_split(argv[i - 1], ' ');
	if (execve(find_path(env, command1), command1, env) == -1)
		ft_perror_message("pipex: command not found", argv[i - 1]);
}

int	main(int argc, char **argv, char **env)
{
	int	fd_in;
	int	fd_out;
	int	count;

	if (argc < 5)
		ft_puterr_fd("error: synthax: ./pipex infile cmd1 cmd2 outfile\n", 2);
	if (ft_strncmp(argv[1], "here_doc", 8) == 0)
	{
		count = 3;
		ft_here_doc(argc, argv);
		fd_out = ft_open_file(argv[argc - 1], 2);
	}
	else
	{
		count = 2;
		fd_in = ft_open_file(argv[1], 0);
		dup2(fd_in, 0);
		close(fd_in);
		fd_out = ft_open_file(argv[argc - 1], 1);
	}
	while (count++ < argc - 2)
		child1(env, argv[count - 1]);
	dup2(fd_out, STDOUT_FILENO);
	close(fd_out);
	last_process(argv, env, count);
}
