/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuau <lsuau@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 18:51:43 by lsuau             #+#    #+#             */
/*   Updated: 2021/12/04 17:35:32 by lsuau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int	x;

	x = 0;
	if (n < 1)
		return (0);
	while (s1[x] && s2[x] && (s1[x] == s2[x]) && n > 0)
	{
		n--;
		if (n > 0)
			x++;
	}
	return ((unsigned char)s1[x] - (unsigned char)s2[x]);
}

int	ft_strlen(const char *s)
{
	int	x;

	x = 0;
	while (s[x])
		x++;
	return (x);
}

int	ft_strcpy(char *dst, const char *src)
{
	int	x;

	x = 0;
	while (src[x])
	{
		dst[x] = src[x];
		x++;
	}
	dst[x] = 0;
	return (0);
}

char	*ft_strdup(const char *s1)
{
	char	*r;

	r = malloc(ft_strlen(s1) + 1);
	if (!r)
		return (0);
	ft_strcpy(r, s1);
	return (r);
}
