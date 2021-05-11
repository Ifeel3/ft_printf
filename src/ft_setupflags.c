/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setupflags.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvallie <lvallie@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 15:26:55 by lvallie           #+#    #+#             */
/*   Updated: 2021/05/11 22:24:58 by lvallie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_setupflags(char **string, t_type *flags, va_list ap)
{
	while (ft_isalpha(*(++(*string))) != 1 && **string != '%')
	{
		if (**string == '-')
			flags->minus = 1;
		if (**string == '0' && !ft_isdigit(*(*string - 1)))
			flags->nill = 1;
		if (**string == '.')
			flags->dot = 1;
		if (ft_isdigit(**string) && flags->dot != 1)
			flags->width = (flags->width * 10) + **string - 48;
		if (ft_isdigit(**string) && flags->dot == 1)
			flags->precision = (flags->precision * 10) + **string - 48;
		if (*(*string - 1) == '*' && flags->dot != 1)
			flags->width = va_arg(ap, int);
		if (*(*string + 1) == '*' && flags->dot == 1)
			flags->precision = va_arg(ap, int);
	}
	if (ft_strchr("cspdiuxX%", **string) == NULL)
		return (0);
	flags->type = **string;
	(*string)++;
	return (1);
}
