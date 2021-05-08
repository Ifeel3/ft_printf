/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvallie <lvallie@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 12:12:28 by lvallie           #+#    #+#             */
/*   Updated: 2021/05/08 16:04:46 by lvallie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

int	converter(char **string, va_list ap, int *printed_chars)
{
	t_type	flags;

	flags = malloc(sizeof(t_type));
	if (!flags)
		return (0);
	initflags(flags);
	setupflags(string, flags);
	return (1);
}