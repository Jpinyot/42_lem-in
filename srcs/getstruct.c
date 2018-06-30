/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getstruct.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpinyot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 20:02:02 by jpinyot           #+#    #+#             */
/*   Updated: 2018/07/01 00:23:28 by jpinyot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "liblem.h"

static int	maplen(char **m, int j)
{
	int i;
	int cnt;

	i = j;
	cnt = 0;
	while (m[i])
	{
		if (ft_strchr(m[i], ' '))
			cnt++;
		i++;
	}
	return (cnt);
}

static int	anthunter(char **m)
{
	int a;
	int i;

	i = 0;
	while (m[i] && m[i][0] == '#')
		i++;
	if (!(m[i]))
		return (0);
	if (!(ft_strchr(m[i], ' ')))
		if ((ft_atoi_li(m[i]) != -1) && (a = ft_atoi(m[i])) != 0)
			return (a);
	return (0);
}

static int	searchpos(char **m)
{
	int i;
	int j;
	int cnt;
	int cnt2;

	i = 0;
	j = -1;
	cnt = 0;
	cnt2 = 0;
	while (m[i] && m[i][0] == '#')
		i++;
	while (m[++j])
	{
		if (ft_strcmp(m[j], "##start") == 0)
			cnt++;
		if (ft_strcmp(m[j], "##end") == 0)
			cnt2++;
	}
	if (cnt != 1 || cnt2 != 1)
		return (-1);
	return (i);
}

t_hex		*getstruct(char **map)
{
	t_hex	*h;
	t_map	*m;
	t_id	*id;
	int		a;
	int		i;

	if ((a = anthunter(map)) == 0)
		ft_exit();
	if ((i = searchpos(map)) == -1)
		ft_exit();
	if (!(m = ft_newmap(maplen(map, i))))
		ft_exit();
	if (!(id = ft_idgenerator(map, i)))
		ft_exit();
	if (!(h = ft_newhex(a, m, id)))
		ft_exit();
	return (h);
}
