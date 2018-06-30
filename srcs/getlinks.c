/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getlinks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpinyot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 20:12:32 by jpinyot           #+#    #+#             */
/*   Updated: 2018/06/30 23:57:07 by jpinyot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "liblem.h"

static int	maplinks(char **m)
{
	int i;
	int j;
	int cnt;

	i = 0;
	while (m[i])
	{
		cnt = 0;
		j = 0;
		while (m[i][j])
		{
			if (m[i][j] == ' ')
			{
				cnt = 0;
				break ;
			}
			if (m[i][j] == '-')
				cnt++;
			j++;
		}
		if (cnt > 0)
			return (i);
		i++;
	}
	return (-1);
}

static int	findroom_else(t_id *id, char *s)
{
	char	*t;
	t_id	*d;
	int		i;
	int		j;

	d = id;
	t = s;
	while (d)
	{
		i = ft_strlen(t);
		j = ft_strlen(d->n);
		while (i >= 0 && j >= 0 && t[i] == d->n[j])
		{
			i--;
			j--;
		}
		if (j == -1 && t[i] == '-')
			return (d->id);
		d = d->next;
	}
	return (-1);
}

static int	findroom(t_id *id, char *s, int x)
{
	char	*t;
	t_id	*d;
	int		i;
	int		j;

	d = id;
	t = s;
	if (x)
	{
		while (d)
		{
			i = 0;
			t = s;
			while (d->n[i] && t[i] && d->n[i] == t[i])
				i++;
			if (d->n[i] == 0 && t[i] == '-')
				return (d->id);
			d = d->next;
		}
	}
	else
		return (findroom_else(id, s));
	return (-1);
}

t_hex		*getlinks(t_hex *h, char **map)
{
	int	i;
	int	x;
	int	y;

	if ((i = maplinks(map)) == -1)
		ft_exit();
	while (map[i])
	{
		if (map[i][0] != '#')
		{
			if ((x = findroom(h->id, map[i], 1)) == -1)
				ft_exit();
			if ((y = findroom(h->id, map[i], 0)) == -1)
				ft_exit();
			if (x != y)
			{
				h->map->map[x][y] = 1;
				h->map->map[y][x] = 1;
			}
		}
		i++;
	}
	h->map = ft_mindistance(h->map);
	return (h);
}
