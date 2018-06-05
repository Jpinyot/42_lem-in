#include "liblem.h"

static int	maplen(char **m)
{
	int i;
	int cnt;

	i = 0;
	cnt = 0;
	while (m[i])
	{
		if (ft_strchr(m[i], ' '))
			cnt++;
		i++;
	}
	return(cnt);
}

static int	anthunter(char **m)
{
	int a;
	int i;

	i = -1;
	while (m[++i] && m[i][0] == '#');
	if (!(ft_strchr(m[i], ' ')))
		if ((a = ft_atoi(m[i])) != 0)
			return (a);
	return (0);
}

t_hex		*getstruct(char **map)
{
	t_hex	*h;
	t_map	*m;
	t_id	*id;
	int	a;

	if ((a = anthunter(map)) == 0)
		ft_exit();
	if (!(m = ft_newmap(maplen(map))))
		ft_exit();
	if (!(id = ft_idgenerator(map)))
		ft_exit();
	if (!(h = ft_newhex(a, m, id)))
		ft_exit();
	return (h);
}
