/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_applyformattostr.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvallie <lvallie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 13:33:40 by lvallie           #+#    #+#             */
/*   Updated: 2021/05/11 14:38:49 by lvallie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

int	ft_applyformattostr(char *string, t_type *flags)
{
	size_t	precision;
	size_t	width;
	size_t	tmp;

	if (flags->dot == 0)
		precision = ft_strlen(string);
	else
	{
		if (flags->precision > ft_strlen(string))
			precision = ft_strlen(string);
		else
			precision = flags->precision;
	}
	if (flags->width > precision)
		width = flags->width;
	else
		width = precision;
	if (flags->minus == 1)
		write(1, string, precision);
	tmp = width;
	while (tmp-- > precision)
		write(1, " ", 1);
	if (flags->minus == 0)
		write(1, string, precision);
	return ((int)width);
}
