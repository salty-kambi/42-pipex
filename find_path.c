/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuau <lsuau@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 18:26:37 by lsuau             #+#    #+#             */
/*   Updated: 2021/12/04 17:35:30 by lsuau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*get_pathl(char **envp)
{
	int	x;

	x = 0;
	while (envp[x])
	{
		if (!ft_strncmp(envp[x], "PATH=", 5))
			return (envp[x] + 5);
		x++;
	}
	return (0);
}

int	add_slash(char **paths, char *cmd)
{
	int		x;
	int		lp;
	int		lc;
	char	*s;

	x = 0;
	while (paths[x])
	{
		lp = ft_strlen(paths[x]);
		lc = ft_strlen(cmd);
		s = malloc(sizeof(char) * (lp + lc + 2));
		if (!s)
			return (1);
		ft_strcpy(s, paths[x]);
		s[lp] = '/';
		ft_strcpy(s + lp + 1, cmd);
		free(paths[x]);
		paths[x] = s;
		x++;
	}
	return (0);
}

char	*remove_arg(char *cmd)
{
	int		x;
	char	*s;

	x = 0;
	while (cmd[x] && cmd[x] != ' ')
		x++;
	s = malloc(sizeof(char) * (x + 1));
	if (!s)
		return (0);
	x = 0;
	while (cmd[x] && cmd[x] != ' ')
	{
		s[x] = cmd[x];
		x++;
	}
	s[x] = 0;
	return (s);
}

int	le_finder(char **paths, char **s)
{
	int	x;

	free(*s);
	x = 0;
	while (paths[x] && access(paths[x], F_OK))
		x++;
	if (!paths[x])
		*s = 0;
	else
		*s = ft_strdup(paths[x]);
	return (0);
}

char	*find_path(char **envp, char *cmd)
{
	char	**paths;
	char	*s;

	s = remove_arg(cmd);
	if (!s)
		return (0);
	paths = ft_split(get_pathl(envp), ':');
	if (!paths)
	{
		free(s);
		return (0);
	}
	if (add_slash(paths, s) || le_finder(paths, &s))
		s = (char *)s;
	free_table(paths);
	return (s);
}
