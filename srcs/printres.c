/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printres.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpinyot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 20:05:32 by jpinyot           #+#    #+#             */
/*   Updated: 2018/07/01 17:52:26 by jpinyot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "liblem.h"

static int		finalvisual(int v, char **m, t_path *p, int mov)
{
	if (mov < 0)
	{
		if (v == 3)
			ft_putdmap(m);
		if (v == 2 || v == 3)
			ft_staticpath(p);
		if (v == 3)
			ft_deletedstr(m);
	}
	else
	{
		if (v == 3)
			ft_putdmap(m);
		if (v == 2 || v == 3)
			ft_dynamicpath(p, mov);
		else
			ft_putres(p);
		mov++;
	}
	return (mov);
}

static int		visualselect(int v, t_path *p, t_hex *h, char **map)
{
	if (v == 0)
		ft_putinstruct(map);
	else if (v)
		v = ft_visual(p, h, map);
	return (v);
}

void			printres(t_path *p, t_hex *h, char **map, int v)
{
	int		a;
	int		mov;
	char	**m;

	mov = 1;
	a = 1;
	v = visualselect(v, p, h, map);
	if (v == 3)
		if (!(m = ft_statichex(h, map)))
			v = 2;
	while (a <= h->ants)
	{
		a = ft_move(p, a);
		if (v == 3)
			ft_putdmap(m);
		if (v == 2 || v == 3)
			ft_dynamicpath(p, mov);
		else
			ft_putres(p);
		mov++;
	}
	while (lastants(p))
		mov = finalvisual(v, m, p, mov);
	finalvisual(v, m, p, -1);
}
