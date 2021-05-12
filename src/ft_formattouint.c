/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_applyformattouint.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvallie <lvallie@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 13:24:30 by lvallie           #+#    #+#             */
/*   Updated: 2021/05/11 22:01:51 by lvallie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ptf_formattouint(unsigned int number, t_type *flags)
{
	char	*string;
	int		len;

	(void) flags;
	string = ptf_itoau(number);
	len = (int)ft_strlen(string);
	write(1, string, ft_strlen(string));
	free(string);
	return (len);
}
