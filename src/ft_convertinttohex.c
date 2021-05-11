/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convertinttohex.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvallie <lvallie@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 03:29:01 by lvallie           #+#    #+#             */
/*   Updated: 2021/05/09 04:13:44 by lvallie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*ft_convertinttohex(int number, char type)
{
	int		tmp;
	char	*s;
	int		i;

	tmp = number;
	i = 0;
	while (tmp != 0)
	{
		tmp >>= 4;
		i++;
	}
	s = malloc(sizeof(char) * (i + 1));
	if (!s)
		return (NULL);
	tmp = number;
	s[i--] = 0;
	while (i >= 0)
	{
		s[i] = "0123456789abcdef"[tmp & 0x0F];
		if (ft_isupper(type))
			s[i] = "0123456789ABCDEF"[tmp & 0x0F];
		tmp >>= 4;
		i--;
	}
	return (s);
}
