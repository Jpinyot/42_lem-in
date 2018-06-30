/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpinyot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 20:04:16 by jpinyot           #+#    #+#             */
/*   Updated: 2018/07/01 00:16:27 by jpinyot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "liblem.h"

t_path	*lem_in(char **map, int v)
{
	t_hex	*h;
	t_path	*path;

	if (!(h = getstruct(map)))
		return (NULL);
	if (!(h = getlinks(h, map)))
		return (NULL);
	if (!(h = getpaths(h)))
		return (NULL);
	if (!(path = translate(h)))
		return (NULL);
	printres(path, h, map, v);
	ft_deletehex(h);
	return (path);
}
