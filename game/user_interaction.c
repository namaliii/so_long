/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   user_interaction.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamieta <anamieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 17:29:18 by anamieta          #+#    #+#             */
/*   Updated: 2024/04/12 20:13:08 by anamieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"


void	my_keyhook(mlx_key_data_t keydata, void* param)
{
	t_map	*map;
	t_point	player_copy;
	char	**array;
	int		melon_count;

	map = (t_map *)param;
	player_copy = map->player;
	array = map->array;
	if ((keydata.key == MLX_KEY_A || keydata.key == MLX_KEY_LEFT)
		&& keydata.action == MLX_PRESS)
		player_copy.x -= 1;
	else if ((keydata.key == MLX_KEY_D || keydata.key == MLX_KEY_RIGHT)
		&& keydata.action == MLX_PRESS)
		player_copy.x += 1;
	else if ((keydata.key == MLX_KEY_W || keydata.key == MLX_KEY_UP)
		&& keydata.action == MLX_PRESS)
		player_copy.y -= 1;
	else if ((keydata.key == MLX_KEY_S || keydata.key == MLX_KEY_DOWN)
		&& keydata.action == MLX_PRESS)
		player_copy.y += 1;

	if (array[player_copy.y][player_copy.x] == '1')
		return ;
	else
	{
		map->player.x = player_copy.x;
		map->player.y = player_copy.y;
		if (array[player_copy.y][player_copy.x] == 'C')
		{
			// stop displaying melon!
			melon_count++;
		}
		if ((array[player_copy.y][player_copy.x] == 'E') && melon_count = num_of_melons)
			exit(EXIT_SUCCESS);
	}

position player_copy is a wall and if not then return
if its collectible collect
collectible pick up number deduct one when I encounter the position of C
if its 0 then exit if step on the exit

if its not a 1 then update player position

	// what if it is MLX_REPEAT
	make a function that counts the melons and put it into game struct
	do something about the randomly flying enemy and their encounter
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
