/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animate_rest.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamieta <anamieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 13:20:04 by anamieta          #+#    #+#             */
/*   Updated: 2024/04/14 17:53:35 by anamieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	animate_player(mlx_image_t **img, int num_imgs, t_game *game)
{
	static int	frame_counter = 0;
	static int	current_frame = 0;

	img[current_frame]->enabled = false;
	if (++frame_counter == 10)
	{
		frame_counter = 0;
		current_frame = (current_frame + 1) % num_imgs;
	}
	img[current_frame]->enabled = true;
	img[current_frame]->instances[0].x = game->map.player.x * TILE_SIZE;
	img[current_frame]->instances[0].y = game->map.player.y * TILE_SIZE;
}

void	animate_melon(mlx_image_t **img, int num_imgs)
{
	static int	frame_counter = 0;
	static int	current_frame = 0;

	img[current_frame]->enabled = false;
	if (++frame_counter == 10)
	{
		frame_counter = 0;
		current_frame = (current_frame + 1) % num_imgs;
	}
	img[current_frame]->enabled = true;
}

void	animate_enemy(t_game *game, mlx_image_t **img, int num_imgs)
{
	static int	frame_counter = 0;
	static int	current_frame = 0;

	img[current_frame]->enabled = false;
	if (++frame_counter == 10)
	{
		frame_counter = 0;
		current_frame = (current_frame + 1) % num_imgs;
	}
	img[current_frame]->instances[0].x = game->enemy_pos.x;
	img[current_frame]->instances[0].y = game->enemy_pos.y;
	img[current_frame]->enabled = true;
}

void	animate_exit(mlx_image_t **img, int num_imgs)
{
	static int	frame_counter = 0;
	static int	current_frame = 0;

	img[current_frame]->enabled = false;
	if (++frame_counter == 10)
	{
		frame_counter = 0;
		current_frame = (current_frame + 1) % num_imgs;
	}
	img[current_frame]->enabled = true;
}
