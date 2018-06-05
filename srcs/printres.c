#include "liblem.h"

static int ft_move(t_path *bgn, int a)
{
	t_path *p;
	int i;
	int t;
	int t2;

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

static int lastants(t_path *bgn)
{
	t_path *p;
	int i;
	int t;
	int t2;

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

void printres(t_path *p, t_hex *h, char **map, int v)
{
	int a;
	int mov;
	char **m;

	mov = 1;
	a = 1;
	if (v == 0)
		ft_putinstruct(map);
	else if (v)
		v = ft_visual(p, h, map);
	if (v == 3)
		if (!(m = ft_statichex(p, h, map)))
			v = 2;
	while (a <= h->ants)
	{
		a = ft_move (p, a);
		if (v == 3)
			ft_putdmap(m);
		if (v == 2 || v == 3)
			ft_dynamicpath(p, mov);
		else
			ft_putres(p);
		mov++;
	}
	while (lastants(p))
	{
		if (v == 3)
			ft_putdmap(m);
		if (v == 2 || v == 3)
			ft_dynamicpath(p, mov);
		else
			ft_putres(p);
		mov++;
	}
	if (v == 3)
		ft_putdmap(m);
	if (v == 2 || v == 3)
		ft_staticpath(p);
	if (v == 3)
		ft_deletedstr(m);
}
