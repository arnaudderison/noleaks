NAME = libft.a
NOLEAKS = noleaks
CC = gcc
CFLAGS = -Wall -Wextra -Werror
LIBFT_DIR = ./src/libft/libft
FT_PRINTF_DIR = ./src/libft/ft_printf
GNL_DIR = ./src/libft/gnl
INCLUDES = -I$(LIBFT_DIR) -I $(FT_PRINTF_DIR)/includes -I$(GNL_DIR)

# Colors
RED=\033[0;31m
GREEN=\033[0;32m
YELLOW=\033[1;33m
CYAN=\033[0;36m
NC=\033[0m

# Libft sources
LIBFT_SRCS = $(wildcard $(LIBFT_DIR)/*.c)
LIBFT_OBJS = $(LIBFT_SRCS:.c=.o)

# ft_printf sources
FT_PRINTF_SRCS = $(wildcard $(FT_PRINTF_DIR)/*.c) \
				$(wildcard $(FT_PRINTF_DIR)/srcs/*.c)
FT_PRINTF_OBJS = $(FT_PRINTF_SRCS:.c=.o)

# GNL sources
GNL_SRCS = $(wildcard $(GNL_DIR)/*.c)
GNL_OBJS = $(GNL_SRCS:.c=.o)

# noleaks sources
NOLEAKS_SRCS = $(wildcard ./src/*/*.c) \
				src/main.c
NOLEAKS_OBJS = $(NOLEAKS_SRCS:.c=.o)

# Compilation rules
all: $(NAME) $(NOLEAKS)

$(NAME): $(LIBFT_OBJS) $(FT_PRINTF_OBJS) $(GNL_OBJS)
	@ar rcs $(NAME) $^
	@echo "${YELLOW}Library $(NAME) created.${NC}"

$(NOLEAKS): $(NOLEAKS_OBJS) $(NAME)
	@$(CC) $(CFLAGS) $^ -o $@
	@echo "${YELLOW}Executable $(NOLEAKS) created.${NC}"

%.o: %.c
	@echo "${CYAN}Compiling $<...${NC}"
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@rm -f $(LIBFT_OBJS) $(FT_PRINTF_OBJS) $(GNL_OBJS) $(NOLEAKS_OBJS)
	@echo "${GREEN}Object files cleaned.${NC}"

fclean: clean
	@rm -f $(NAME) $(NOLEAKS)
	@echo "${RED}All files removed.${NC}"

re: fclean all

.PHONY: all clean fclean re
