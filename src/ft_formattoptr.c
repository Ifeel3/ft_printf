/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_applyformattoptr.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvallie <lvallie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 01:55:16 by lvallie           #+#    #+#             */
/*   Updated: 2021/05/16 15:59:18 by lvallie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static size_t	ft_countptr_hex(unsigned long long int number)
{
	size_t	counter;

	counter = 0;
	if (number > 15)
		counter = ft_countptr_hex(number >> 4);
	return (counter + 1);
}

static void	ft_putptr_hex(unsigned long long int number, int type)
{
	if (number > 15)
		ft_putptr_hex(number >> 4, type);
	write(1, &"0123456789abcdef"[number & 0x0F], 1);
}

static void	widandprec(unsigned long long int addr, t_type *fl, size_t *wid, size_t *prec)
{
	*prec = ft_countptr_hex(addr);
	if (addr == 0 && fl->dot == 1 && fl->precision == 0)
		*prec = 0;
	else if (fl->dot == 1)
	{
		if (fl->precision < (int)ft_countptr_hex(addr))
			*prec = ft_countptr_hex(addr);
		else
			*prec = fl->precision;
	}
	if (fl->width > (int)*prec)
		*wid = fl->width;
	else
		*wid = *prec;
}

static void	printspace(size_t count1, size_t count2, int chr)
{
	while (count1-- > count2)
		write(1, &chr, 1);
}

int	ptf_formattoptr(void *ptr, t_type *flags)
{
	unsigned long long int addr;
	size_t	precision;
	size_t	width;
	char	chr;

	addr = (unsigned long long)&(*ptr);
	chr = ' ';
	widandprec(addr, flags, &width, &precision);
	if (flags->nill == 1 && flags->dot != 1)
		chr = '0';
	write(1, "0x", 2);
	if (flags->minus != 1)
		printspace(width, precision, chr);
	printspace(precision, ft_countptr_hex(addr), '0');
	if (addr == 0 && flags->dot == 1 && precision == 0)
		;
	else
		ft_putptr_hex(addr, flags->type);
	if (flags->minus == 1)
		printspace(width, precision, ' ');
	return ((int)width);
}
