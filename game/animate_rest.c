/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animate_rest.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamieta <anamieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 13:20:04 by anamieta          #+#    #+#             */
/*   Updated: 2024/04/12 17:13:43 by anamieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	animate_melon(mlx_image_t **img, int num_imgs)
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
}

void	animate_enemy(mlx_image_t **img, int num_imgs)
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
		ft_printf("Current frame: %d\n", current_frame);
	}
	img[current_frame]->enabled = true;
}

// void	my_keyhook(mlx_key_data_t keydata, void* param)
// {
// 	t_map	*map = (t_map *)param;

// 	if ((keydata.key == MLX_KEY_A || keydata.key == MLX_KEY_LEFT) && keydata.action == MLX_PRESS)
// 	{
// 		if (map->player.x - 1 == '1')
// 			return ;
// 		else
// 			map->player.x -= 1;
// 	}
// 	else if ((keydata.key == MLX_KEY_D || keydata.key == MLX_KEY_RIGHT) && keydata.action == MLX_PRESS)
// 	{
// 		if (map->player.x + 1 == '1')
// 			return ;
// 		else
// 			map->player.x += 1;
// 		map->player.x += 1;
// 	}
// 	else if ((keydata.key == MLX_KEY_W || keydata.key == MLX_KEY_UP) && keydata.action == MLX_PRESS)
// 	{
// 		if (map->player.y - 1 == '1')
// 			return ;
// 		else
// 			map->player.y -= 1;
// 	}
// 	else if ((keydata.key == MLX_KEY_S || keydata.key == MLX_KEY_DOWN) && keydata.action == MLX_PRESS)
// 	{
// 		if (map->player.y + 1 == '1')
// 			return ;
// 		else
// 		map->player.y += 1;
// 	}

// 	// what if it is MLX_REPEAT
// }
// by default player looks to the right. If user presses key go left, player turns left but doesnt move
// if user presses key up or down the player moves in idle. Idle left if it was left before, idle right
// if was right
// when the key right/left is pressed he runs.

// void	hop_hop_hop(t_game *game)
// {
// 	animate(game->idle_right, NUM_IDLE_IMGS);

// 	my_keyhook(keydata ?????, game->map);
// }

// void loop_hook(void *param)
// {
// 	mlx_t	*mlx;
// 	static int counter = 0;

// 	mlx = param;
// 	if (mlx_is_key_down(mlx, MLX_KEY_W))
// 	{
// 		counter++;
// 		if(counter % 10 == 0)
// 			move();
// 	}
// }

// void	hook(void *param)
// {
// 	mlx_t	*mlx;

// 	mlx = param;
// 	if (mlx_is_key_down(param, MLX_KEY_ESCAPE))
// 		mlx_close_window(param);
// 	if (mlx_is_key_down(param, MLX_KEY_UP))
// 		g_img->instances[0].y -= 5;
// 	if (mlx_is_key_down(param, MLX_KEY_DOWN))
// 		g_img->instances[0].y += 5;
// 	if (mlx_is_key_down(param, MLX_KEY_LEFT))
// 		g_img->instances[0].x -= 5;
// 	if (mlx_is_key_down(param, MLX_KEY_RIGHT))
// 		g_img->instances[0].x += 5;
// }
