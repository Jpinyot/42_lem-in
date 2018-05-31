#include "liblem.h"

void	ft_putinstruct(char **map)
{
	int i;

	i = -1;
	while (map[++i])
	{
			ft_putstr(map[i]);
			write(1, "\n", 1);
	}
	write(1, "\n", 1);
}

void	ft_putres(t_path *p)
{
	t_path *t;
	int	i;
	int	cnt;

	t = p;
	cnt = 0;
	while (t)
	{
		i = t->w;
		while (--i > 0)
		{
			if (t->a[i])
			{
				if (cnt == 1)
					write(1, " ", 1);
				cnt = 1;
				ft_printf("L%i-%s", t->a[i], t->path[i]);
			}
		}
		t = t->next;
	}
	write(1, "\n", 1);
}
