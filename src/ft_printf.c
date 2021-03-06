/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvallie <lvallie@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 21:18:59 by lvallie           #+#    #+#             */
/*   Updated: 2021/05/17 18:06:20 by lvallie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		printed_chars;
	char	*string;

	string = (char *)str;
	printed_chars = 0;
	va_start(ap, str);
	while (*string)
	{
		if (*string == '%')
		{
			if (!ft_converter(&string, ap, &printed_chars))
				return (-1);
		}
		else if (*string != '%')
		{
			write(1, string, 1);
			printed_chars++;
			string++;
		}
	}
	va_end(ap);
	return (printed_chars);
}
