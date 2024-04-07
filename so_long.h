/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamieta <anamieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 18:14:17 by anamieta          #+#    #+#             */
/*   Updated: 2024/04/07 16:35:46 by anamieta         ###   ########.fr       */
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
	char	*path;
	int		collectible;
	int		player;
	int		exit;
	int		height;
}				t_map;

void	error_handling(char *str);
int		file_opening(char *str);
int		count_lines(char *str);
char	**create_array(char *str);
void	rectangular_check(char **array);
void	surrounded_by_walls(char **array);
void	figure_number_check(char **array, int *player,
			int *exit, int *collectible);
void	valid_extension(char *str);
void	valid_characters(char **array);
void	map_validity(char *str);
void	valid_path(char **array);
int		main(int argc, char **argv);
#endif
