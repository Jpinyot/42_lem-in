#include "liblem.h"

char	**getord(void)
{
	char	*line;
	char	**r;
	char	*s;
	char	*d;

	s = ft_strnew(1);
	while (get_next_line(0, &line) > 0)
	{
		d = s;
		if (!(s = ft_strjoin(s, line)))
			return (NULL);
		ft_strdel(&d);
		d = s;
		if (!(s = ft_strjoin(s, "\n")))
			return (NULL);
		ft_strdel(&d);
		ft_strdel(&line);
	}
	r = ft_strsplit(s, '\n');
	ft_strdel(&s);
	return (r);
}
