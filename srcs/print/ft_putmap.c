/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpinyot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 18:39:52 by jpinyot           #+#    #+#             */
/*   Updated: 2018/06/05 18:40:15 by jpinyot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "liblem.h"

void	ft_puttmap(t_map *m)
{
	t_map	*t;
	int		i;
	int		j;

	i = -1;
	if (m == NULL)
	{
		write(1, "NULL", 4);
		write(1, "\n", 1);
	}
	t = m;
	while (++i < m->w)
	{
		j = -1;
		while (++j < m->w)
		{
			ft_putnbr(m->map[i][j]);
			write(1, "  ", 2);
		}
		write(1, "\n", 1);
	}
	ft_putnbr(m->w);
	write(1, "\n", 1);
	write(1, "\n", 1);
}

void	ft_putfinal(t_path *p)
{
	t_path	*t;
	int		i;

	if (t == NULL)
		write(1, "NULL\n", 5);
	t = p;
	while (t)
	{
		i = -1;
		while (t->path[++i])
		{
			ft_putstr(t->path[i]);
			ft_putchar('<');
			ft_putnbr(t->a[i]);
			ft_putchar('>');
			write(1, "  ", 2);
		}
		ft_printf("\n%i<%i>\n", t->ants, t->cost);
		t = t->next;
	}
	write(1, "\n", 1);
	write(1, "\n", 1);
}

void	ft_putpath(t_hex *h)
{
	t_hex	*t;
	int		i;
	int		j;

	i = -1;
	if (h->path == NULL)
	{
		write(1, "NULL", 4);
		write(1, "\n", 1);
	}
	t = h;
	while (++i < h->w)
	{
		j = -1;
		write(1, "->", 2);
		while (++j < h->map->w && h->path[i][j] != -1)
		{
			ft_putnbr(h->path[i][j]);
			write(1, "  ", 2);
		}
		write(1, "\n", 1);
	}
	ft_putnbr(h->w);
	write(1, "\n", 1);
	write(1, "\n", 1);
}

void	ft_putid(t_id *id)
{
	t_id *t;

	t = id;
	while (t)
	{
		ft_putstr(t->n);
		write(1, "<", 1);
		ft_putnbr(t->x);
		write(1, ">", 1);
		write(1, "<", 1);
		ft_putnbr(t->y);
		write(1, ">\n", 2);
		t = t->next;
	}
}
