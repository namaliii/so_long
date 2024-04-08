/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamieta <anamieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 18:07:34 by anamieta          #+#    #+#             */
/*   Updated: 2024/04/08 14:59:20 by anamieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include "../libraries/MLX42/include/MLX42/MLX42.h"

int	main(int argc, char **argv)
{
	if (argc != 2)
		error_handling("Wrong number of arguments, dude");
	map_validity(argv[1]);

	mlx_t *mlx = mlx_init(1000, 1000 , "So Long", true);
	mlx_loop(mlx);
	return (0);
}
