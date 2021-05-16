/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countnbr_hex.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvallie <lvallie@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 17:22:40 by lvallie           #+#    #+#             */
/*   Updated: 2021/05/16 17:22:40 by lvallie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

size_t	ft_countnbr_hex(unsigned int number)
{
	size_t	counter;

	counter = 0;
	if (number > 15)
		counter = ft_countnbr_hex(number >> 4);
	return (counter + 1);
}
