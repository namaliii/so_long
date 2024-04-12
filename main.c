/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamieta <anamieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 18:07:34 by anamieta          #+#    #+#             */
/*   Updated: 2024/04/12 17:28:49 by anamieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	update(void *param)
{
	t_game			*game;
	static int		cool_down;

	game = (t_game *)param;
	if (cool_down <= 0)
	{
		game->background[0]->enabled = !game->background[0]->enabled;
		game->background[1]->enabled = !game->background[1]->enabled;
		cool_down = 30;
	}
	else
		cool_down--;
	if (game->player_direction == RIGHT)
	{
		// disable_everything(game->idle_left);
		animate_idle_right(game->idle_right, NUM_IDLE_IMGS);
	}
	animate_idle_left(game->idle_left, NUM_IDLE_IMGS);
	animate_run_right(game->run_right, NUM_RUN_IMGS);
	animate_run_left(game->run_left, NUM_RUN_IMGS);
	animate_exit(game->exit, NUM_EXIT_IMGS);
	animate_enemy(game->enemy, NUM_ENEMY_IMGS);
	animate_melon(game->collectible, NUM_COLLECT_IMGS);
}

int	main(int argc, char **argv)
{
	static t_game	game;

	if (argc != 2)
		error_handling(NULL, "Wrong number of arguments, dude");
	game.map.array = create_array(argv[1]);
	map_validity(&game, argv[1]);
	game.mlx = mlx_init(1000, 1000, "So Long", true);
	load_images(&game);
	render_map(&game);
	mlx_loop_hook(game.mlx, update, (void *)&game);
	mlx_loop(game.mlx);
	free(game.map.array);
	//free structs
	return (0);
}

// fulfill the elements in the struct in the map parsing functions like
//