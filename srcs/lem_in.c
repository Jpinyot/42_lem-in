#include "liblem.h"

t_path	*lem_in(char **map, int v)
{
	t_hex	*h;
	t_path	*path;

	if (!(h = getstruct(map)))
		return (NULL);
	if (!(h = getlinks(h, map)))
		return (NULL);
	if (!(h = getpaths(h)))
		return (NULL);
	if (!(path = translate(h)))
		return (NULL);
	printres(path, h, map, v);
	ft_deletehex(h);
	return (path);
}
