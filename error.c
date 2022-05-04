/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuau <lsuau@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 12:00:11 by lsuau             #+#    #+#             */
/*   Updated: 2021/12/05 15:21:36 by lsuau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	check_file(char **argv)
{
	errno = 0;
	if (access(argv[1], R_OK))
		return (1);
	if (access(argv[4], F_OK))
		return (0);
	else
	{
		if (access(argv[4], W_OK))
			return (1);
		if (unlink(argv[4]))
			return (1);
	}
	return (0);
}

void	free_table(char **del)
{
	int	n;

	if (!del)
		return ;
	n = 0;
	while (del[n])
	{
		free(del[n]);
		n++;
	}
	free(del);
}

int	double_free(char *t1, char **t2, int fd)
{
	if (t1)
		free(t1);
	free_table(t2);
	if (fd > -1)
		write(fd, "pipex: command not found\n", 25);
	waitpid(-1, 0, 0);
	exit(0);
	return (1);
}
