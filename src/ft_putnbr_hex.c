/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvallie <lvallie@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 14:00:46 by lvallie           #+#    #+#             */
/*   Updated: 2021/05/16 16:05:31 by lvallie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_putnbr_hex(unsigned int number, int type)
{
	if (number > 15)
		ft_putnbr_hex(number >> 4, type);
	if (type == 'x')
		write(1, &"0123456789abcdef"[number & 0x0F], 1);
	if (type == 'X')
		write(1, &"0123456789ABCDEF"[number & 0x0F], 1);
}
