/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_converter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvallie <lvallie@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 12:12:28 by lvallie           #+#    #+#             */
/*   Updated: 2021/05/08 23:29:36 by lvallie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

int	ft_converter(char **string, va_list ap, int *printed_chars)
{
	t_type	*flags;

	if (printpercent(&(*string), printed_chars))
		return (1);
	flags = malloc(sizeof(t_type));
	if (!flags)
		return (0);
	ft_initflags(flags);
	if (!setupflags(string, flags, ap))
		return (0);

	return (1);
}
