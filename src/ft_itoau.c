/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvallie <lvallie@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 13:55:48 by lvallie           #+#    #+#             */
/*   Updated: 2021/05/11 20:42:30 by lvallie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	ft_howbig(unsigned int c)
{
	int	i;

	if (c < 0)
	{
		i = 1;
		c = -c;
	}
	else
		i = 0;
	while (c)
	{
		c = c / 10;
		i++;
	}
	return (i);
}

char	*ft_itoau(unsigned int n)
{
	char	*result;
	int		i;

	if (n == 0)
		return (ft_strdup("0"));
	i = ft_howbig(n);
	result = malloc(sizeof(char) * i + 1);
	if (result == NULL)
		return (NULL);
	result[i] = '\0';
	while (n > 0)
	{
		i--;
		result[i] = (char)((n % 10) + 48);
		n = n / 10;
	}
	return (result);
}
