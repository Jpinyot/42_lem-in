/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getpaths.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpinyot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 19:56:34 by jpinyot           #+#    #+#             */
/*   Updated: 2018/06/30 23:27:39 by jpinyot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "liblem.h"

static t_hex	*insertroom(t_hex *h, int r)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < h->w && h->path[i][0] != -1 && h->path[i][0] != -2)
		i++;
	if (i == h->w)
		return (NULL);
	if (h->path[i][0] == -1)
		h->path[i][0] = -2;
	i = 0;
	while (i < h->w && h->path[i][0] != -2)
		i++;
	if (i == h->w)
		return (NULL);
	while (j < h->map->w && h->path[i][j] != -1)
		j++;
	if (j == h->map->w)
		return (NULL);
	h->path[i][j] = r;
	return (h);
}

static t_hex	*endroom(t_hex *h, int i)
{
	int j;

	j = 0;
	if (h->map->map[i][h->map->w - 1] == 1)
	{
		h = insertroom(h, h->map->w - 1);
		while (j < h->w && h->path[j][0] != -2)
			j++;
		h->path[j][0] = 0;
		h->map->map[i][h->map->w - 1] = 0;
		h->map->map[h->map->w - 1][i] = 0;
	}
	j = -1;
	while (++j < h->map->w)
		if (h->map->map[j][h->map->w - 1] > 1)
			h->map->map[j][h->map->w - 1] = 0;
	return (h);
}

static int		extractpath_s(t_hex *h, int l)
{
	int	i;
	int	j;

	i = 0;
	while (l > 0)
	{
		j = -1;
		while (++j < h->map->w)
			if (h->map->map[i][j] == 1 && h->map->map[j][h->map->w - 1] == l)
				break ;
		if (j == h->map->w)
			return (0);
		h->map->map[i][j] = 0;
		h->map->map[i][h->map->w - 1] = 0;
		h->map->map[j][i] = 0;
		if (!(h = insertroom(h, j)))
			return (0);
		l--;
		i = j;
	}
	h = endroom(h, j);
	return (1);
}

static int		extractpath(t_hex *h)
{
	int	l;
	int	i;
	int	j;

	i = 0;
	j = l;
	if ((l = h->map->map[0][h->map->w - 1] - 1) < 1)
	{
		if (l != 0)
			return (0);
		h = endroom(h, 0);
		return (1);
	}
	return (extractpath_s(h, l));
}

t_hex			*getpaths(t_hex *h)
{
	int **p;

	if (!(h = intmalloc(h)))
		ft_exit();
	while (extractpath(h) != 0)
		h->map = ft_mindistance(h->map);
	if (h->path[0][0] < 0)
		ft_exit();
	return (h);
}
