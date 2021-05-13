/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_dec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvallie <lvallie@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 14:10:24 by lvallie           #+#    #+#             */
/*   Updated: 2021/05/13 14:33:30 by lvallie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

size_t	ft_countnbr_dec(long long int number)
{
	size_t	counter;

	counter = 0;
	if (number < 0)
		number = -number;
	if (number > 10)
		counter = ft_countnbr_dec(number / 10);
	return (counter + 1);
}

size_t	ft_putnbr_dec(long long int number)
{
	size_t	counter;

	counter = 0;
	if (number < 0)
		number = -number;
	if (number > 10)
		counter = ft_putnbr_dec(number / 10);
	number = (int)((number % 10) + 48);
	write(1, &number, 1);
	return (counter + 1);
}