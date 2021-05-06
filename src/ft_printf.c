/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvallie <lvallie@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 21:18:59 by lvallie           #+#    #+#             */
/*   Updated: 2021/05/06 23:44:26 by lvallie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include "../includes/libftprintf.h"

int	ft_printf(char const *string, ...)
{
	va_list	ap;
	int		printed_chars;

	printed_chars = 0;
	va_start(ap, string);
	while (*string)
	{
		if (*string == '%')
			;//percent_check(&string, ap, &printed_chars);
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
