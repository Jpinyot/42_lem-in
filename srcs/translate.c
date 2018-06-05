#include "liblem.h"

static int	pathlen(t_hex *h)
{
	int i;

	i = 0;
	while (i < h->w)
	{
		if (h->path[i][0] < 0)
			return (i);
		i++;
	}
	return (i);
}

static char	*copyid(t_hex *h, int i, int j)
{
	t_id	*t;
	char	*r;

	t = h->id;
	while (t->id != h->path[i][j])
		t = t->next;
	if (!(r = ft_strnew(ft_strlen(t->n))))
		return (NULL);
	r = ft_strcpy(r, t->n);
	return (r);
}

static t_path	*copypath(t_hex *h, int i)
{
	t_path *p;
	int	j;
	int	x;

	j = -1;
	x = -1;
	while (++j < h->map->w)
		if (h->path[i][j] < 0)
			break ;
	if (!(p = ft_newpath(j)))
		return (NULL);
	while (++x < j)
		if (!(p->path[x] = copyid(h, i, x)))
			return (NULL);
	return (p);
}

t_path	*translate(t_hex *h)
{
	t_path	*p;
	t_path	*bgn;
	int	i;
	int	l;

	l = pathlen(h);
	i = 0;
	if  (!(p = copypath(h, 0)))
		ft_exit();
//		return (NULL);
	bgn = p;
	while (++i < l)
	{
		if (h->path[i][0] < 0)
			break ;
		if (!(p->next = copypath(h, i)))
			ft_exit();
//			return (NULL);
		p = p->next;
	}
	return (antdist(h ,bgn));
}
