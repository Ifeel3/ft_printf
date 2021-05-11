/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_applyformattochr.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvallie <lvallie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 13:33:40 by lvallie           #+#    #+#             */
/*   Updated: 2021/05/11 19:49:48 by lvallie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

int	ft_applyformattochr(int c, t_type *flags)
{
	size_t	width;
	size_t	tmplen;
	char	chr;

	if (flags->width > 1)
		width = flags->width;
	else
		width = 1;
	tmplen = width;
	if (width > 1)
	{
		if (flags->nill == 1 && flags->minus != 1)
			chr = '0';
		else
			chr = ' ';
	}
	if (flags->minus == 1)
		write(1, &c, 1);
	while (tmplen-- > 1)
		write(1, &chr, 1);
	if (flags->minus != 1)
		write(1, &c, 1);
	return ((int)width);
}
