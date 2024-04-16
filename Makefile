NAME		:= so_long

CC			:= cc
CFLAGS		:= -Wall -Werror -Wextra -g

CFLAGS_MLX	:= -Wall -Werror -Wextra -g -Wunreachable-code -Ofast
MLX_PATH	:= libraries/MLX42

HEADERS		:= -I ./include -I $(MLX_PATH)/include
LIB_MLX		:= $(MLX_PATH)/build/MLX_PATH42.a -ldl -lglfw -pthread -lm
MLX			:=  libraries/MLX42/build/libmlx42.a -ldl -lglfw -pthread -lm

LIBFT_PATH 	:= ./libraries/libft

LIBFT 		:=	$(LIBFT_PATH)/libft.a
LDFLAGS 	:= -L $(LIBFT_PATH) -lft

SRC 		:=	map/array_utils.c map/map_utils.c \
				map/create_array.c map/path_validity.c \
				map/figures_positions.c game/load_images.c \
				game/player_images.c game/user_interaction.c \
				game/other_images.c game/render_map.c \
				game/render_variables.c game/animate.c \
				game/e_pl_collisions.c game/e_wall_xcollisions.c \
				game/e_wall_ycollisions.c \
				main.c

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