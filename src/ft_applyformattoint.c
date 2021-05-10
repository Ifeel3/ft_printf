/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_applyformattoint.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvallie <lvallie@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 13:24:30 by lvallie           #+#    #+#             */
/*   Updated: 2021/05/10 13:24:30 by lvallie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

int	ft_applyformattoint(int number, t_type *flags)
{
	char *string;

	(void) flags;
	string = ft_itoa(number);
	write(1, string, ft_strlen(string));
	return ((int)ft_strlen(string));
}