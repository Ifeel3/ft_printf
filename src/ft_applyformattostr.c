/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_applyformattostr.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvallie <lvallie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 13:33:40 by lvallie           #+#    #+#             */
/*   Updated: 2021/05/10 13:33:40 by lvallie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

int	ft_applyformattostr(char *string, t_type *flags)
{
	(void) flags;
	write(1, string, ft_strlen(string));
	return ((int)ft_strlen(string));
}