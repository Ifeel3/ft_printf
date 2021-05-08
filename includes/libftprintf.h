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
int		converter(char **string, va_list ap, int *printed_chars);
void	initflags(t_type flags);
int		setupflags(char **string, t_type flags);
#endif