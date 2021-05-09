/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvallie <lvallie@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 01:12:29 by lvallie           #+#    #+#             */
/*   Updated: 2021/05/09 03:56:34 by lvallie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
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
int		ft_converter(char **string, va_list ap, int *printed_chars);
void	ft_initflags(t_type *flags);
int		ft_setupflags(char **string, t_type *flags, va_list ap);
int		ft_printpercent(char **string, int *printed_chars);
char	*ft_convertpointertohex(void *ptr);
char	*ft_convertinttohex(int number);
void	ft_checktype(t_type *flags, int *printed_chars, va_list ap);
int		ft_applyformattoptr(void *ptr, t_type *flags);
int		ft_applyformattohex(int number, t_type *flags, char format);
#endif