/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getord.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpinyot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 19:56:15 by jpinyot           #+#    #+#             */
/*   Updated: 2018/09/26 15:32:45 by jpinyot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		if (line[0] == 0)
			ft_exit();
		d = s;
		if (!(s = ft_strjoin(s, line)))
			exit(-1);
		ft_strdel(&d);
		d = s;
		if (!(s = ft_strjoin(s, "\n")))
			exit(-1);
		ft_strdel(&d);
		ft_strdel(&line);
	}
	if (s[0] == 0)
		ft_exit();
	r = ft_strsplit(s, '\n');
	ft_strdel(&s);
	return (r);
}
