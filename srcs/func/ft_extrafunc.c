/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extrafunc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpinyot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/29 16:12:06 by jpinyot           #+#    #+#             */
/*   Updated: 2018/06/29 16:33:13 by jpinyot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "liblem.h"

t_hex	*intmalloc(t_hex *h)
{
	int i;
	int j;
	int cnt;

	cnt = 0;
	i = -1;
	while (i++ < h->map->w - 1)
		if (h->map->map[0][i] == 1)
			cnt++;
	if (!cnt)
		return (NULL);
	if (!(h->path = (int **)malloc(sizeof(int **) * cnt)))
		return (NULL);
	i = -1;
	h->w = cnt;
	while (++i < cnt)
	{
		if (!(h->path[i] = (int *)malloc(sizeof(int *) * (h->map->w))))
			return (NULL);
		j = -1;
		while (++j < h->map->w)
			h->path[i][j] = -1;
	}
	return (h);
}
