/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   antdist.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpinyot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 19:55:01 by jpinyot           #+#    #+#             */
/*   Updated: 2018/11/13 18:11:28 by jpinyot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "liblem.h"

static t_path	*ft_pathlen(t_path *p, int ants)
{
	int		l;
	int		div;
	t_path	*t;

	l = 0;
	t = p;
	while (t)
	{
		t = t->next;
		l++;
	}
	t = p;
	div = ants / l;
	t->ants = div + (ants % l);
	t->cost += t->ants - 1;
	while (t->next)
	{
		t->next->ants = div;
		t->next->cost += t->next->ants - 1;
		t = t->next;
	}
	return (p);
}

static t_path	*minmaxcost(t_path *p, int sel)
{
	t_path	*r;
	t_path	*t;

	if (!(p->next))
		return (NULL);
	r = p;
	t = p;
	while (t)
	{
		if (sel && t->ants > 0 && t->cost < r->cost)
			r = t;
		else if (sel == 0 && t->ants > 0 && t->cost > r->cost)
			r = t;
		t = t->next;
	}
	return (r);
}

static t_path	*sortants(t_path *p)
{
	t_path	*min;
	t_path	*max;
	int		a;

	if (!(min = minmaxcost(p, 1)))
		return (p);
	if (!(max = minmaxcost(p, 0)))
		return (p);
	a = (max->cost - min->cost) / 2;
	if (max->cost > min->cost + 1)
	{
		min->ants += a;
		max->ants -= a;
		min->cost += a;
		max->cost -= a;
		ft_putchar('\n');
		return (sortants(p));
	}
	return (p);
}

t_path			*antdist(t_hex *h, t_path *p)
{
	p = ft_pathlen(p, h->ants);
	p = sortants(p);
	return (p);
}
