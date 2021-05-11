/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_applyformattoptr.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvallie <lvallie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 01:55:16 by lvallie           #+#    #+#             */
/*   Updated: 2021/05/11 23:35:54 by lvallie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static void	ptf_shiftstring(char *string)
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

static char	*ptf_convertpointertohex(void *ptr)
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
	ptf_shiftstring(s);
	return (s);
}

int	ptf_applyformattoptr(void *ptr, t_type *flags)
{
	char	*string;
	int		len;

	(void) flags;
	string = ptf_convertpointertohex(ptr);
	len = (int)ft_strlen(string);
	write(1, "0x", 2);
	write(1, string, ft_strlen(string));
	free(string);
	return (len + 2);
}
