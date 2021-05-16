/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvallie <lvallie@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 01:12:29 by lvallie           #+#    #+#             */
/*   Updated: 2021/05/16 16:20:40 by lvallie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include "libft.h"

typedef struct s_type
{
	size_t	minus;
	size_t	nill;
	size_t	dot;
	int		width;
	int		precision;
	char	type;
}				t_type;

int		ft_printf(char *string, ...);
int		ptf_converter(char **string, va_list ap, int *printed_chars);
int		ptf_setupflags(char **string, t_type *flags, va_list ap);
void	ptf_checktype(t_type *flags, int *printed_chars, va_list ap);
int		ptf_formattoptr(void *ptr, t_type *flags);
int		ptf_formattoint(long long int number, t_type *flags);
int		ptf_formattostr(char *string, t_type *flags);
int		ptf_formattochr(int c, t_type *flags);
int		ptf_formattohex(int number, t_type *flags);
size_t	ft_countnbr_hex(unsigned int number);
void	ft_putnbr_hex(unsigned int number, int type);
size_t	ft_countnbr_dec(long long int number);
void	ft_putnbr_dec(long long int number);
#endif