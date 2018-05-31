#include "liblem.h"

void	ft_deletemap(t_map *m)
{
	int i;

	i = -1;
	if (m)
	{
		if (m->map)
		{
			if (m->w > 0)
				while(++i < m->w)
					free(m->map[i]);
			free (m->map);
		}
		free (m);
		m = NULL;
	}
}
