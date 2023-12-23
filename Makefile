NOLEAKS = noleaks.a
CC = gcc
FT_PRINTF_DIR = ./src/libft/ft_printf
INCLUDES = -I$(FT_PRINTF_DIR)/includes
CFLAGS = -Wall -Wextra -Werror

# Colors
RED=\033[0;31m
GREEN=\033[0;32m
YELLOW=\033[1;33m
CYAN=\033[0;36m
NC=\033[0m

# ft_printf sources
FT_PRINTF_SRCS = $(wildcard $(FT_PRINTF_DIR)/*.c) \
				$(wildcard $(FT_PRINTF_DIR)/srcs/*.c)
FT_PRINTF_OBJS = $(FT_PRINTF_SRCS:.c=.o)

# noleaks sources
NOLEAKS_SRCS = $(wildcard ./src/*/*.c) \
				$(wildcard ./src/*.c)
NOLEAKS_OBJS = $(NOLEAKS_SRCS:.c=.o)

all: $(NOLEAKS)

$(NOLEAKS): $(NOLEAKS_OBJS) $(FT_PRINTF_OBJS)
	@ar rcs $(NOLEAKS) $^
	@echo "${YELLOW}Library $(NOLEAKS) created.${NC}"

%.o: %.c
	@echo "${CYAN}Compiling $<...${NC}"
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@rm -f $(FT_PRINTF_OBJS) $(NOLEAKS_OBJS)
	@echo "${GREEN}Object files cleaned.${NC}"

fclean: clean
	@rm -f $(NOLEAKS)
	@echo "${RED}All files removed.${NC}"

re: fclean all

.PHONY: all clean fclean re
