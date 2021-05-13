/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_applyformattoint.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvallie <lvallie@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 13:24:30 by lvallie           #+#    #+#             */
/*   Updated: 2021/05/13 18:15:50 by lvallie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static void	widandprec(long long int num, t_type *fl, size_t *wid, size_t *prec)
{
	*prec = ft_countnbr_dec(num);
	if (num == 0 && fl->dot == 1 && fl->precision == 0)
		*prec = 0;
	else if (fl->dot == 1)
	{
		if (fl->precision < ft_countnbr_dec(num))
			*prec = ft_countnbr_dec(num);
		else
			*prec = fl->precision;
	}
	if (fl->width > *prec)
		*wid = fl->width;
	else
		*wid = *prec;
}

static void	printspace(size_t count1, size_t count2, int chr)
{
	while (count1-- > count2)
		write(1, &chr, 1);
}

int	ptf_formattoint(long long int number, t_type *flags)
{
	size_t	precision;
	size_t	width;
	char	chr;

	chr = ' ';
	if (number >= 0)
		widandprec(number, flags, &width, &precision);
	else
		return (0);
	if (flags->nill == 1 && flags->dot != 1)
		chr = '0';
	if (flags->minus != 1)
		printspace(width, precision, chr);
	printspace(precision, ft_countnbr_dec(number), '0');
	if (number == 0 && flags->dot == 1 && precision == 0)
		;
	else
		ft_putnbr_dec(number);
	if (flags->minus == 1)
		printspace(width, precision, ' ');
	return ((int)width);
}
