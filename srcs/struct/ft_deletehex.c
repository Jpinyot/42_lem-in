#include "liblem.h"

void	ft_deletehex(t_hex *h)
{
	int i;

	i = -1;
	if (h)
	{
		if (h->map)
			ft_deletemap(h->map);
		h->map = NULL;
		if (h->id)
			ft_deleteid(h->id);
		h->id = NULL;
		if (h->path)
		{
			while (++i < h->w)
				free(h->path[i]);
			free(h->path);
		}
		if (h)
			free(h);
		h = NULL;
	}
}
