/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamieta <anamieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 18:04:23 by anamieta          #+#    #+#             */
/*   Updated: 2024/04/15 14:01:26 by anamieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	figure_counter(char **array, int *player,
	int *exit, int *collectible)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (array[i])
	{
		j = 0;
		while (array[i][j])
		{
			if (array[i][j] == 'P')
				(*player)++;
			else if (array[i][j] == 'E')
				(*exit)++;
			else if (array[i][j] == 'C')
				(*collectible)++;
			j++;
		}
		i++;
	}
}

void	figure_number_check(char **array)
{
	int	collectible;
	int	player;
	int	exit;

	collectible = 0;
	player = 0;
	exit = 0;
	figure_counter(array, &player, &exit, &collectible);
	if (player != 1)
		error_handling(array, "There should be one player!");
	if (exit != 1)
		error_handling(array, "There should be one exit!");
	if (collectible < 1)
		error_handling(array, "There should be at least one collectible!");
}

void	valid_extension(char **array, char *str)
{
	int		length;

	length = ft_strlen(str) - 1;
	if (str[length - 3] != '.' || str[length - 2] != 'b'
		|| str[length - 1] != 'e' || str[length] != 'r')
		error_handling(array, "Map extension invalid");
}

void	valid_characters(char **array)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (array[i])
	{
		j = 0;
		while (array[i][j])
		{
			if (array[i][j] != 'E' && array[i][j] != 'P' && array[i][j] != 'C'
				&& array[i][j] != '0' && array[i][j] != '1'
				&& array[i][j] != '\n')
				error_handling(array, "Map contains invalid characters");
			j++;
		}
		i++;
	}
}

void	enemy_pos_set(t_game *game)
{
	game->enemy_pos.x = game->map.exit.x * TILE_SIZE;
	game->enemy_pos.y = game->map.exit.y * TILE_SIZE;
	game->enemy_dir.x = 1;
	game->enemy_dir.y = 1;
}

void	map_validity(t_game *game, char *file_name)
{
	char	**tmp_array;

	tmp_array = create_array(file_name);
	figure_number_check(game->map.array);
	rectangular_check(game->map.array);
	valid_extension(game->map.array, file_name);
	valid_characters(game->map.array);
	surrounded_by_walls(game->map.array);
	valid_path(game, tmp_array);
	size_set(game);
	exit_position_set(game);
	count_collectibles(&game->map);
	enemy_pos_set(game);
	free(tmp_array);
	//free the tmp_game
}
