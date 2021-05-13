/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvallie <lvallie@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 14:00:46 by lvallie           #+#    #+#             */
/*   Updated: 2021/05/13 14:35:09 by lvallie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

size_t	ft_countnbr_hex(long long int number)
{
	size_t	counter;

	counter = 0;
	if (number < 0)
		number = -number;
	if (number > 16)
		counter = ft_countnbr_hex(number >> 4);
	return (counter + 1);
}

size_t	ft_putnbr_hex(unsigned long long int number, int type)
{
	size_t	counter;

	counter = 0;
	if (number > 16)
		counter = ft_putnbr_hex(number >> 4, type);
	if (type == 'x')
		write(1, &"0123456789abcdef"[number & 0x0F], 1);
	if (type == 'X')
		write(1, &"0123456789ABCDEF"[number & 0x0F], 1);
	return (counter + 1);
}