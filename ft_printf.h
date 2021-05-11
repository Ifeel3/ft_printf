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
int		ptf_applyformattoptr(void *ptr, t_type *flags);
int		ptf_applyformattohex(int number, t_type *flags, char format);
int		ptf_applyformattoint(int number, t_type *flags);
int		ptf_applyformattostr(char *string, t_type *flags);
int		ptf_applyformattochr(int c, t_type *flags);
int		ptf_applyformattouint(unsigned int number, t_type *flags);
#endif