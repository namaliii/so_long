/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   e_wall_xcollisions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamieta <anamieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 13:01:40 by anamieta          #+#    #+#             */
/*   Updated: 2024/04/16 13:36:36 by anamieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	x_positive(t_game *game, t_point collision_tile)
{
	if (game->map.array[collision_tile.y][collision_tile.x] == '1')
	{
		game->enemy_dir.x = -1;
		game->enemy_pos.x = collision_tile.x * TILE_SIZE - TILE_SIZE - 1;
	}
	if (game->enemy_pos.y % TILE_SIZE != 0)
	{
		collision_tile.y++;
		if (game->map.array[collision_tile.y][collision_tile.x] == '1')
		{
			game->enemy_dir.x = -1;
			game->enemy_pos.x = collision_tile.x * TILE_SIZE - TILE_SIZE - 1;
		}
	}
}

static void	x_negative(t_game *game, t_point collision_tile)
{
	if (game->map.array[collision_tile.y][collision_tile.x] == '1')
	{
		game->enemy_dir.x = 1;
		game->enemy_pos.x = collision_tile.x * TILE_SIZE + TILE_SIZE;
	}
	if (game->enemy_pos.y % TILE_SIZE != 0)
	{
		collision_tile.y++;
		if (game->map.array[collision_tile.y][collision_tile.x] == '1')
		{
			game->enemy_dir.x = 1;
			game->enemy_pos.x = collision_tile.x * TILE_SIZE + TILE_SIZE;
		}
	}
}

void	enemy_x_collisions(t_game *game)
{
	t_point	collision_tile;

	if (game->enemy_dir.x > 0)
	{
		collision_tile.x = (game->enemy_pos.x + TILE_SIZE) / TILE_SIZE;
		collision_tile.y = (game->enemy_pos.y / TILE_SIZE);
		x_positive(game, collision_tile);
	}
	else
	{
		collision_tile.x = game->enemy_pos.x / TILE_SIZE;
		collision_tile.y = game->enemy_pos.y / TILE_SIZE;
		x_negative(game, collision_tile);
	}
}
