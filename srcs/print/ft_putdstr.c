/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putdstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpinyot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 18:23:38 by jpinyot           #+#    #+#             */
/*   Updated: 2018/06/05 18:26:38 by jpinyot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "liblem.h"

void		ft_putdstr(char **s)
{
	int i;
	int j;

	i = -1;
	while (s[++i])
	{
		j = -1;
		while (s[i][++j])
		{
			if (s[i][j] != ' ')
			{
				ft_printf("\x1b[97m%s\x1b[0m", s[i]);
				write(1, "\n", 1);
				break ;
			}
		}
	}
}

static int	jumpspace(char **s)
{
	int i;
	int j;

	i = -1;
	while (s[++i])
	{
		j = -1;
		while (s[i][++j])
			if (s[i][j] != ' ')
				break ;
		if (s[i][j])
			break ;
	}
	i -= 1;
	return (i);
}

void		ft_putdmap(char **s)
{
	int i;
	int j;

	i = jumpspace(s);
	while (s[++i])
	{
		j = -1;
		while (s[i][++j])
		{
			if (s[i][j] != ' ' && s[i][j] != '-' &&
					s[i][j] != '|' && s[i][j] != '/' && s[i][j] != '\\')
				ft_printf("\x1b[92m%c\x1b[0m", s[i][j]);
			else
				ft_printf("\x1b[96m%c\x1b[0m", s[i][j]);
		}
		ft_putchar('\n');
	}
}
