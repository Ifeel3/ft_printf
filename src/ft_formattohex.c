/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_applyformattohex.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvallie <lvallie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 02:45:30 by lvallie           #+#    #+#             */
/*   Updated: 2021/05/11 23:35:54 by lvallie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static char	*ptf_convertinttohex(int number, char type)
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

int	ptf_formattohex(int number, t_type *flags, char format)
{
	char	*string;
	int		len;

	(void) flags;
	(void) format;
	string = ptf_convertinttohex(number, format);
	len = (int)ft_strlen(string);
	write(1, string, ft_strlen(string));
	free(string);
	return (len);
}
