/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countnbr_dec.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvallie <lvallie@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 17:13:41 by lvallie           #+#    #+#             */
/*   Updated: 2021/05/16 17:15:09 by lvallie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../ft_printf.h"

size_t	ft_countnbr_dec(long long int number)
{
	size_t	counter;

	counter = 0;
	if (number < 0)
		number = -number;
	if (number > 9)
		counter = ft_countnbr_dec(number / 10);
	return (counter + 1);
}
