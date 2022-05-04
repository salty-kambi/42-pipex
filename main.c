/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuau <lsuau@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 15:31:36 by lsuau             #+#    #+#             */
/*   Updated: 2021/12/11 18:23:07 by lsuau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <string.h>

int	le_child(int *pfd, char **argv, char **envp)
{
	int		fd;
	int		fdout;
	char	*path;
	char	**cmd;

	close(pfd[0]);
	fdout = dup(1);
	fd = open(argv[1], O_RDONLY);
	dup2(fd, 0);
	dup2(pfd[1], 1);
	path = find_path(envp, argv[2]);
	cmd = ft_split(argv[2], ' ');
	if (!path || !cmd)
		return (double_free(path, cmd, fdout));
	execve(path, cmd, envp);
	double_free(path, cmd, -1);
	close(pfd[1]);
	close(fd);
	exit(0);
}

int	le_parent(int *pfd, char **argv, char **envp)
{
	int		fd;
	int		fdout;
	char	*path;
	char	**cmd;

	close(pfd[1]);
	fdout = dup(1);
	fd = open(argv[4], O_CREAT | O_RDWR, 0644);
	dup2(fd, 1);
	dup2(pfd[0], 0);
	path = find_path(envp, argv[3]);
	cmd = ft_split(argv[3], ' ');
	if (!path || !cmd)
		return (double_free(path, cmd, fdout));
	execve(path, cmd, envp);
	double_free(path, cmd, -1);
	close(pfd[0]);
	close(fd);
	exit(0);
}

int	main(int argc, char **argv, char **envp)
{
	int		pfd[2];
	int		cpid[2];

	if (argc != 5 || check_file(argv) || pipe(pfd))
	{
		if (errno)
			perror("pipex");
		else
			write(1, "pipex: not enough argument\n", 27);
		return (1);
	}
	cpid[0] = fork();
	if (!cpid[0])
		le_child(pfd, argv, envp);
	else if (cpid[0] != -1)
		le_parent(pfd, argv, envp);
	if (errno)
	{
		perror("pipex");
		return (1);
	}
	return (0);
}
