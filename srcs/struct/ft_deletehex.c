/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deletehex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpinyot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 17:38:56 by jpinyot           #+#    #+#             */
/*   Updated: 2018/06/05 17:39:04 by jpinyot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "liblem.h"

void	ft_deletehex(t_hex *h)
{
	int i;

	i = -1;
	if (h)
	{
		if (h->map)
			ft_deletemap(h->map);
		h->map = NULL;
		if (h->id)
			ft_deleteid(h->id);
		h->id = NULL;
		if (h->path)
		{
			while (++i < h->w)
				free(h->path[i]);
			free(h->path);
		}
		if (h)
			free(h);
		h = NULL;
	}
}
