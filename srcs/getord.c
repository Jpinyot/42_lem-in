/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getord.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpinyot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 19:56:15 by jpinyot           #+#    #+#             */
/*   Updated: 2018/09/29 22:27:59 by jpinyot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "liblem.h"

char	**getord(void)
{
	char	*line;
	char	**r;
	char	*s;
	char	*d;

	if (!(s = ft_strnew(1)))
		exit(-1);
	while (get_next_line(0, &line) > 0)
	{
		d = s;
		if (line[0] == 0 || !(s = ft_strjoin(s, line)))
			ft_exit();
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
