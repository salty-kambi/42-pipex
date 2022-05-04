/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuau <lsuau@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 15:58:35 by lsuau             #+#    #+#             */
/*   Updated: 2021/12/02 11:44:41 by lsuau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	check_word(char const *str, char c, int x, int n)
{
	int	nb_word;
	int	nb_cara;

	nb_word = 0;
	nb_cara = 0;
	while (str[x])
	{
		if (!(str[x] == c) && str[x])
			nb_word++;
		while (!(str[x] == c) && str[x])
		{
			nb_cara++;
			x++;
		}
		while ((str[x] == c || n == 1) && str[x])
			x++;
	}
	if (n == 2)
		return (nb_word);
	else
		return (nb_cara);
}

static int	skip_c(char const *str, char c, int x)
{
	while (str[x] == c && str[x])
		x++;
	return (x);
}

static char	*ft_remp(const char *str, int *x, char c)
{
	char	*r;
	int		y;

	y = 0;
	r = malloc(check_word(str, c, *x, 1) + 1);
	if (!r)
		return (0);
	while (!(str[*x] == c) && str[*x])
		r[y++] = str[(*x)++];
	r[y] = 0;
	return (r);
}

static char	**ft_clearsplit(char **splited, int n)
{
	while (n >= 0)
	{
		free(splited[n]);
		n--;
	}
	free(splited);
	return (0);
}

char	**ft_split(char const *s, char c)
{
	int		nb_word;
	int		x;
	int		n;
	char	**splited;

	if (!s)
		return (0);
	x = 0;
	n = -1;
	nb_word = check_word(s, c, x, 2);
	splited = malloc(sizeof(char *) * (nb_word + 1));
	if (!splited)
		return (0);
	while (nb_word > ++n)
	{
		x = skip_c(s, c, x);
		splited[n] = ft_remp(s, &x, c);
		if (!splited[n])
			return (ft_clearsplit(splited, n));
	}
	splited[n] = 0;
	return (splited);
}
