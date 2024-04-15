/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamieta <anamieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 18:07:34 by anamieta          #+#    #+#             */
/*   Updated: 2024/04/15 20:34:30 by anamieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


static void	enemy_player_collisions(t_point enemy_hitbox, t_point player_hitbox)
{
	t_point	upper_left;
	t_point	upper_right;
	t_point	lower_left;
	t_point	lower_right;

	upper_left.x = enemy_hitbox.x;
	upper_left.y = enemy_hitbox.y;
	upper_right.x = enemy_hitbox.x + TILE_SIZE / 2;
	upper_right.y = enemy_hitbox.y;
	lower_left.x = enemy_hitbox.x;
	lower_left.y = enemy_hitbox.y + TILE_SIZE / 2;
	lower_right.x = enemy_hitbox.x + TILE_SIZE / 2;
	lower_right.y = enemy_hitbox.y + TILE_SIZE / 4;
	if ((player_hitbox.x <= upper_left.x
			&& (player_hitbox.x + 32) >= upper_left.x
			&& player_hitbox.y <= upper_left.y
			&& (player_hitbox.y + 32) >= upper_left.y)
		|| (player_hitbox.x <= upper_right.x
			&& (player_hitbox.x + 32) >= upper_right.x
			&& player_hitbox.y <= upper_right.y
			&& (player_hitbox.y + 32) >= upper_right.y)
		|| (player_hitbox.x <= lower_left.x
			&& (player_hitbox.x + 32) >= lower_left.x
			&& player_hitbox.y <= lower_left.y
			&& (player_hitbox.y + 32) >= lower_left.y)
		|| (player_hitbox.x <= lower_right.x
			&& (player_hitbox.x + 32) >= lower_right.x
			&& player_hitbox.y == lower_right.y
			&& (player_hitbox.y + 32) >= lower_right.y))
	{
		ft_printf("You've been eaten by the monster");
		exit(0);
	}
}

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
		collision_tile.y = (game->enemy_pos.y / TILE_SIZE);
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
	t_point			enemy_hitbox;
	t_point			player_hitbox;
	static int		cool_down;

	game = (t_game *)param;
	game->enemy_pos.x += game->enemy_dir.x;
	enemy_x_collisions(game);
	game->enemy_pos.y += game->enemy_dir.y;
	enemy_y_collisions(game);
	player_hitbox.x = game->map.player.x * TILE_SIZE + TILE_SIZE / 4;
	player_hitbox.y = game->map.player.y * TILE_SIZE + TILE_SIZE / 4;
	enemy_hitbox.x = game->enemy_pos.x + TILE_SIZE / 4;
	enemy_hitbox.y = game->enemy_pos.y + TILE_SIZE / 4;
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
	enemy_player_collisions(enemy_hitbox, player_hitbox);
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
