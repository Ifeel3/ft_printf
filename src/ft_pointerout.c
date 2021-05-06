/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointerout.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvallie <lvallie@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 21:17:14 by lvallie           #+#    #+#             */
/*   Updated: 2021/05/04 21:17:14 by lvallie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

static char	*convert_pointer(void *ptr, char format)
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
		if (format == 'X')
			s[i] = "0123456789ABCDEF"[ptraddr & 0x0F];
		else
			s[i] = "0123456789abcdef"[ptraddr & 0x0F];
		ptraddr >>= 4;
		i--;
	}
	return (s);
}

int	ft_pointerout(void *ptr, char format)
{
	char	*string;
	int		i;
	int		j;

	string = convert_pointer(ptr, format);
	if (string == NULL)
		return (-1);
	i = 0;
	j = 0;
	while (string [i] == 48)
		i++;
	write(1, "0x", 2);
	while (string[i + j] != 0)
	{
		write(1, &string[i + j], 1);
		j++;
	}
	return (j + 2);
}
