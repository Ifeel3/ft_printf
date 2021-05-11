NAME	= libftprintf.a

FLAGS	= -Wall -Werror -Wextra

CFLAGS	= $(FLAGS) -I.

CC		= gcc

NORMIN	= norminette

HEADERS	= libft.h \
		ft_printf.h

LIBFT	= libft/ft_isdigit.c \
		libft/ft_islower.c \
		libft/ft_isupper.c \
		libft/ft_isalpha.c \
		libft/ft_isalnum.c \
		libft/ft_isprint.c \
		libft/ft_isnotprint.c \
		libft/ft_isascii.c \
		libft/ft_memset.c \
		libft/ft_bzero.c \
		libft/ft_memcpy.c \
		libft/ft_memrcpy.c \
		libft/ft_memmove.c \
		libft/ft_memchr.c \
		libft/ft_memccpy.c \
		libft/ft_memcmp.c \
		libft/ft_memrchr.c \
		libft/ft_strlen.c \
		libft/ft_strchr.c \
		libft/ft_strrchr.c \
		libft/ft_strncmp.c \
		libft/ft_strlcpy.c \
		libft/ft_strlcat.c \
		libft/ft_strnstr.c \
		libft/ft_substr.c \
		libft/ft_strjoin.c \
		libft/ft_strdup.c \
		libft/ft_strmapi.c \
		libft/ft_strtrim.c \
		libft/ft_split.c \
		libft/ft_toupper.c \
		libft/ft_tolower.c \
		libft/ft_calloc.c \
		libft/ft_atoi.c \
		libft/ft_putchar_fd.c \
		libft/ft_putstr_fd.c \
		libft/ft_putendl_fd.c \
		libft/ft_itoa.c \
		libft/ft_putnbr_fd.c \
		libft/ft_lstnew.c \
		libft/ft_lstadd_front.c \
		libft/ft_lstsize.c \
		libft/ft_lstlast.c \
		libft/ft_lstadd_back.c \
		libft/ft_lstdelone.c \
		libft/ft_lstclear.c \
		libft/ft_lstiter.c \
		libft/ft_lstmap.c

SRC		= src/ft_printf.c \
		src/ft_converter.c \
		src/ft_setupflags.c \
		src/ft_checktype.c \
		src/ft_applyformattoptr.c \
		src/ft_applyformattohex.c \
		src/ft_applyformattoint.c \
		src/ft_applyformattostr.c \
		src/ft_applyformattochr.c \
		src/ft_applyformattoint.c \
		src/ft_applyformattouint.c \
		src/ft_itoau.c

OBJS	= $(SRC:%.c=%.o)

LIBOBJS	= $(LIBFT:%.c=%.o)

.PHONY: all clean fclean re norm

all: $(LIB) $(NAME)

$(NAME): $(LIB) $(LIBOBJS) $(OBJS)
	ar rcs $@ $(LIBOBJS) $(OBJS)

clean:
	rm -f $(LIBOBJS)
	rm -f $(OBJS)
	rm -f test

fclean: clean
	rm -f $(LIB)
	rm -f $(NAME)

norm:
	$(NORMIN) -R CheckForbiddenSourceHeader $(LIBFT)
	$(NORMIN) -R CheckForbiddenSourceHeader $(SRC)
	$(NORMIN) $(HEADERS)

re: fclean all

test: $(LIB) $(NAME)
	$(CC) $(FLAGS) -L. -lftprintf main.c -o test