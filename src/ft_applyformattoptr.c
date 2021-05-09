/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_applyformattoptr.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvallie <lvallie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 01:55:16 by lvallie           #+#    #+#             */
/*   Updated: 2021/05/09 02:17:56 by lvallie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

int	ft_applyformattoptr(void *ptr, t_type *flags)
{
	char *string;

	(void) flags;
	string = ft_convertpointertohex(ptr);
	write(1, "0x", 2);
	write(1, string, ft_strlen(string));
	return ((int)ft_strlen(string) + 2);
}