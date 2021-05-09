/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setupflags.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvallie <lvallie@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 15:26:55 by lvallie           #+#    #+#             */
/*   Updated: 2021/05/09 02:37:38 by lvallie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

int	ft_setupflags(char **string, t_type *flags, va_list ap)
{
	while (ft_isalpha(*(++(*string))) != 1)
	{
		if (**string == '-')
			flags->minus = 1;
		if (**string == '0')
			flags->nill = 1;
		if (**string == '.')
		{
			flags->dot = 1;
			if (ft_isdigit(*(*string - 1)) && *(*string - 1) != 0)
				flags->width = *(*string - 1) - 48;
			if (*(*string - 1) == '*')
				flags->width = va_arg(ap, int);
			if (ft_isdigit(*(*string + 1)))
				flags->precision = *(*string + 1) - 48;
			if (*(*string + 1) == '*')
				flags->precision = va_arg(ap, int);
		}
	}
	if (ft_strchr("cspdiuxX", **string) == NULL)
		return (0);
	flags->type = **string;
	(*string)++;
	return (1);
}
