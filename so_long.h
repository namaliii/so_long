/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamieta <anamieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 18:14:17 by anamieta          #+#    #+#             */
/*   Updated: 2024/04/16 15:22:21 by anamieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libraries/libft/libft.h"
# include <fcntl.h>
# include "libraries/MLX42/include/MLX42/MLX42.h"

# define NUM_PL_IMGS 11
# define NUM_COLLECT_IMGS 17
# define NUM_EXIT_IMGS 8
# define NUM_ENEMY_IMGS 4

# define TILE_SIZE 64

typedef struct s_point
{
	int	x;
	int	y;
}				t_point;

typedef struct s_map
{
	char	**array;
	t_point	collectible;
	t_point	player;
	t_point	player_copy;
	t_point	exit;
	t_point	size;
	int		melon_count;
	int		collected;
	int		display_moves;
}				t_map;

typedef struct s_corners
{
	t_point	upper_left;
	t_point	upper_right;
	t_point	lower_left;
	t_point	lower_right;
}				t_corners;

typedef struct s_game
{
	t_map		map;
	mlx_t		*mlx;
	mlx_image_t	*background[2];
	mlx_image_t	*wall;
	mlx_image_t	*player[NUM_PL_IMGS];
	mlx_image_t	*exit[NUM_EXIT_IMGS];
	mlx_image_t	*collectible[NUM_COLLECT_IMGS];
	mlx_image_t	*enemy[NUM_ENEMY_IMGS];
	mlx_image_t	*moves_counter_img;
	t_point		enemy_pos;
	t_point		enemy_dir;
	t_corners	en_cor;
}				t_game;

// map checks
void		error_handling(t_game *game, char **array, char *str);
int			file_opening(t_game *game, char *file_name);
int			count_lines(t_game *game, char *file_name);
char		**create_array(t_game *game, char *file_name);
void		rectangular_check(t_game *game);
void		surrounded_by_walls(t_game *game, char **array);
void		figure_number_check(t_game *game);
void		valid_extension(t_game *game, char *file_name);
void		valid_characters(t_game *game, char **array);
void		map_validity(t_game *game, char *file_name);
void		valid_path(t_game *game, char **array);
void		count_collectibles(t_map *map);

// setting
t_point		player_position_set(t_game *game);
t_point		size_set(t_game *game);
t_point		exit_position_set(t_game *game);
void		enemy_pos_set(t_game *game);

// images
int			load_imgs_error_check(t_game *game, mlx_image_t **imgs,
				const char **paths);
int			player_imgs(t_game *game);
int			melon_imgs(t_game *game);
int			exit_imgs(t_game *game);
int			enemy_imgs(t_game *game);
int			background_imgs(t_game *game);
int			wall_img(t_game *game);
mlx_image_t	*load_image(const char *path, t_game *game);
int			load_images(t_game *game);

// rendering
void		player_img_to_window(t_game *game, int x, int y);
void		melon_img_to_window(t_game *game, int x, int y);
void		exit_img_to_window(t_game *game, int x, int y);
void		enemy_img_to_window(t_game *game);
void		background_img_to_window(t_game *game, int x, int y);
void		render_map(t_game *game);

// animate
void		animate_exit(mlx_image_t **img, int num_imgs);
void		animate_enemy(t_game *game, mlx_image_t **img, int num_imgs);
void		animate_melon(mlx_image_t **img, int num_imgs);
void		animate_player(mlx_image_t **img, int num_imgs, t_game *game);

// game
void		my_keyhook(mlx_key_data_t keydata, void *param);
void		move_and_collect(t_game *game);
void		collect_melons(t_game *game, char **array);
void		enemy_x_collisions(t_game *game);
void		enemy_y_collisions(t_game *game);
void		enemy_player_collisions(t_game *game,
				t_point player_hitbox, t_point enemy_hitbox);

//utils
void		ft_exit(t_game *game, int exit_code, char *str);
void		free_2d_array(char **array);

int			main(int argc, char **argv);
#endif
