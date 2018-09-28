/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_idgenerator.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpinyot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 19:43:19 by jpinyot           #+#    #+#             */
/*   Updated: 2018/09/26 17:40:00 by jpinyot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "liblem.h"

static int	checkval(char *m)
{
	char	*t;
	char	*t2;
	int		i;

	if (m[0] == '#')
		return (1);
	i = -1;
	if (!(t = ft_strchr(m, ' ')))
		return (0);
	if (!(t2 = ft_strchr(t + 1, ' ')))
		return (0);
	if (!t)
		return (0);
	while (t[++i])
		if (!(ft_isdigit(t[i])) && t[i] != ' ' && t[i] != '+' && t[i] != '-')
			return (0);
	return (1);
}

static t_id	*ft_split(char *map, int i)
{
	char	**s;
	t_id	*id;
	int		j;

	j = 0;
	if (!(checkval(map)))
		return (NULL);
	if (!(s = ft_strsplit(map, ' ')) || map[0] == 'L')
		return (NULL);
	if (s[0][0] != '#')
		if (ft_atoi_li(s[1]) == -1 || ft_atoi_li(s[2]) == -1)
			ft_exit();
	if (!(id = ft_newid(s[0], i)))
		return (NULL);
	while (s[++j])
		ft_strdel(&s[j]);
	free(s);
	return (id);
}

static t_id	*ft_bgnend(char **map, int x)
{
	t_id	*bgn;
	int		i;

	i = 0;
	if (x == 0)
		while (map[i] && ft_strcmp(map[i], "##start") != 0)
			i++;
	else
		while (map[i] && ft_strcmp(map[i], "##end") != 0)
			i++;
	while (map[++i] && map[i][0] == '#' && ft_strcmp(map[i], "##end")
			&& ft_strcmp(map[i], "##start"))
		if (map[i][0] != '#')
			break ;
	if (map[i] == NULL || ft_strcmp(map[i], "##end") == 0
			|| ft_strcmp(map[i], "##end") == 0)
		return (NULL);
	if (!(bgn = ft_split(map[i], x)))
		return (NULL);
	return (bgn);
}

static int	nonrepeat(t_id *bgn)
{
	t_id *t;
	t_id *t2;

	t = bgn;
	while (t->next)
	{
		t2 = t->next;
		while (t2)
		{
			if (t->n[0] != '#' && t2->n[0] != '#'
					&& ft_strcmp(t->n, t2->n) == 0)
				return (0);
			t2 = t2->next;
		}
		t = t->next;
	}
	return (1);
}

t_id		*ft_idgenerator(char **map, int i, int cnt)
{
	t_id	*id;
	t_id	*bgn;

	if (!(id = ft_bgnend(map, 0)))
		ft_exit();
	bgn = id;
	while (map[++i])
	{
		if (map[i][0] == 'L' || (map[i][0] != '#' &&
					(!(ft_strchr(map[i], ' ')) && !(ft_strchr(map[i], '-')))))
			ft_exit();
		if (ft_strchr(map[i], ' '))
		{
			if (!(id->next = ft_split(map[i], cnt++)))
				ft_exit();
			id = id->next;
		}
		else if (ft_strcmp(map[i], "##start") == 0 ||
				ft_strcmp(map[i], "##end") == 0)
			while (map[i][0] == '#')
				i++;
	}
	if (!(id->next = ft_bgnend(map, cnt)) || nonrepeat(bgn) == 0)
		ft_exit();
	return (bgn);
}
