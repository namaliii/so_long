NAME = so_long
CC = cc
CFLAGS = -Wall -Werror -Wextra -g
LIBFT_PATH = ./libraries/libft
PARSING_PATH = ./parsing

LIBFT =	$(LIBFT_PATH)/libft.a
LDFLAGS = -L $(LIBFT_PATH) -lft

SRC =	parsing/array_utils.c parsing/map_utils.c \
		parsing/create_array.c parsing/path_validity.c \
		parsing/main.c
OBJ =	$(SRC:.c=.o)

all: $(LIBFT) $(NAME)

$(LIBFT):
	@make -C $(LIBFT_PATH)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $^ $(LDFLAGS) -o $@

$(OBJ): %.o : %.c
	$(CC) -c $(CFLAGS) -I$(LIBFT_PATH) $< -o $@

clean:
	/bin/rm -f $(OBJ)
	@make -C $(LIBFT_PATH) clean

fclean: clean
	rm -rf $(NAME)
	@make -C $(LIBFT_PATH) fclean

re: fclean all

.PHONY: all clean fclean norm re