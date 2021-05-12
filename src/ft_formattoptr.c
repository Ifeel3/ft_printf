/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_applyformattoptr.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvallie <lvallie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 01:55:16 by lvallie           #+#    #+#             */
/*   Updated: 2021/05/12 22:20:07 by lvallie          ###   ########.fr       */
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

static void	widandprec(char *str, size_t *wid, size_t *prec, t_type *flags)
{
	if (flags->dot == 1)
	{
		if ((size_t)flags->precision > ft_strlen(str))
			*prec = flags->precision;
		else
			*prec = ft_strlen(str);
	}
	else
		*prec = ft_strlen(str);
	if ((size_t)flags->width > *prec + 2)
		*wid = flags->width;
	else
		*wid = *prec + 2;
}

static void	printspace(size_t count1, size_t count2)
{
	while (count1-- > count2 + 2)
		write(1, " ", 1);
}

int	ptf_formattoptr(void *ptr, t_type *flags)
{
	char	*string;
	size_t	precision;
	size_t	width;
	size_t	tmp;

	if (ptr == NULL && flags->dot == 0)
		string = "0";
	else if (ptr == NULL && flags->dot == 1)
		string = "";
	else
		string = ptf_convertpointertohex(ptr);
	widandprec(string, &width, &precision, flags);
	if (flags->minus != 1)
		printspace(width, precision);
	write(1, "0x", 2);
	tmp = precision;
	while (tmp-- > ft_strlen(string))
		write(1, "0", 1);
	write(1, string, ft_strlen(string));
	if (flags->minus == 1)
		printspace(width, precision);
	if (ptr)
		free(string);
	return ((int)width);
}
