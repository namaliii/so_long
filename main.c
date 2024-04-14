/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamieta <anamieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 18:07:34 by anamieta          #+#    #+#             */
/*   Updated: 2024/04/14 20:22:29 by anamieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void 	enemy_y_collisions(t_game *game)
{
	t_point	collision_tile;

	if (game->enemy_dir.y > 0)
	{
		collision_tile.x = game->enemy_pos.x / TILE_SIZE;
		collision_tile.y = (game->enemy_pos.y + TILE_SIZE) / TILE_SIZE;
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
	else
	{
		collision_tile.x = game->enemy_pos.x / TILE_SIZE;
		collision_tile.y = game->enemy_pos.y / TILE_SIZE;
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
}

void enemy_x_collisions(t_game *game)
{
	t_point	collision_tile;

	if (game->enemy_dir.x > 0)
	{
		collision_tile.x = (game->enemy_pos.x + TILE_SIZE) / TILE_SIZE;
		collision_tile.y = (int)(game->enemy_pos.y / TILE_SIZE);
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
	else
	{
		collision_tile.x = game->enemy_pos.x / TILE_SIZE;
		collision_tile.y = game->enemy_pos.y / TILE_SIZE;
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
}

void	update(void *param)
{
	t_game			*game;
	static int		cool_down;

	game = (t_game *)param;
	game->enemy_pos.x += game->enemy_dir.x;
	enemy_x_collisions(game);
	game->enemy_pos.y += game->enemy_dir.y;
	enemy_y_collisions(game);
	if (cool_down <= 0)
	{
		game->background[0]->enabled = !game->background[0]->enabled;
		game->background[1]->enabled = !game->background[1]->enabled;
		cool_down = 30;
	}
	else
		cool_down--;
	animate_player(game->player, NUM_PL_IMGS, game);
	animate_exit(game->exit, NUM_EXIT_IMGS);
	animate_enemy(game, game->enemy, NUM_ENEMY_IMGS);
	animate_melon(game->collectible, NUM_COLLECT_IMGS);
}

int	main(int argc, char **argv)
{
	static t_game	game;
	t_point			monitor_size;

	if (argc != 2)
		error_handling(NULL, "Wrong number of arguments, dude");
	game.map.array = create_array(argv[1]);
	map_validity(&game, argv[1]);
	game.mlx = mlx_init(game.map.size.x * TILE_SIZE,
			game.map.size.y * TILE_SIZE, "So Long", false);
	mlx_get_monitor_size(0, &monitor_size.x, &monitor_size.y);
	if (game.map.size.x > monitor_size.x || game.map.size.y > monitor_size.y)
		exit (EXIT_FAILURE); // and free
	load_images(&game);
	render_map(&game);
	mlx_key_hook(game.mlx, my_keyhook, (void *)&game);
	mlx_loop_hook(game.mlx, update, (void *)&game);
	mlx_loop(game.mlx);
	free(game.map.array);
	//free structs
	return (0);
}
