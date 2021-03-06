/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checktype.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvallie <lvallie@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 01:14:50 by lvallie           #+#    #+#             */
/*   Updated: 2021/05/14 19:49:35 by lvallie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_checktype(t_type *flags, int *printed_chars, va_list ap)
{
	char	type;

	type = flags->type;
	if (type == '%')
		*printed_chars += ft_formattochr('%', flags);
	if (type == 'c')
		*printed_chars += ft_formattochr(va_arg(ap, int), flags);
	if (type == 's')
		*printed_chars += ft_formattostr(va_arg(ap, char *), flags);
	if (type == 'p')
		*printed_chars += ft_formattoptr(va_arg(ap, void *), flags);
	if (type == 'd' || type == 'i')
		*printed_chars += ft_formattoint(va_arg(ap, int), flags);
	if (type == 'x' || type == 'X')
		*printed_chars += ft_formattohex(va_arg(ap, int), flags);
	if (type == 'u')
		*printed_chars += ft_formattoint(va_arg(ap, unsigned int), flags);
}
