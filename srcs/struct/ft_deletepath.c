#include "liblem.h"

void	ft_deletepath(t_path *p)
{
	t_path *t;
	int	i;

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
