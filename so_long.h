/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamieta <anamieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 18:14:17 by anamieta          #+#    #+#             */
/*   Updated: 2024/04/13 19:44:17 by anamieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libraries/libft/libft.h"
# include <fcntl.h>
# include "libraries/MLX42/include/MLX42/MLX42.h"

# define NUM_BACKG_IMGS 2
# define NUM_IDLE_IMGS 11
# define NUM_RUN_IMGS 12
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
	t_point	exit;
	t_point	size;
	t_point	enemy;
	int		melon_count;
	int		collected;
	bool	is_dead;
}				t_map;

typedef enum Direction {
	UP,
	DOWN,
	LEFT,
	RIGHT,
}			t_direction;

typedef struct s_game
{
	t_map		map;
	mlx_t		*mlx;
	mlx_image_t	*background[NUM_BACKG_IMGS];
	mlx_image_t	*wall;
	mlx_image_t	*idle_right[NUM_IDLE_IMGS];
	mlx_image_t	*idle_left[NUM_IDLE_IMGS];
	mlx_image_t	*run_left[NUM_RUN_IMGS];
	mlx_image_t	*run_right[NUM_RUN_IMGS];
	mlx_image_t	*exit[NUM_EXIT_IMGS];
	mlx_image_t	*collectible[NUM_COLLECT_IMGS];
	mlx_image_t	*enemy[NUM_ENEMY_IMGS];
	bool		is_moving;
	t_direction	player_direction;
	int			idle;
	int			run;
}				t_game;

void		error_handling(char **array, char *file_name);
int			file_opening(char *file_name);
int			count_lines(char *file_name);
char		**create_array(char *file_name);
void		rectangular_check(char **array);
void		surrounded_by_walls(char **array);
void		figure_number_check(char **array);
void		valid_extension(char **array, char *file_name);
void		valid_characters(char **array);
void		map_validity(t_game *game, char *file_name);
void		valid_path(t_game *game, char **array);
void		count_collectibles(t_map map);

t_point		player_position_set(t_game *game);
t_point		size_set(t_game *game);
t_point		exit_position_set(t_game *game);

// images
int			load_imgs_error_check(t_game *game, mlx_image_t **imgs,
				const char **paths);
int			idle_right_imgs(t_game *game);
int			idle_left_imgs(t_game *game);
int			run_left_imgs(t_game *game);
int			run_right_imgs(t_game *game);
int			melon_imgs(t_game *game);
int			exit_imgs(t_game *game);
int			enemy_imgs(t_game *game);
int			background_imgs(t_game *game);
int			wall_img(t_game *game);
mlx_image_t	*load_image(const char *path, t_game *game);
int			load_images(t_game *game);

// rendering
void		idle_img_to_window(t_game *game, int x, int y);
void		run_img_to_window(t_game *game, int x, int y);
void		melon_img_to_window(t_game *game, int x, int y);
void		exit_img_to_window(t_game *game, int x, int y);
void		enemy_img_to_window(t_game *game, int x, int y);
void		background_img_to_window(t_game *game, int x, int y);
void		render_map(t_game *game);

// animate
void		animate_exit(mlx_image_t **img, int num_imgs);
void		animate_enemy(mlx_image_t **img, int num_imgs);
void		animate_melon(mlx_image_t **img, int num_imgs);
void		animate_idle_right(mlx_image_t **img, int num_imgs, t_game *game);
void		animate_idle_left(mlx_image_t **img, int num_imgs, t_game *game);
void		animate_run_right(mlx_image_t **img, int num_imgs, t_game *game);
void		animate_run_left(mlx_image_t **img, int num_imgs, t_game *game);

void		my_keyhook(mlx_key_data_t keydata, void* param);

int			main(int argc, char **argv);
#endif
