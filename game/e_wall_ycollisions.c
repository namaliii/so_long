/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   e_wall_ycollisions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamieta <anamieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 13:29:11 by anamieta          #+#    #+#             */
/*   Updated: 2024/04/16 13:29:59 by anamieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	y_positive(t_game *game, t_point collision_tile)
{
	if (game->map.array[collision_tile.y][collision_tile.x] == '1')
	{
		game->enemy_dir.y = -1;
		game->enemy_pos.y = collision_tile.y * TILE_SIZE - TILE_SIZE;
	}
	if (game->enemy_pos.x % TILE_SIZE != 0)
	{
		collision_tile.x++;
		if (game->map.array[collision_tile.y][collision_tile.x] == '1')
		{
			game->enemy_dir.y = -1;
			game->enemy_pos.y = collision_tile.y * TILE_SIZE - TILE_SIZE;
		}
	}
}

static void	y_negative(t_game *game, t_point collision_tile)
{
	if (game->map.array[collision_tile.y][collision_tile.x] == '1')
	{
		game->enemy_dir.y = 1;
		game->enemy_pos.y = collision_tile.y * TILE_SIZE + TILE_SIZE;
	}
	if (game->enemy_pos.x % TILE_SIZE != 0)
	{
		collision_tile.x++;
		if (game->map.array[collision_tile.y][collision_tile.x] == '1')
		{
			game->enemy_dir.y = 1;
			game->enemy_pos.y = collision_tile.y * TILE_SIZE + TILE_SIZE;
		}
	}
}

void	enemy_y_collisions(t_game *game)
{
	t_point	collision_tile;

	if (game->enemy_dir.y > 0)
	{
		collision_tile.x = game->enemy_pos.x / TILE_SIZE;
		collision_tile.y = (game->enemy_pos.y + TILE_SIZE) / TILE_SIZE;
		y_positive(game, collision_tile);
	}
	else
	{
		collision_tile.x = game->enemy_pos.x / TILE_SIZE;
		collision_tile.y = game->enemy_pos.y / TILE_SIZE;
		y_negative(game, collision_tile);
	}
}
