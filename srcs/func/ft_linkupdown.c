#include "liblem.h"

static char **todown(t_id *down, t_id *up, char **m)
{
	int x;
	int y;

	x = down->x;
	y = down->y;
	while (m[++y] && (up->y - y) != (up->x - x))
		if (m[y][x] == ' ')
			 m[y][x] = '|';
	m[y][x] = '|';
	while (m[++y][x] && y != up->y)
		if (m[y][++x] == ' ')
			m[y][x] = '\\';
	return (m);
}

static char **toup(t_id *down, t_id *up, char **m)
{
	int x;
	int y;
	x = down->x;
	y = down->y;
	while (m[--y] && y != up->y)
		if (m[y][x] == ' ')
			m[y][x] = '|';
	while (m[y][++x] && x != up->x)
		if (m[y][x] == ' ')
			m[y][x] = '-';
	return (m);
}

char	**linktoup(t_id *down, t_id *up, char **m)
{
	int x;
	int y;

	x = down->x;
	y = down->y;
//	ft_putstr(down->n);
//	ft_putstr("-");
//	ft_putstr(up->n);
//	 if (up->x - down->x >= up->y - down->y)
//		 return (toup(down, up, m));
	while (--y > 0 && y > ((down->y - up->y) / 2) + up->y)
		if (m[y][++x] == ' ')
			m[y][x] = '/';
	while (m[y][++x] && x < up->x - (down->y - y))
		if (m[y][x] == ' ')
			m[y][x] = '-';
	while (m[--y][x] && y != up->y)
		if (m[y][++x] == ' ')
			m[y][x] = '/';
	return (m);
}

char    **linktodown(t_id *down, t_id *up, char **m)
{
	int x;
	int y;

	x = down->x;
	y = down->y;
	if (down->x - up->x >= down->y - up->y)
		return (todown(down, up, m));
	while (m[++y][x] && y < up->y - ((up->y - down->y) / 2))
		if (m[y][++x] == ' ')
			m[y][x] = '\\';
	 while (m[y][++x] && x < up->x - (y - down->y))
		 if (m[y][x] == ' ')
			 m[y][x] = '-';
	 while (m[++y][x] && y != up->y)
		 if (m[y][++x] == ' ')
			  m[y][x] = '\\';
	return (m);
}
