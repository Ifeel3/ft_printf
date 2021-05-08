/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printpercent.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvallie <lvallie@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 01:11:41 by lvallie           #+#    #+#             */
/*   Updated: 2021/05/09 01:11:41 by lvallie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/libftprintf.h"

int ft_printpercent(char **string, int *printed_chars)
{
	if (*(*string + 1) == '%')
	{
		*printed_chars += 1;
		*string += 2;
		write(1, "%", 1);
		return (1);
	}
	else
		return (0);
}