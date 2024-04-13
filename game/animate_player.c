/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animate_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamieta <anamieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 13:06:58 by anamieta          #+#    #+#             */
/*   Updated: 2024/04/13 15:44:59 by anamieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	animate_idle_left(mlx_image_t **img, int num_imgs, t_game *game)
{
	static int	frame_counter = 0;
	static int	current_frame = 0;

	img[current_frame]->enabled = false;
	if (++frame_counter == 10)
	{
		frame_counter = 0;
		current_frame = (current_frame + 1) % num_imgs;
		ft_printf("Current frame: %d\n", current_frame);
	}
	img[current_frame]->enabled = true;
	img[current_frame]->instances[0].x = game->map.player.x * TILE_SIZE;
	img[current_frame]->instances[0].y = game->map.player.y * TILE_SIZE;
}

void	animate_idle_right(mlx_image_t **img, int num_imgs, t_game *game)
{
	static int	frame_counter = 0;
	static int	current_frame = 0;

	img[current_frame]->enabled = false;
	if (++frame_counter == 10)
	{
		frame_counter = 0;
		current_frame = (current_frame + 1) % num_imgs;
		ft_printf("Current frame: %d\n", current_frame);
	}
	img[current_frame]->enabled = true;
	img[current_frame]->instances[0].x = game->map.player.x * TILE_SIZE;
	img[current_frame]->instances[0].y = game->map.player.y * TILE_SIZE;
}

void	animate_run_right(mlx_image_t **img, int num_imgs, t_game *game)
{
	static int	frame_counter = 0;
	static int	current_frame = 0;

	img[current_frame]->enabled = false;
	if (++frame_counter == 10)
	{
		frame_counter = 0;
		current_frame = (current_frame + 1) % num_imgs;
		ft_printf("Current frame: %d\n", current_frame);
	}
	img[current_frame]->enabled = true;
	img[current_frame]->instances[0].x = game->map.player.x * TILE_SIZE;
	img[current_frame]->instances[0].y = game->map.player.y * TILE_SIZE;
}

void	animate_run_left(mlx_image_t **img, int num_imgs, t_game *game)
{
	static int	frame_counter = 0;
	static int	current_frame = 0;

	img[current_frame]->enabled = false;
	if (++frame_counter == 10)
	{
		frame_counter = 0;
		current_frame = (current_frame + 1) % num_imgs;
		ft_printf("Current frame: %d\n", current_frame);
	}
	img[current_frame]->enabled = true;
	img[current_frame]->instances[0].x = game->map.player.x * TILE_SIZE;
	img[current_frame]->instances[0].y = game->map.player.y * TILE_SIZE;
}
