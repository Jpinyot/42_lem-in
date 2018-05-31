#include "liblem.h"

void	ft_deletedstr(char **s)
{
	int i;

	i = -1;
	if (s)
	{
		while (s[++i])
			ft_strdel(&s[i]);
		free (s);
	}
}
