NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRC = 	ft_printf.c \
		srcs/ft_pointer.c \
		srcs/ft_putchar_fd_printf.c \
		srcs/ft_putstr_fd_printf.c \
		srcs/ft_putnbr_fd_printf.c \
		srcs/ft_strlen_printf.c \
		srcs/ft_u_putnbr_fd_printf.c \
		srcs/ft_strlcpy_printf.c \
		srcs/ft_puthex_fd_printf.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
