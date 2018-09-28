/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpinyot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 20:04:30 by jpinyot           #+#    #+#             */
/*   Updated: 2018/09/28 16:06:14 by jpinyot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "liblem.h"

int	main(int ac, char **av)
{
	char	**map;
	int		v;
	t_path	*path;

	v = 0;
	if (ac > 1)
		if (ft_strcmp(av[1], "-v") == 0)
			v = 1;
	if (!(map = getord()))
		return (-1);
	if (!(path = lem_in(map, v)))
		return (-1);
	ft_deletepath(path);
	ft_deletedstr(map);
	return (0);
}
