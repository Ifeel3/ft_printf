/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checktype.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvallie <lvallie@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 01:14:50 by lvallie           #+#    #+#             */
/*   Updated: 2021/05/11 20:37:10 by lvallie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ptf_checktype(t_type *flags, int *printed_chars, va_list ap)
{
	char	type;

	type = flags->type;
	if (type == 'c')
		*printed_chars += ptf_formattochr(va_arg(ap, int), flags);
	if (type == '%')
		*printed_chars += ptf_formattochr('%', flags);
	if (type == 's')
		*printed_chars += ptf_formattostr(va_arg(ap, char *), flags);
	if (type == 'p')
		*printed_chars += ptf_formattoptr(va_arg(ap, void *), flags);
	if (type == 'd' || type == 'i')
		*printed_chars += ptf_formattoint(va_arg(ap, int), flags);
	if (type == 'x' || type == 'X')
		*printed_chars += ptf_formattohex(va_arg(ap, int), flags, type);
	if (type == 'u')
		*printed_chars += ptf_formattouint(va_arg(ap, unsigned int), flags);
}
