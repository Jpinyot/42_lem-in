#include "liblem.h"

static int **reppath(int **m, int l, int x)
{
	int i;
	int cnt;

	i = 0;
	cnt = m[x][l];
	while (i < l - 1)
	{
		if (m[x][i] && (m[i][l] == 0 || m[i][l] > cnt))
		{
			m[i][l] = cnt + 1;
			m = reppath(m, l, i);
		}
		i++;
	}
	return (m);
}

t_map	*ft_mindistance(t_map *m)
{
	int **t;
	int i;

	i = 0;
	while (i < m->w - 1)
	{
		if (m->map[m->w - 1][i])
			m->map = reppath(m->map, m->w - 1, i);
		i++;
	}
	return (m);
}
