/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_variables.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamieta <anamieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 13:05:39 by anamieta          #+#    #+#             */
/*   Updated: 2024/04/12 16:37:07 by anamieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	render_idle(t_game *game, int x, int y)
{
	int	i;

	i = 0;
	while (i < NUM_IDLE_IMGS)
	{
		mlx_image_to_window(game->mlx, game->idle_right[i],
			x * game->idle_right[i]->width,
			y * game->idle_right[i]->height);
		game->idle_right[i]->enabled = false;
		i++;
	}
	game->idle_right[0]->enabled = true;
	i = 0;
	while (i < NUM_IDLE_IMGS)
	{
		mlx_image_to_window(game->mlx, game->idle_left[i],
			x * game->idle_left[i]->width,
			y * game->idle_left[i]->height);
		game->idle_left[i]->enabled = false;
		i++;
	}
}

void	render_run(t_game *game, int x, int y)
{
	int	i;

	i = 0;
	while (i < NUM_RUN_IMGS)
	{
		mlx_image_to_window(game->mlx, game->run_left[i],
			x * game->run_left[i]->width,
			y * game->run_left[i]->height);
		game->run_left[i]->enabled = false;
		i++;
	}
	i = 0;
	while (i < NUM_RUN_IMGS)
	{
		mlx_image_to_window(game->mlx, game->run_right[i],
			x * game->run_right[i]->width,
			y * game->run_right[i]->height);
		game->run_right[i]->enabled = false;
		i++;
	}
}

void	render_melon(t_game *game, int x, int y)
{
	int	i;

	i = 0;
	while (i < NUM_COLLECT_IMGS)
	{
		mlx_image_to_window(game->mlx, game->exit[i],
			x * game->collectible[i]->width,
			y * game->collectible[i]->height);
		game->collectible[i]->enabled = false;
		i++;
	}
	game->collectible[0]->enabled = true;
}
