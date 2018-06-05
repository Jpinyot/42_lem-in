/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_staticpath.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpinyot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 17:59:14 by jpinyot           #+#    #+#             */
/*   Updated: 2018/06/05 17:59:38 by jpinyot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "liblem.h"

void	ft_staticpath(t_path *p)
{
	t_path	*t;
	int		i;

	t = p;
	write(1, "\n\n", 1);
	while (t)
	{
		i = 0;
		ft_printf("\t\x1b[92m{%s}\x1b[0m->", t->path[0]);
		while (t->path[++i + 1])
		{
			ft_printf("\x1b[97m[%s]\x1b[0m->", t->path[i]);
		}
		ft_printf("\x1b[91m{%s}\x1b[0m\n", t->path[i]);
		ft_printf("\t\x1b[90m<cost: %i>\x1b[0m\n", i);
		t = t->next;
	}
	write(1, "\n\n", 1);
}
