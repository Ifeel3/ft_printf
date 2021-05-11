/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_applyformattohex.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvallie <lvallie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 02:45:30 by lvallie           #+#    #+#             */
/*   Updated: 2021/05/09 04:03:20 by lvallie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_applyformattohex(int number, t_type *flags, char format)
{
	char	*string;
	int		len;

	(void) flags;
	(void) format;
	string = ft_convertinttohex(number, format);
	len = (int)ft_strlen(string);
	write(1, string, ft_strlen(string));
	free(string);
	return (len);
}
