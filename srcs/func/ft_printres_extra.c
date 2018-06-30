/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printres_extra.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpinyot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/29 20:05:54 by jpinyot           #+#    #+#             */
/*   Updated: 2018/06/30 16:52:15 by jpinyot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "liblem.h"

static t_path	*ft_move_s(t_path *p)
{
	int		i;
	int		t;
	int		t2;

	i = 0;
	t = p->a[1];
	while (++i < p->w - 1)
	{
		t2 = p->a[i + 1];
		p->a[i + 1] = t;
		t = t2;
	}
	return (p);
}

int				ft_move(t_path *bgn, int a)
{
	t_path	*p;

	p = bgn;
	while (p)
	{
		p = ft_move_s(p);
		if (p->ants)
		{
			p->a[1] = a;
			p->ants -= 1;
			a++;
		}
		else
			p->a[1] = 0;
		p = p->next;
	}
	return (a);
}

static int		lastants_s(t_path *bgn)
{
	t_path	*p;
	int		i;

	p = bgn;
	while (p)
	{
		i = -1;
		while (++i < p->w)
			if (p->a[i])
				return (1);
		p = p->next;
	}
	return (0);
}

int				lastants(t_path *bgn)
{
	t_path	*p;
	int		i;
	int		t;
	int		t2;

	p = bgn;
	while (p)
	{
		i = 0;
		t = p->a[1];
		while (++i < p->w - 1)
		{
			t2 = p->a[i + 1];
			p->a[i + 1] = t;
			t = t2;
		}
		p->ants = 0;
		p->a[1] = 0;
		p = p->next;
	}
	return (lastants_s(bgn));
}
