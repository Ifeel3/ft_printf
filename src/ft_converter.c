/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_converter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvallie <lvallie@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 12:12:28 by lvallie           #+#    #+#             */
/*   Updated: 2021/05/15 00:18:45 by lvallie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ptf_converter(char **string, va_list ap, int *printed_chars)
{
	t_type	*flags;

	flags = malloc(sizeof(t_type));
	if (!flags)
		return (0);
	if (!ptf_setupflags(string, flags, ap))
		return (0);
	if (flags->precision < 0)
	{
		flags->dot = 0;
		flags->precision = 0;
	}
	if (flags->width < 0)
	{
		flags->minus = 1;
		flags->width = -flags->width;
	}
	ptf_checktype(flags, printed_chars, ap);
	free(flags);
	return (1);
}
