/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamieta <anamieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 18:14:17 by anamieta          #+#    #+#             */
/*   Updated: 2024/04/10 14:20:58 by anamieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libraries/libft/libft.h"
# include <fcntl.h>
# include "libraries/MLX42/include/MLX42/MLX42.h"

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
}				t_map;

typedef struct s_game
{
	t_map		map;
	mlx_t		*mlx;
	mlx_image_t	*background;
	mlx_image_t	*wall;
	mlx_image_t	*player;
	mlx_image_t	*exit;
	mlx_image_t	*collectible;
}				t_game;

void	error_handling(char **array, char *str);
int		file_opening(char *str);
int		count_lines(char *str);
char	**create_array(char *str);
void	rectangular_check(char **array);
void	surrounded_by_walls(char **array);
void	figure_number_check(char **array);
void	valid_extension(char **array, char *str);
void	valid_characters(char **array);
void	map_validity(t_game game, char **array, char *str);
void	valid_path(t_game game);

t_point	player_position_set(t_game game);
t_point	size_set(t_game game);
t_point	exit_position_set(t_game game);

void	render_map(t_game *game);
void	load_images(t_game *game);

int		main(int argc, char **argv);
#endif
