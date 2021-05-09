/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_applyformattohex.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvallie <lvallie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 02:45:30 by lvallie           #+#    #+#             */
/*   Updated: 2021/05/09 04:00:36 by lvallie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

int	ft_applyformattohex(int number, t_type *flags, char format)
{
	char *string;

	(void) flags;
	(void) format;
	string = ft_convertinttohex(number);
	write(1, string, ft_strlen(string));
	return ((int)ft_strlen(string));
}