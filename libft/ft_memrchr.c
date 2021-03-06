/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvallie <lvallie@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 02:42:58 by lvallie           #+#    #+#             */
/*   Updated: 2021/04/22 23:46:14 by lvallie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_memrchr(const void *s, int c, size_t n)
{
	unsigned char	*source;

	source = (unsigned char *)s + n - 1;
	while (n--)
	{
		if (*source == (unsigned char)c)
			return (source);
		source--;
	}
	return (NULL);
}
