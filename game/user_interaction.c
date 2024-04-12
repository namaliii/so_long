/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   user_interaction.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamieta <anamieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 17:29:18 by anamieta          #+#    #+#             */
/*   Updated: 2024/04/12 18:11:27 by anamieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"


void	my_keyhook(mlx_key_data_t keydata, void* param)
{
	t_map	*map = (t_map *)param;

	if ((keydata.key == MLX_KEY_A || keydata.key == MLX_KEY_LEFT) && keydata.action == MLX_PRESS)
	{
		if (map->player.x - 1 == '1')
			return ;
		else
			map->player.x -= 1;
	}
	else if ((keydata.key == MLX_KEY_D || keydata.key == MLX_KEY_RIGHT) && keydata.action == MLX_PRESS)
	{
		if (map->player.x + 1 == '1')
			return ;
		else
			map->player.x += 1;
	}
	else if ((keydata.key == MLX_KEY_W || keydata.key == MLX_KEY_UP) && keydata.action == MLX_PRESS)
	{
		if (map->player.y - 1 == '1')
			return ;
		else
			map->player.y -= 1;
	}
	else if ((keydata.key == MLX_KEY_S || keydata.key == MLX_KEY_DOWN) && keydata.action == MLX_PRESS)
	{
		if (map->player.y + 1 == '1')
			return ;
		else
		map->player.y += 1;
	}

	// what if it is MLX_REPEAT
}

void    player_collisions(t_map *map, char **array, bool is_dead)
{
    is_dead = false;
    if (map->player.x == map->collectible.x && map->player.y == map->collectible.y)
        array[player.y][player.x] = 'P'; // or just collectible dissapears
    else if (map->player.x == map->enemy.x && map->player.y == map->enemy.y)
        is_dead = true;
    if (is_dead)
        exit(0); // EXIT_FAILURE?
    if (map->player.x == map->exit.x && map->player.y == map->exit.y)
        exit(EXIT_SUCCESS);

}

void	hop_hop_hop(t_game *game)
{
    animate_idle_right(game->idle_right, NUM_IDLE_IMGS);
    if (is pressed arrow right or D (and theres no wall (look my_keyhook)))
        animate_run_right
        go right
    else if (is pressed arrow left or A (and theres no wall (look my_keyhook)))
        animate_idle_right
    if (pressed again the above)
        animate_run_left
        go left
    else if (is pressed up)
        keep on animating the direction you had before on idle_left_imgs
        go UP
    else if (is pressed down)
        same as for up

by default player looks to the right. If user presses key go left, player turns left but doesnt move
if user presses key up or down the player moves in idle. Idle left if it was left before, idle right
if was right
when the key right/left is pressed he runs.

}

void    enemy_movement(t_point enemy)
{
    int i;
    i = rand() % 4;
}

void loop_hook(void *param)
{
	mlx_t	*mlx;
	static int counter = 0;

	mlx = param;
	if (mlx_is_key_down(mlx, MLX_KEY_W))
	{
		counter++;
		if(counter % 10 == 0) //that's in the animate functions
			move();
	}
}

void	hook(void *param)
{
	mlx_t	*mlx;

	mlx = param;
	if (mlx_is_key_down(param, MLX_KEY_ESCAPE))
		mlx_close_window(param);
	if (mlx_is_key_down(param, MLX_KEY_UP))
		g_img->instances[0].y -= 5;
	if (mlx_is_key_down(param, MLX_KEY_DOWN))
		g_img->instances[0].y += 5;
	if (mlx_is_key_down(param, MLX_KEY_LEFT))
		g_img->instances[0].x -= 5;
	if (mlx_is_key_down(param, MLX_KEY_RIGHT))
		g_img->instances[0].x += 5;
}
