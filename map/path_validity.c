/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_validity.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamieta <anamieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 19:16:41 by anamieta          #+#    #+#             */
/*   Updated: 2024/04/10 14:16:53 by anamieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	fill(char **array, t_point size, t_point current)
{
	if (current.x < 0 || current.y < 0 || current.x >= size.x
		|| current.y >= size.y || array[current.y][current.x] == '1')
		return ;
	array[current.y][current.x] = '1';
	fill(array, size, (t_point){current.x +1, current.y});
	fill(array, size, (t_point){current.x -1, current.y});
	fill(array, size, (t_point){current.x, current.y +1});
	fill(array, size, (t_point){current.x, current.y -1});
}

static void	flood_fill(t_game game)
{
	t_point	size;
	t_point	player;

	size = size_set(game);
	player = player_position_set(game);
	fill(game.map.array, size, player);
}

void	valid_path(t_game game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	flood_fill(game);
	while (game.map.array[i])
	{
		j = 0;
		while (game.map.array[i][j])
		{
			if (game.map.array[i][j] != '1' && game.map.array[i][j] != '0'
				&& game.map.array[i][j] != '\n')
				error_handling(game.map.array,
					"Some significant characters are unreachable!");
			j++;
		}
		i++;
	}
}
