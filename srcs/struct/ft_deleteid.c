#include "liblem.h"

void	ft_deleteid(t_id *id)
{
	t_id *t;

	if (id)
	{
		while (id)
		{
			t = id->next;
			ft_strdel(&id->n);
			free(id);
			id = t;
		}
	}
	id = NULL;
}
