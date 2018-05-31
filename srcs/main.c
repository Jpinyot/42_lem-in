#include "liblem.h"

int	main(int ac, char **av)
{
	char **map;
	int	v;
	t_path *path;

	v = 0;
	if (ac > 1)
		v = 1;
	if (!(map = getord()))
		return (-1);
	if (!(path = lem_in(map, v)))
	{
//		ft_putstr_fd("ERROR", 2);
		return (-1);
	}
	ft_deletepath(path);
	ft_deletedstr(map);
	return (0);
}
