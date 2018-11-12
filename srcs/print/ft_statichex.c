/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_statichex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpinyot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 18:40:36 by jpinyot           #+#    #+#             */
/*   Updated: 2018/09/29 22:30:53 by jpinyot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "liblem.h"

static int	maxlen(char **m)
{
	int		i;
	int		cnt;
	int		cnt2;
	char	*t;

	i = -1;
	cnt = 0;
	while (m[++i])
	{
		if (m[i][0] != '#' && (t = ft_strchr(m[i], ' ')))
		{
			if (ft_atoi(t) > cnt)
			{
				cnt = ft_atoi(t);
				cnt2 = i;
			}
		}
	}
	i = 0;
	while (m[cnt2][i] && m[cnt2][i] != ' ')
		i++;
	return (i);
}

static char	**ft_roomlen(char **m, char **s)
{
	int		i;
	int		cnt;

	i = -1;
	cnt = maxlen(m);
	while (++i < 31)
	{
		if (!(s[i] = ft_strnew(71 + cnt)))
			return (NULL);
		ft_memset(s[i], ' ', 71 + cnt);
	}
	return (s);
}

static char	**insertroom(t_hex *h, char **map)
{
	t_id	*t;
	int		x;
	int		i;

	t = h->id;
	while (t)
	{
		if (t->x > -1 && t->y > -1)
		{
			i = -1;
			x = t->x - 1;
			while (t->n[++i] && map[t->y][++x])
				map[t->y][x] = t->n[i];
		}
		t = t->next;
	}
	return (map);
}

static int	nonrepeat(t_hex *h)
{
	t_id	*t;
	t_id	*t2;
	int		i;
	int		j;

	t = h->id;
	while (t->next)
	{
		t2 = t->next;
		while (t2)
		{
			if (t->x < t2->x && (j = t2->x))
				i = t->x + ft_strlen(t->n);
			else if (t->x >= t2->x && (j = t->x))
				i = t2->x + ft_strlen(t->n);
			if (t->y == t2->y && i >= j)
				return (0);
			t2 = t2->next;
		}
		t = t->next;
	}
	return (1);
}

char		**ft_statichex(t_hex *h, char **m)
{
	char	**map;

	if (h->map->w > 10)
		return (NULL);
	if (!(map = (char **)malloc(sizeof(char **) * (32))))
		return (NULL);
	map[31] = NULL;
	if (!(map = ft_roomlen(m, map)))
		return (NULL);
	if (!(h->id = ft_getaxis(h, m)))
		return (NULL);
	if (!(nonrepeat(h)))
	{
		ft_deletedstr(map);
		return (NULL);
	}
	map = insertroom(h, map);
	map = ft_insertlink(h, map, m);
	return (map);
}
