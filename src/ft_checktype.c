/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checktype.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvallie <lvallie@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 01:14:50 by lvallie           #+#    #+#             */
/*   Updated: 2021/05/13 00:15:42 by lvallie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ptf_checktype(t_type *flags, int *printed_chars, va_list ap)
{
	char	type;

	type = flags->type;
	if (type == '%')
		*printed_chars += ptf_formattochr('%', flags);
	if (type == 'c')
		*printed_chars += ptf_formattochr(va_arg(ap, int), flags);
	if (type == 's')
		*printed_chars += ptf_formattostr(va_arg(ap, char *), flags);
	if (type == 'p')
		*printed_chars += ptf_formattoptr(va_arg(ap, void *), flags);
	if (type == 'd' || type == 'i' || type == 'x' || type == 'X' || type == 'u')
		*printed_chars += ptf_formattoint(va_arg(ap, int), flags);
}
