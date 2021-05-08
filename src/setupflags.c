/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setupflags.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvallie <lvallie@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 15:26:55 by lvallie           #+#    #+#             */
/*   Updated: 2021/05/08 15:56:59 by lvallie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

int	setupflags(char **string, t_type flags)
{
	while (ft_isalpha(**string) != 1)
	{
		if (**string == '-')
			flags.minus = 1;
		if (**string == '0')
			flags.nill = 1;
		if (**string == '.')
			flags.dot = 1;
		if (**string == '*')
			*string++;
	}
	if (ft_strchr("cspdiuxX", **string) == NULL)
		return (0);
	return (1);
}