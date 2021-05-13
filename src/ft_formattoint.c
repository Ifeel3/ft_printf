/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_applyformattoint.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvallie <lvallie@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 13:24:30 by lvallie           #+#    #+#             */
/*   Updated: 2021/05/13 02:46:20 by lvallie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static void	widandprec(char *str, t_type *flags, size_t *wid, size_t *prec)
{
	*prec = ft_strlen(str);
	if (flags->dot == 1)
	{
		if ((size_t)flags->precision < ft_strlen(str))
			*prec = ft_strlen(str);
		else
			*prec = flags->precision;
	}
	if ((size_t)flags->width > *prec)
		*wid = flags->width;
	else
		*wid = *prec;
}

static void	printspace(size_t count1, size_t count2, int chr)
{
	while (count1-- > count2)
		write(1, &chr, 1);
}

static void	getstring(t_type *flags, int number, char **string, char *chr)
{
	if (flags->nill == 1 && flags->dot != 1)
		*chr = '0';
	else
		*chr = ' ';
	(void) chr;
	if (flags->type == 'x')
		*string = ptf_convertinttohexlow(number);
	else if (flags->type == 'X')
		*string = ptf_convertinttohexup(number);
	else if (flags->type == 'u')
		*string = ptf_itoau(number);
	else
		*string = ft_itoa(number);
}

int	ptf_formattoint(int number, t_type *flags)
{
	char	*string;
	size_t	precision;
	size_t	width;
	char	chr;
	char	*tmp;

	getstring(flags, number, &string, &chr);
	if (string[0] == '-')
		return (0);
	tmp = string;
	widandprec(string, flags, &width, &precision);
	if (flags->minus != 1)
		printspace(width, precision, chr);
	printspace(precision, ft_strlen(tmp), '0');
	write(1, tmp, ft_strlen(tmp));
	if (flags->minus == 1)
		printspace(width, precision, ' ');
	free(string);
	return ((int)width);
}
