/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_converter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvallie <lvallie@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 12:12:28 by lvallie           #+#    #+#             */
/*   Updated: 2021/05/11 15:07:54 by lvallie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_converter(char **string, va_list ap, int *printed_chars)
{
	t_type	*flags;

	flags = malloc(sizeof(t_type));
	if (!flags)
		return (0);
	ft_initflags(flags);
	if (!ft_setupflags(string, flags, ap))
		return (0);
	ft_checktype(flags, printed_chars, ap);
	free(flags);
	return (1);
}
