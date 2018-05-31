 #include "liblem.h"

void	ft_read_nd_clear(void)
{
	char *b;

	b = NULL;
	while (read(1, b, 1) == 0)
	{
		if (b != NULL)
		{
			ft_strdel(&b);
			break ;
		}
	}
	ft_printf("\033[H\033[J");
	ft_putbanner();
}
