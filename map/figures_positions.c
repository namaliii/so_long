/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   figures_positions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamieta <anamieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 13:48:38 by anamieta          #+#    #+#             */
/*   Updated: 2024/04/13 19:44:06 by anamieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

t_point	size_set(t_game *game)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (game->map.array[0][x] != '\n' && game->map.array[0][x] != '\0')
		x++;
	while (game->map.array[y])
		y++;
	game->map.size.x = x;
	game->map.size.y = y;
	return (game->map.size);
}

t_point	player_position_set(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (game->map.array[y])
	{
		x = 0;
		while (game->map.array[y][x])
		{
			if (game->map.array[y][x] == 'P')
			{
				game->map.player.x = x;
				game->map.player.y = y;
				return (game->map.player);
			}
			x++;
		}
		y++;
	}
	game->map.player.x = x;
	game->map.player.y = y;
	return (game->map.player);
}

t_point	exit_position_set(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (game->map.array[y])
	{
		x = 0;
		while (game->map.array[y][x])
		{
			if (game->map.array[y][x] == 'E')
			{
				game->map.exit.x = x;
				game->map.exit.y = y;
				return (game->map.exit);
			}
			x++;
		}
		y++;
	}
	game->map.exit.x = x;
	game->map.exit.y = y;
	return (game->map.exit);
}

void	count_collectibles(t_map map)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (map.array[y])
	{
		x = 0;
		while (map.array[y][x])
		{
			if (map.array[y][x] == 'C')
				map.melon_count++;
			x++;
		}
		y++;
	}
}
