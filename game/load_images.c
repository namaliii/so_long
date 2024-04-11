/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamieta <anamieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 17:12:08 by anamieta          #+#    #+#             */
/*   Updated: 2024/04/11 18:45:50 by anamieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

mlx_image_t	*load_image(const char *path, t_game *game)
{
	mlx_texture_t	*texture;
	mlx_image_t		*img;

	texture = mlx_load_png(path);
	if (!texture)
		return (NULL);
	img = mlx_texture_to_image(game->mlx, texture);
	if (!img)
		return (NULL);
	mlx_resize_image(img, 64, 64);
	return (img);
}

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
			else if (game->map.array[y][x] != '\n' )
				mlx_image_to_window(game->mlx, game->background,
					x * game->background->width, y * game->background->height);
			if (game->map.array[y][x] == 'P')
				mlx_image_to_window(game->mlx, game->player,
					x * game->player->width, y * game->player->height);
			else if (game->map.array[y][x] == 'C')
				mlx_image_to_window(game->mlx, game->collectible,
					x * game->collectible->width,
					y * game->collectible->height);
			else if (game->map.array[y][x] == 'E')
				mlx_image_to_window(game->mlx, game->exit,
					x * game->exit->width, y * game->exit->height);
			x++;
		}
		y++;
	}
}

void	animate(t_game *game)
{
	int	i;

	i = 0;
	while (game->background[i] != NULL)
	{
		mlx_image_to_window(game->mlx, game->background[i], i * game->background[i]->width, y * game->background[i]->height);
		i++;
	}
}
