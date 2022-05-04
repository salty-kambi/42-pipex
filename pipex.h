/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuau <lsuau@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 15:32:36 by lsuau             #+#    #+#             */
/*   Updated: 2021/12/03 21:33:37 by lsuau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <errno.h>

char	**ft_split(char const *s, char c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*find_path(char **envp, char *cmd);
int		check_file(char **argv);
int		ft_strlen(const char *s);
int		ft_strcpy(char *dst, const char *src);
void	free_table(char **del);
int		double_free(char *t1, char **t2, int fd);
char	*ft_strdup(const char *s1);

#endif