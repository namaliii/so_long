/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamieta <anamieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 18:07:34 by anamieta          #+#    #+#             */
/*   Updated: 2024/04/11 18:02:02 by anamieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	static t_game	game;

	if (argc != 2)
		error_handling(NULL, "Wrong number of arguments, dude");
	game.map.array = create_array(argv[1]);
	map_validity(&game, argv[1]);
	game.mlx = mlx_init(1000, 1000, "So Long", true);
	load_images(&game);
	while (1)
		render_map(&game);
	mlx_loop(game.mlx);
	free(game.map.array);
	//free structs
	return (0);
}

// fulfill the elements in the struct in the map parsing functions like
//