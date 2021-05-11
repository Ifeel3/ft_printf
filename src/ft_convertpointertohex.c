/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convertpointertohex.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvallie <lvallie@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 21:17:14 by lvallie           #+#    #+#             */
/*   Updated: 2021/05/10 14:23:37 by lvallie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static void	shiftstring(char *string)
{
	char	*start;

	start = string;
	while (*string == '0')
		string++;
	while (*string)
		*start++ = *string++;
	while (*start)
		*start++ = 0;
}

char	*ft_convertpointertohex(void *ptr)
{
	intptr_t	ptraddr;
	char		*s;
	int			i;

	s = malloc(2 * sizeof(ptraddr) + 1);
	if (!s)
		return (NULL);
	ptraddr = (intptr_t)&(*ptr);
	i = 2 * sizeof(ptraddr);
	s[i--] = 0;
	while (i >= 0)
	{
		s[i] = "0123456789abcdef"[ptraddr & 0x0F];
		ptraddr >>= 4;
		i--;
	}
	shiftstring(s);
	return (s);
}
