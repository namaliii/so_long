/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamieta <anamieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 18:07:34 by anamieta          #+#    #+#             */
/*   Updated: 2024/04/16 16:13:30 by anamieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_exit(t_game *game, int exit_code, char *str)
{
	if (game->mlx)
	{
		mlx_terminate(game->mlx);
		mlx_close_window(game->mlx);
	}
	if (exit_code == EXIT_SUCCESS)
		ft_printf("gz gz, you won the game!\n");
	else
		ft_printf("%s\n", str);
	free_2d_array(game->map.array);
	exit(exit_code);
}

void	free_2d_array(char **array)
{
	int	i;

	i = 0;
	if (!array)
		return ;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

static void	animate_all(t_game *game)
{
	animate_player(game->player, NUM_PL_IMGS, game);
	animate_exit(game->exit, NUM_EXIT_IMGS);
	animate_enemy(game, game->enemy, NUM_ENEMY_IMGS);
	animate_melon(game->collectible, NUM_COLLECT_IMGS);
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
	animate_all(game);
	enemy_player_collisions(game, enemy_hitbox, player_hitbox);
}

int	main(int argc, char **argv)
{
	static t_game	game;
	t_point			monitor_size;

	if (argc != 2)
		error_handling(&game, game.map.array,
			"Wrong number of arguments, dude");
	valid_extension(&game, argv[1]);
	game.map.array = create_array(&game, argv[1]);
	map_validity(&game, argv[1]);
	game.mlx = mlx_init(game.map.size.x * TILE_SIZE,
			game.map.size.y * TILE_SIZE, "So Long", false);
	mlx_get_monitor_size(0, &monitor_size.x, &monitor_size.y);
	if (game.map.size.x > monitor_size.x || game.map.size.y > monitor_size.y)
		ft_exit(&game, EXIT_FAILURE, "Map bigger than the screen size!");
	load_images(&game);
	render_map(&game);
	mlx_key_hook(game.mlx, my_keyhook, (void *)&game);
	mlx_loop_hook(game.mlx, update, (void *)&game);
	mlx_loop(game.mlx);
	free_2d_array(game.map.array);
	return (0);
}

// void	check_leaks(void)
// {
// 	system("leaks so_long");
// }
// atexit(check_leaks);