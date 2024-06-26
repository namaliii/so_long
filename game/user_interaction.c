/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   user_interaction.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamieta <anamieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 17:29:18 by anamieta          #+#    #+#             */
/*   Updated: 2024/04/16 15:34:30 by anamieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	get_melon_index(t_game *game)
{
	int	current;

	current = 0;
	while (current < game->map.melon_count)
	{
		if ((game->collectible[0]->instances[current].x
				== game->map.player.x * TILE_SIZE)
			&& (game->collectible[0]->instances[current].y
				== game->map.player.y * TILE_SIZE))
			return (current);
		current++;
	}
	return (-1);
}

void	collect_melons(t_game *game, char **array)
{
	int		melon_inx;
	int		imgs;

	imgs = 0;
	if (array[game->map.player_copy.y][game->map.player_copy.x] == 'C')
	{
		melon_inx = get_melon_index(game);
		while (imgs < NUM_COLLECT_IMGS)
		{
			if (melon_inx != (-1))
				game->collectible[imgs]->instances[melon_inx].enabled
					= false;
			imgs++;
		}
		game->map.array[game->map.player_copy.y][game->map.player_copy.x]
			= '0';
		game->map.collected++;

	}
}

static void	number_of_moves(t_game *game)
{
	char	*src;
	char	dst[4096];

	ft_memset(dst, 0, 4096);
	ft_printf("Number of moves: %d\n", game->map.display_moves);
	if (game->moves_counter_img)
		mlx_delete_image(game->mlx, game->moves_counter_img);
	src = ft_itoa(game->map.display_moves);
	ft_strlcpy(dst, "Number of moves: ", 4096);
	ft_strlcat(dst, src, 4096);
	free ((void *)src);
	game->moves_counter_img = mlx_put_string(game->mlx, dst,
			(((game->map.size.x / 2) * TILE_SIZE) - 2 * TILE_SIZE), 0);
}

void	move_and_collect(t_game *game)
{
	if (game->map.array[game->map.player_copy.y]
		[game->map.player_copy.x] == '1')
		return ;
	else
	{
		game->map.player.x = game->map.player_copy.x;
		game->map.player.y = game->map.player_copy.y;
		game->map.display_moves++;
		number_of_moves(game);
		collect_melons(game, game->map.array);
		if ((game->map.array[game->map.player_copy.y]
				[game->map.player_copy.x] == 'E')
			&& game->map.collected == game->map.melon_count)
			ft_exit(game, EXIT_SUCCESS, NULL);
	}
}

void	my_keyhook(mlx_key_data_t keydata, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	game->map.player_copy = game->map.player;
	if ((keydata.key == MLX_KEY_A || keydata.key == MLX_KEY_LEFT)
		&& keydata.action == MLX_PRESS)
		game->map.player_copy.x -= 1;
	else if ((keydata.key == MLX_KEY_D || keydata.key == MLX_KEY_RIGHT)
		&& keydata.action == MLX_PRESS)
		game->map.player_copy.x += 1;
	else if ((keydata.key == MLX_KEY_W || keydata.key == MLX_KEY_UP)
		&& keydata.action == MLX_PRESS)
		game->map.player_copy.y -= 1;
	else if ((keydata.key == MLX_KEY_S || keydata.key == MLX_KEY_DOWN)
		&& keydata.action == MLX_PRESS)
		game->map.player_copy.y += 1;
	else if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		ft_exit(game, EXIT_FAILURE, "You pressed ESC");
	if ((keydata.key == MLX_KEY_A || keydata.key == MLX_KEY_LEFT
			|| keydata.key == MLX_KEY_D || keydata.key == MLX_KEY_RIGHT
			|| keydata.key == MLX_KEY_W || keydata.key == MLX_KEY_UP
			|| keydata.key == MLX_KEY_S || keydata.key == MLX_KEY_DOWN)
		&& keydata.action == MLX_PRESS)
		move_and_collect(game);
}
