/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamieta <anamieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 18:07:34 by anamieta          #+#    #+#             */
/*   Updated: 2024/04/09 14:38:51 by anamieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libraries/MLX42/include/MLX42/MLX42.h" // is that necessary if I have it included in so_long.h?

int	main(int argc, char **argv)
{
	char	**array;
	mlx_t	*mlx;

	if (argc != 2)
		error_handling(NULL, "Wrong number of arguments, dude");
	array = create_array(argv[1]);
	map_validity(array, argv[1]);
	mlx = mlx_init(1000, 1000, "So Long", true);
	mlx_loop(mlx);
	free(array);
	return (0);
}
