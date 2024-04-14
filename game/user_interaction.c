/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   user_interaction.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamieta <anamieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 17:29:18 by anamieta          #+#    #+#             */
/*   Updated: 2024/04/14 17:47:53 by anamieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	get_melon_index(t_game *game)
{
	int	current;

	current = 0;
	while (current < game->map.melon_count)
	{
		if ((game->collectible[0]->instances[current].x == game->map.player.x * TILE_SIZE)
		&& (game->collectible[0]->instances[current].y == game->map.player.y * TILE_SIZE))
			return (current);
		current++;
	}
	return (-1);
}

void	my_keyhook(mlx_key_data_t keydata, void* param)
{
	t_game	*game;
	t_point	player_copy;
	char	**array;
	int	melon_inx;
	int	imgs;

	game = (t_game *)param;
	player_copy = game->map.player;
	array = game->map.array;
	imgs = 0;
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
		game->map.player.x = player_copy.x;
		game->map.player.y = player_copy.y;
		if (array[player_copy.y][player_copy.x] == 'C')
		{
			melon_inx = get_melon_index(game);
			while (imgs < NUM_COLLECT_IMGS)
			{
				if (melon_inx != (-1))
					game->collectible[imgs]->instances[melon_inx].enabled
						= false;
				imgs++;
			}
			game->map.array[player_copy.y][player_copy.x] = '0';
			game->map.collected++;
			if (game->map.collected == game->map.melon_count - 1)
			{
				game->map.last_melon.x = player_copy.x;
				game->map.last_melon.y = player_copy.y;
			}
		}
		if ((array[player_copy.y][player_copy.x] == 'E')
			&& game->map.collected == game->map.melon_count)
			exit(EXIT_SUCCESS);
	}
}
