NAME		:= so_long

CC			:= cc
CFLAGS		:= -Wall -Werror -Wextra -g

CFLAGS_MLX	:= -Wall -Werror -Wextra -g -Wunreachable-code -Ofast
MLX_PATH	:= libraries/MLX42

HEADERS		:= -I ./include -I $(MLX_PATH)/include
LIB_MLX		:= $(MLX_PATH)/build/MLX_PATH42.a -ldl -lglfw -pthread -lm
MLX			:=  libraries/MLX42/build/libmlx42.a -ldl -lglfw -pthread -lm

LIBFT_PATH 	:= ./libraries/libft
PARSING_PATH:= ./parsing

LIBFT 		:=	$(LIBFT_PATH)/libft.a
LDFLAGS 	:= -L $(LIBFT_PATH) -lft

SRC 		:=	parsing/array_utils.c parsing/map_utils.c \
				parsing/create_array.c parsing/path_validity.c \
				parsing/main.c
OBJ 		:=	$(SRC:.c=.o)

all: libmlx $(LIBFT) $(NAME)

libmlx:
	@cmake $(MLX_PATH) -B $(MLX_PATH)/build && make -C $(MLX_PATH)/build -j4

$(LIBFT):
	@make -C $(LIBFT_PATH)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $^ $(LDFLAGS) $(MLX) -o $@

$(OBJ): %.o : %.c
	$(CC) -c $(CFLAGS) -I$(LIBFT_PATH) $(HEADERS) $< -o $@

clean:
	rm -f $(OBJ)
	@make -C $(LIBFT_PATH) clean

fclean: clean
	rm -f $(NAME)
	@make -C $(LIBFT_PATH) fclean

re: fclean all

.PHONY: all clean fclean norm re libmlx