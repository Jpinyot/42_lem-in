/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getaxis.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpinyot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 22:28:18 by jpinyot           #+#    #+#             */
/*   Updated: 2018/06/04 22:52:27 by jpinyot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "liblem.h"

static t_id	*strcmpid(char *s, t_id *id, int mx, int my)
{
	int		i;
	t_id	*t;

	t = id;
	i = -1;
	if (!(ft_strchr(s, ' ') || s[0] == ' '))
		return (id);
	while (s[++i] && id->n[i])
		if (s[i] != id->n[i])
			break ;
	if (s[i] != ' ' || id->n[i] != 0)
		return (id);
	if (mx)
		t->x = (ft_atoi(&s[i]) * 70) / mx;
	else
		t->x = 0;
	if (my)
		t->y = (ft_atoi(ft_strchr(&s[i + 1], ' ')) * 30) / my;
	else
		t->y = 0;
	return (id);
}

static int	getmaxy(char **m)
{
	int		i;
	int		cnt;
	char	*t;

	i = -1;
	cnt = 0;
	while (m[++i])
	{
		if (m[i][0] != '#' && (t = ft_strchr(m[i], ' ')))
		{
			t = ft_strchr(t + 1, ' ');
			if (ft_atoi(t) > cnt)
				cnt = ft_atoi(t);
		}
	}
	return (cnt);
}

static int	getmaxx(char **m)
{
	int		i;
	int		cnt;
	char	*t;

	i = -1;
	cnt = 0;
	while (m[++i])
	{
		if (m[i][0] != '#' && (t = ft_strchr(m[i], ' ')))
			if (ft_atoi(t) > cnt)
				cnt = ft_atoi(t);
	}
	return (cnt);
}

t_id		*ft_getaxis(t_hex *h, char **m)
{
	t_id	*t;
	int		i;
	int		my;
	int		mx;

	t = h->id;
	mx = getmaxx(m);
	my = getmaxy(m);
	while (t)
	{
		i = -1;
		while (t && t->n[0] == '#')
			t = t->next;
		if (!t)
			return (h->id);
		while (m[++i])
			t = strcmpid(m[i], t, mx, my);
		t = t->next;
	}
	return (h->id);
}
