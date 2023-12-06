CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf
NAME = libftprintf.a
AR = ar crs

src = ft_printf.c ft_print_number_format.c ft_print_string_format.c
obj = $(src:.c=.o)

all: $(NAME)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(obj)
	$(AR) $@ $(obj)

clean:
	$(RM) $(obj)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
