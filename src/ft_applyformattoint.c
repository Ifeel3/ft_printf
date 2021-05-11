/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_applyformattoint.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvallie <lvallie@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 13:24:30 by lvallie           #+#    #+#             */
/*   Updated: 2021/05/10 13:27:42 by lvallie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_applyformattoint(int number, t_type *flags)
{
	char	*string;
	int		len;

	(void) flags;
	string = ft_itoa(number);
	len = (int)ft_strlen(string);
	write(1, string, ft_strlen(string));
	free(string);
	return (len);
}
