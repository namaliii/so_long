/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamieta <anamieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 18:04:23 by anamieta          #+#    #+#             */
/*   Updated: 2024/04/16 16:09:02 by anamieta         ###   ########.fr       */
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

void	figure_number_check(t_game *game)
{
	int	collectible;
	int	player;
	int	exit;

	collectible = 0;
	player = 0;
	exit = 0;
	figure_counter(game->map.array, &player, &exit, &collectible);
	if (player != 1)
		error_handling(game, game->map.array, "There should be one player!");
	if (exit != 1)
		error_handling(game, game->map.array, "There should be one exit!");
	if (collectible < 1)
		error_handling(game, game->map.array,
			"There should be at least one collectible!");
}

void	valid_extension(t_game *game, char *file_name)
{
	int		length;

	length = ft_strlen(file_name) - 1;
	if (file_name[length - 3] != '.' || file_name[length - 2] != 'b'
		|| file_name[length - 1] != 'e' || file_name[length] != 'r')
		error_handling(game, game->map.array, "Map extension invalid");
}

void	valid_characters(t_game *game, char **array)
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
				error_handling(game, array, "Map contains invalid characters");
			j++;
		}
		i++;
	}
}

void	map_validity(t_game *game, char *file_name)
{
	char	**tmp_array;

	figure_number_check(game);
	rectangular_check(game);
	valid_characters(game, game->map.array);
	surrounded_by_walls(game, game->map.array);
	tmp_array = create_array(game, file_name);
	valid_path(game, tmp_array);
	free_2d_array(tmp_array);
	size_set(game);
	exit_position_set(game);
	count_collectibles(&game->map);
	enemy_pos_set(game);
	if (game->map.size.y == 3)
		ft_exit(game, EXIT_FAILURE, "Map is not playable!");
}
