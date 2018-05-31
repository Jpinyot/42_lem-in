#include "liblem.h"

void ft_dynamicpath(t_path *p, int m)
{
	t_path *t;
	int i;

	t = p;
	write(1, "\n\n", 1);
	while (t)
	{
		i = 0;
		if (t->ants)
			ft_printf("\t\x1b[31m{%s}\x1b[0m->", t->path[0]);
		else
			ft_printf("\t\x1b[92m{%s}\x1b[0m->", t->path[0]);
		while (t->path[++i + 1])
		{
			if (t->a[i])
				ft_printf("\x1b[96m[<L%i>]\x1b[0m->", t->a[i]);
			else
				ft_printf("\x1b[97m[%s]\x1b[0m->", t->path[i]);
		}
		if (t->a[i])
				ft_printf("\x1b[96m{<L%i>}\x1b[0m\n", t->a[i]);
		else
			ft_printf("\x1b[97m{%s}\x1b[0m\n", t->path[i]);
		ft_printf("\t\x1b[90m<ants to pass: %i>\x1b[0m\n", t->ants);
		t = t->next;
	}
	write (1, "\n", 1);
	ft_printf("\t\x1b[36mCURRENT COST: %i\x1b[0m\n", m);
	ft_putres(p);
	ft_read_nd_clear();

}
