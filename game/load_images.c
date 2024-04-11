/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamieta <anamieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 17:12:08 by anamieta          #+#    #+#             */
/*   Updated: 2024/04/11 20:55:45 by anamieta         ###   ########.fr       */
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

int	load_images(t_game *game)
{
	if (background_imgs(game) || wall_img(game) || idle_right_imgs(game)
		|| idle_left_imgs(game) || run_left_imgs(game) || run_right_imgs(game)
		|| melon_imgs(game) || exit_imgs(game) || enemy_imgs(game))
		return (1);
	return (0);
}

void	render_map(t_game *game)
{
	int	x;
	int	y;
	int i;

	i = 0;
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
			{
				mlx_image_to_window(game->mlx, game->background[0],
					x * game->background[0]->width,
					y * game->background[0]->height);
				mlx_image_to_window(game->mlx, game->background[1],
					x * game->background[1]->width,
					y * game->background[1]->height);
				game->background[0]->enabled = 0;
			}
			if (game->map.array[y][x] == 'P')
			{
				while (i < NUM_IDLE_IMGS)
				{
					mlx_image_to_window(game->mlx, game->idle_right[i],
						x * game->idle_right[i]->width,
						y * game->idle_right[i]->height);
					game->idle_right[i]->enabled = 0;
					i++;
				}
				game->idle_right[0]->enabled = 1;
				i = 0;
				while (i < NUM_IDLE_IMGS)
				{
					mlx_image_to_window(game->mlx, game->idle_left[i],
						x * game->idle_left[i]->width,
						y * game->idle_left[i]->height);
					game->idle_left[i]->enabled = 0;
					i++;
				}
				i = 0;
				while (i < NUM_RUN_IMGS)
				{
					mlx_image_to_window(game->mlx, game->run_left[i],
						x * game->run_left[i]->width,
						y * game->run_left[i]->height);
					game->run_left[i]->enabled = 0;
					i++;
				}
				i = 0;
				while (i < NUM_RUN_IMGS)
				{
					mlx_image_to_window(game->mlx, game->run_right[i],
						x * game->run_right[i]->width,
						y * game->run_right[i]->height);
					game->run_right[i]->enabled = 0;
					i++;
				}
			}
			else if (game->map.array[y][x] == 'C')
			{
				i = 0;
				while (i < NUM_COLLECT_IMGS)
				{
					mlx_image_to_window(game->mlx, game->exit[i],
						x * game->collectible[i]->width,
						y * game->collectible[i]->height);
					game->collectible[i]->enabled = 0;
					i++;
				}
				game->collectible[0]->enabled = 1;
			}
			else if (game->map.array[y][x] == 'E')
			{
				i = 0;
				while (i < NUM_EXIT_IMGS)
				{
					mlx_image_to_window(game->mlx, game->exit[i],
						x * game->exit[i]->width,
						y * game->exit[i]->height);
					game->exit[i]->enabled = 0;
					i++;
				}
				game->exit[0]->enabled = 1;
			}
			x++;
		}
		y++;
	}
}

void	animate(mlx_image_t **img, int **index, int num_imgs)
{
	int	i;

	i = 0;
	if index > num_imgs
		index = 0;
	setting all to false enabled
	1 to enabled
	while (i < num_imgs)
	{

		usleep(100000);
		i++;
	}
}

