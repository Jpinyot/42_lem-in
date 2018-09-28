/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_visula.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpinyot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 18:26:45 by jpinyot           #+#    #+#             */
/*   Updated: 2018/09/28 20:36:00 by jpinyot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "liblem.h"

static int	ft_selector(void)
{
	char	b[4];
	char	n;
	int		i;

	n = 0;
	i = -1;
	while (++i < 4)
		b[i] = 0;
	i = read(1, b, 3);
	if (b[1] != 0)
		n = ft_atoi(b);
	ft_printf("\033[H\033[J");
	ft_putbanner();
	return (n);
}

static int	pathselector(t_path *p)
{
	int v;

	ft_printf("\n\n\t\t\x1b[31mSelect type:\x1b[0m\n");
	ft_printf("\t\t\t\x1b[91m1) Static\x1b[0m\n");
	ft_printf("\t\t\t\x1b[91m2) Dynamic\x1b[0m\n");
	if ((v = ft_selector()) == 1)
		ft_staticpath(p);
	if (v == 2)
		return (2);
	return (0);
}

static int	hexselector(t_hex *h, char **map)
{
	int		v;
	char	**d;

	ft_printf("\n\n\t\t\x1b[31mSelect type:\x1b[0m\n");
	ft_printf("\t\t\t\x1b[91m1) Static\x1b[0m\n");
	ft_printf("\t\t\t\x1b[91m2) Dynamic\x1b[0m\n");
	if ((v = ft_selector()) == 1)
	{
		if (!(d = ft_statichex(h, map)))
			return (0);
		ft_putdmap(d);
		ft_deletedstr(d);
	}
	if (v == 2)
		return (3);
	return (0);
}

static int	adminselector(t_path *p, t_hex *h, char **map, int v)
{
	char	**c;

	if (v == 11)
		ft_staticpath(p);
	if (v == 12)
		return (2);
	if (v == 22)
		return (3);
	if (v == 21)
	{
		if (!(c = ft_statichex(h, map)))
			return (0);
		ft_putdmap(c);
		ft_deletedstr(c);
	}
	if (v == 2)
		v = hexselector(h, map);
	if (v == 1)
		v = pathselector(p);
	return (v);
}

int			ft_visual(t_path *p, t_hex *h, char **map)
{
	int		v;

	v = 0;
	ft_printf("\033[H\033[J");
	ft_putbanner();
	ft_printf("\n\n\t\t\x1b[31mSelect visualitzation option:\x1b[0m\n");
	ft_printf("\t\t\t\x1b[91m1) Path\x1b[0m\n");
	ft_printf("\t\t\t\x1b[91m2) Hex\x1b[0m\n");
	ft_printf("\t\t\t\x1b[91m3) Non\x1b[0m\n");
	if ((v = ft_selector()) != 1 && v != 2 &&
			v != 12 && v != 11 && v != 21 && v != 22)
		return (0);
	return (adminselector(p, h, map, v));
}
