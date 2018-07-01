/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mindistance.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpinyot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 22:32:17 by jpinyot           #+#    #+#             */
/*   Updated: 2018/07/01 17:56:21 by jpinyot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "liblem.h"

static int	**reppath(int **m, int l, int x)
{
	int i;
	int cnt;

	i = 0;
	cnt = m[x][l];
	while (i < l - 1)
	{
		if (m[x][i] && (m[i][l] == 0 || m[i][l] > cnt))
		{
			m[i][l] = cnt + 1;
			m = reppath(m, l, i);
		}
		i++;
	}
	return (m);
}

t_map		*ft_mindistance(t_map *m)
{
	int i;

	i = 0;
	while (i < m->w - 1)
	{
		if (m->map[m->w - 1][i])
			m->map = reppath(m->map, m->w - 1, i);
		i++;
	}
	return (m);
}
