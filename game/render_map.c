/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamieta <anamieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 17:12:08 by anamieta          #+#    #+#             */
/*   Updated: 2024/04/14 17:59:53 by anamieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	render_map(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (game->map.array[y])
	{
		x = 0;
		while (game->map.array[y][x])
		{
			if (game->map.array[y][x] == '1')
				mlx_image_to_window(game->mlx, game->wall,
					x * game->wall->width, y * game->wall->height);
			else if (game->map.array[y][x] != '\n')
				background_img_to_window(game, x, y);
			if (game->map.array[y][x] == 'C')
				melon_img_to_window(game, x, y);
			x++;
		}
		y++;
	}
	exit_img_to_window(game, game->map.exit.x, game->map.exit.y);
	enemy_img_to_window(game);
	player_img_to_window(game, game->map.player.x, game->map.player.y);
}
