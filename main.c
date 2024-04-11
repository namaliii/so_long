/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamieta <anamieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 18:07:34 by anamieta          #+#    #+#             */
/*   Updated: 2024/04/11 20:39:54 by anamieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	update(void *param)
{
	t_game *game;
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
	animate();
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