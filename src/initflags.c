/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initflags.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvallie <lvallie@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 22:34:44 by lvallie           #+#    #+#             */
/*   Updated: 2021/05/07 22:41:39 by lvallie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

void	initflags(t_type flags)
{
	flags.minus = 0;
	flags.dot = 0;
	flags.nill = 0;
	flags.precision = 0;
	flags.width = 0;
	flags.type = 0;
}
