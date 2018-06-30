/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_nd_clear.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpinyot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 19:34:29 by jpinyot           #+#    #+#             */
/*   Updated: 2018/06/30 23:12:05 by jpinyot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
