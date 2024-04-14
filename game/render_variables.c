/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_variables.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamieta <anamieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 13:05:39 by anamieta          #+#    #+#             */
/*   Updated: 2024/04/14 17:56:39 by anamieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	exit_img_to_window(t_game *game, int x, int y)
{
	int	i;

	i = 0;
	while (i < NUM_EXIT_IMGS)
	{
		mlx_image_to_window(game->mlx, game->exit[i],
			x * game->exit[i]->width,
			y * game->exit[i]->height);
		game->exit[i]->enabled = false;
		i++;
	}
}

void	enemy_img_to_window(t_game *game)
{
	int	i;

	i = 0;
	while (i < NUM_ENEMY_IMGS)
	{
		mlx_image_to_window(game->mlx, game->enemy[i],
			game->enemy_pos.x,
			game->enemy_pos.y);
		game->enemy[i]->enabled = false;
		i++;
	}
}

void	background_img_to_window(t_game *game, int x, int y)
{
	mlx_image_to_window(game->mlx, game->background[0],
		x * game->background[0]->width,
		y * game->background[0]->height);
	mlx_image_to_window(game->mlx, game->background[1],
		x * game->background[1]->width,
		y * game->background[1]->height);
	game->background[0]->enabled = 0;
}

void	player_img_to_window(t_game *game, int x, int y)
{
	int	i;

	i = 0;
	while (i < NUM_PL_IMGS)
	{
		mlx_image_to_window(game->mlx, game->player[i],
			x * game->player[i]->width,
			y * game->player[i]->height);
		game->player[i]->enabled = false;
		i++;
	}
}

void	melon_img_to_window(t_game *game, int x, int y)
{
	int	i;

	i = 0;
	while (i < NUM_COLLECT_IMGS)
	{
		mlx_image_to_window(game->mlx, game->collectible[i],
			x * game->collectible[i]->width,
			y * game->collectible[i]->height);
		game->collectible[i]->enabled = false;
		i++;
	}
}
