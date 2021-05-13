/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convertinthex.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvallie <lvallie@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 02:46:33 by lvallie           #+#    #+#             */
/*   Updated: 2021/05/13 02:49:57 by lvallie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*ptf_convertinttohexlow(int number)
{
	int		tmp;
	char	*s;
	int		i;

	if (number == 0)
		return (ft_strdup("0"));
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
		tmp >>= 4;
		i--;
	}
	return (s);
}

char	*ptf_convertinttohexup(int number)
{
	int		tmp;
	char	*s;
	int		i;

	if (number == 0)
		return (ft_strdup("0"));
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
		s[i] = "0123456789ABCDEF"[tmp & 0x0F];
		tmp >>= 4;
		i--;
	}
	return (s);
}