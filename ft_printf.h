/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvallie <lvallie@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 01:12:29 by lvallie           #+#    #+#             */
/*   Updated: 2021/05/11 20:44:48 by lvallie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include "libft.h"

typedef struct s_type
{
	int		minus;
	int		nill;
	int		dot;
	int		width;
	int		precision;
	char	type;
}				t_type;

int		ft_printf(char *string, ...);
int		ptf_converter(char **string, va_list ap, int *printed_chars);
int		ptf_setupflags(char **string, t_type *flags, va_list ap);
char	*ptf_itoau(unsigned int n);
void	ptf_checktype(t_type *flags, int *printed_chars, va_list ap);
int		ptf_formattoptr(void *ptr, t_type *flags);
int		ptf_formattoint(int number, t_type *flags);
int		ptf_formattostr(char *string, t_type *flags);
int		ptf_formattochr(int c, t_type *flags);
size_t	ft_countnbr_hex(long long int number);
size_t	ft_putnbr_hex(unsigned long long int number, int type);
size_t	ft_countnbr_dec(long long int number);
size_t	ft_putnbr_dec(long long int number);
#endif