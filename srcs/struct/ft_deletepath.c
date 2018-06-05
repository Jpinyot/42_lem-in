/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deletepath.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpinyot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 17:38:30 by jpinyot           #+#    #+#             */
/*   Updated: 2018/06/05 17:38:43 by jpinyot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "liblem.h"

void	ft_deletepath(t_path *p)
{
	t_path	*t;
	int		i;

	if (p)
	{
		while (p)
		{
			t = p;
			p = p->next;
			i = -1;
			while (t->path[++i])
				free(t->path[i]);
			if (t->path)
				free(t->path);
			if (t->a)
				free(t->a);
			free(t);
		}
		p = NULL;
	}
}
