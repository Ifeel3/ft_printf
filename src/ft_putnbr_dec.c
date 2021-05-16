/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_dec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvallie <lvallie@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 14:10:24 by lvallie           #+#    #+#             */
/*   Updated: 2021/05/16 17:15:09 by lvallie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_putnbr_dec(long long int number)
{
	if (number < 0)
		number = -number;
	if (number > 9)
		ft_putnbr_dec(number / 10);
	number = (int)((number % 10) + 48);
	write(1, &number, 1);
}
