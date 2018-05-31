#include "liblem.h"


static int	ft_selector(void)
{
	char *b;
	char n;

	b = NULL;
	n = 0;
	get_next_line(1, &b);
	if (b != NULL)
	{
		n = ft_atoi(b);
		ft_strdel(&b);
	}

	ft_printf("\033[H\033[J");
	ft_putbanner();
	return(n);
}

static int	pathselector(t_path *p, t_hex *h)
{
	int v;

	ft_printf("\n\n\t\t\x1b[31mSelect type:\x1b[0m\n");
	ft_printf("\t\t\t\x1b[91m1) Static\x1b[0m\n");
	ft_printf("\t\t\t\x1b[91m2) Dynamic\x1b[0m\n");
	if ((v = ft_selector()) == 1)
		ft_staticpath(p);
	if (v == 2)
		return (2);
	return (0);
}

static int	hexselector(t_path *p, t_hex *h, char **map)
{
	int v;
	char **d;

	ft_printf("\n\n\t\t\x1b[31mSelect type:\x1b[0m\n");
	ft_printf("\t\t\t\x1b[91m1) Static\x1b[0m\n");
	ft_printf("\t\t\t\x1b[91m2) Dynamic\x1b[0m\n");
	if ((v = ft_selector()) == 1)
	{
		d = ft_statichex(p, h, map);
		ft_putdmap(d);
		ft_deletedstr(d);
	}
	if (v == 2)
		return (3);
	return (0);
}

int	ft_visual(t_path *p, t_hex *h, char **map)
{
	int v;
	char **c;

	v = 0;
	ft_printf("\033[H\033[J");
	ft_putbanner();
	ft_printf("\n\n\t\t\x1b[31mSelect visualitzation option:\x1b[0m\n");
	ft_printf("\t\t\t\x1b[91m1) Path\x1b[0m\n");
	ft_printf("\t\t\t\x1b[91m2) Hex\x1b[0m\n");
	ft_printf("\t\t\t\x1b[91m3) Non\x1b[0m\n");
	if ((v = ft_selector()) != 1 && v != 2 && v != 12 && v != 11 && v != 21 && v != 22)
		return (0);
	if (v == 11)
		ft_staticpath(p);
	if (v == 12)
		return (2);
	if (v == 22)
		return (3);
	if (v == 21)
	{
		c = ft_statichex(p, h, map);
		ft_putdmap(c);
		ft_deletedstr(c);
	}
	if (v == 2)
		v = hexselector(p, h, map);
	if (v == 1)
		v = pathselector(p, h);
	return (v);
}
