#include "liblem.h"

t_hex	*ft_newhex(int a, t_map *m, t_id *id)
{
	t_hex *h;

	if (!(h = (t_hex *)malloc(sizeof(t_hex))))
		return (NULL);
	h->ants = a;
	if (m)
		h->map = m;
	else
		h->map = NULL;
	if (id)
		h->id = id;
	else
		h->id = NULL;
	h->path = NULL;
	h->w = 0;
	return (h);
}

t_map	*ft_newmap(int w)
{
	t_map	*m;
	int	i;
	int	j;

	i = -1;
	if (!(m = (t_map *)malloc(sizeof(t_map))))
		return (NULL);
	if (!(m->map = (int **)malloc(sizeof(int **) * w)))
		return (NULL);
	while (++i < w)
	{
		if (!(m->map[i] = (int *)malloc(sizeof(int *) * w)))
			return (NULL);
		j = -1;
		while (++j < w)
			m->map[i][j] = 0;
	}
	m->w = w; 
	return (m);
}

t_id	*ft_newid(char *n, int i)
{	
	t_id *id;

	if (!(id = (t_id *)malloc(sizeof(t_id))))
		return (NULL);
	id->next = NULL;
	if (n == NULL)
		return (NULL);
	id->id = i;
	id->n = n;
	id->x = -1;
	id->y = -1;
	return (id);
}

t_path	*ft_newpath(int w)
{
	t_path	*p;
	int	i;

	i = -1;
	if (!(p = (t_path *)malloc(sizeof(t_path))))
		return (NULL);
	if (!(p->path = (char **)malloc(sizeof(char **) * (w + 1))))
		return (NULL);
	if (!(p->a = (int *)malloc(sizeof(int *) * w)))
		return (NULL);
	while (++i < w)
		p->a[i] = 0;
	p->path[w] = NULL;
	p->cost = w - 1;
	p->w = w;
	p->ants = 0;
	p->next = NULL;
	return (p);
}
