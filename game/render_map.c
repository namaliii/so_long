/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamieta <anamieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 17:12:08 by anamieta          #+#    #+#             */
/*   Updated: 2024/04/12 16:41:13 by anamieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	render_exit(t_game *game, int x, int y)
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
	game->exit[0]->enabled = true;
}

void	render_enemy(t_game *game, int x, int y)
{
	int	i;

	i = 0;
	while (i < NUM_ENEMY_IMGS)
	{
		mlx_image_to_window(game->mlx, game->enemy[i],
			x * game->enemy[i]->width,
			y * game->enemy[i]->height);
		game->enemy[i]->enabled = false;
		i++;
	}
	game->enemy[0]->enabled = true;
}

void	render_background(t_game *game, int x, int y)
{
	mlx_image_to_window(game->mlx, game->background[0],
		x * game->background[0]->width,
		y * game->background[0]->height);
	mlx_image_to_window(game->mlx, game->background[1],
		x * game->background[1]->width,
		y * game->background[1]->height);
	game->background[0]->enabled = 0;
}

static void	render_helper_f(t_game *game, int x, int y)
{
	if (game->map.array[y][x] == '1')
		mlx_image_to_window(game->mlx, game->wall,
			x * game->wall->width, y * game->wall->height);
	else if (game->map.array[y][x] != '\n')
		render_background(game, x, y);
	if (game->map.array[y][x] == 'P')
	{
		render_idle(game, x, y);
		render_run(game, x, y);
	}
	else if (game->map.array[y][x] == 'C')
		render_melon(game, x, y);
	else if (game->map.array[y][x] == 'E')
		render_exit(game, x, y);
	else if (y == game->map.enemy.y && x == game->map.enemy.x)
		render_enemy(game, x, y);
}

void	render_map(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (game->map.array[y])
	{
		x = 0;
		while (game->map.array[y][x])
		{
			render_helper_f(game, x, y);
			x++;
		}
		y++;
	}
}
