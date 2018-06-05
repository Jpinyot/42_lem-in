/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_insertlink.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpinyot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 22:34:06 by jpinyot           #+#    #+#             */
/*   Updated: 2018/06/05 19:41:54 by jpinyot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "liblem.h"

static char	**samey(t_id *t1, t_id *t2, char **map)
{
	int i;
	int j;

	if (t1->x < t2->x)
	{
		i = t1->x;
		j = t2->x;
	}
	else
	{
		i = t2->x;
		j = t1->x;
	}
	while (map[t1->y][i] && map[t1->y][i] != ' ')
		i++;
	if (i >= t1->x && i >= t2->x)
		return (map);
	while (map[t1->y][++i] && i != j)
		map[t1->y][i] = '-';
	return (map);
}

static char	**straightline(t_id *t1, t_id *t2, char **map)
{
	int i;
	int j;

	if (t1->x == t2->x)
	{
		if (t1->y < t2->y)
		{
			i = t1->y;
			j = t2->y;
		}
		else
		{
			i = t2->y;
			j = t1->y;
		}
		while (map[++i][t1->x] && i < j)
			map[i][t1->x] = '|';
	}
	else if (t1->y == t2->y)
		map = samey(t1, t2, map);
	return (map);
}

static char	**writelinks(char **m, t_id *t1, t_id *t2)
{
	t_id *mx;
	t_id *y;

	if (t1->x < t2->x)
	{
		mx = t1;
		y = t2;
	}
	else
	{
		mx = t2;
		y = t1;
	}
	if (mx->y > y->y)
		linktoup(mx, y, m);
	else
		linktodown(mx, y, m);
	return (m);
}

static char	**inlink(t_hex *h, char **map, int i, int j)
{
	t_id	*t1;
	t_id	*t2;

	t1 = h->id;
	t2 = h->id;
	while (t1 && t1->id != i)
		t1 = t1->next;
	while (t2 && t2->id != j)
		t2 = t2->next;
	if (t1->x == t2->x || t1->y == t2->y)
		return (straightline(t1, t2, map));
	return (writelinks(map, t1, t2));
	return (map);
}

char		**ft_insertlink(t_hex *h, char **map, char **m)
{
	int		i;
	int		j;
	char	**t;

	if (!(h = getlinks(h, m)))
		return (NULL);
	i = -1;
	while (++i < h->map->w)
	{
		j = -1;
		while (++j < h->map->w)
			if (h->map->map[i][j] == 1 && j < i)
				map = inlink(h, map, i, j);
	}
	return (map);
}
