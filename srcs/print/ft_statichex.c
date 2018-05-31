#include "liblem.h"

static char	**ft_roomlen(char **m, char **s)
{
	int i;
	int cnt;
	int cnt2;
	char *t;

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
	i = -1;
	while (m[cnt2][++i] && m[cnt2][i] != ' ');
	cnt = i;
	i = -1;
	while (++i < 31)
	{
		if (!(s[i] = ft_strnew(71 + cnt)))
			return (NULL);
		ft_memset(s[i], ' ', 71 + cnt);
	}
	return (s);
}

static char	**ft_mapgenerator(char **m)
{
	char **r;
	int	i;

	i = -1;
	if (!(r = (char **)malloc(sizeof(char **) * (32))))
		return (NULL);
	r[431] = NULL;
	return (ft_roomlen(m, r));
}

char	**insertroom(t_hex *h, char **map)
{
	t_id *t;
	int	x;
	int	i;

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
	t_id *t;
	t_id *t2;
	int	i;
	int	j;

	t = h->id;
	while (t->next)
	{
		t2 = t->next;
		while (t2)
		{
			if (t->x < t2->x)
			{
				i = t->x + ft_strlen(t->n);
				j = t2->x;
			}
			else
			{
				i = t2->x + ft_strlen(t->n);
				j = t->x;
			}
			if (t->y == t2->y && i >= j)
				return (0);
			t2 = t2->next;
		}
		t = t->next;
	}
	return (1);
}

char	**ft_statichex(t_path *p, t_hex *h, char **m)
{
	char	**map;

	if (h->map->w > 10)
		return (NULL);
	if (!(map = ft_mapgenerator(m)))
		return (NULL);
//	ft_putid(h->id);
	if (!(h->id = ft_getaxis(h, m)))
		return (NULL);
	if (!(nonrepeat(h)))
		return (NULL);
	map = insertroom(h, map);
	map = ft_insertlink(h, map, m);
	return (map);
}
