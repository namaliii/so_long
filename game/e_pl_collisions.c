/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   e_pl_collisions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamieta <anamieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 13:27:48 by anamieta          #+#    #+#             */
/*   Updated: 2024/04/16 14:12:01 by anamieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	enemy_pos_set(t_game *game)
{
	game->enemy_pos.x = game->map.exit.x * TILE_SIZE;
	game->enemy_pos.y = game->map.exit.y * TILE_SIZE;
	game->enemy_dir.x = 1;
	game->enemy_dir.y = 1;
}

static void	setting_enemy_corners(t_game *game, t_point enemy_hitbox)
{
	game->en_cor.upper_left.x = enemy_hitbox.x;
	game->en_cor.upper_left.y = enemy_hitbox.y;
	game->en_cor.upper_right.x = enemy_hitbox.x + TILE_SIZE / 2;
	game->en_cor.upper_right.y = enemy_hitbox.y;
	game->en_cor.lower_left.x = enemy_hitbox.x;
	game->en_cor.lower_left.y = enemy_hitbox.y + TILE_SIZE / 2;
	game->en_cor.lower_right.x = enemy_hitbox.x + TILE_SIZE / 2;
	game->en_cor.lower_right.y = enemy_hitbox.y + TILE_SIZE / 4;
}

void	enemy_player_collisions(t_game *game,
	t_point player_hitbox, t_point enemy_hitbox)
{
	setting_enemy_corners(game, enemy_hitbox);
	if ((player_hitbox.x <= game->en_cor.upper_left.x
			&& (player_hitbox.x + 32) >= game->en_cor.upper_left.x
			&& player_hitbox.y <= game->en_cor.upper_left.y
			&& (player_hitbox.y + 32) >= game->en_cor.upper_left.y)
		|| (player_hitbox.x <= game->en_cor.upper_right.x
			&& (player_hitbox.x + 32) >= game->en_cor.upper_right.x
			&& player_hitbox.y <= game->en_cor.upper_right.y
			&& (player_hitbox.y + 32) >= game->en_cor.upper_right.y)
		|| (player_hitbox.x <= game->en_cor.lower_left.x
			&& (player_hitbox.x + 32) >= game->en_cor.lower_left.x
			&& player_hitbox.y <= game->en_cor.lower_left.y
			&& (player_hitbox.y + 32) >= game->en_cor.lower_left.y)
		|| (player_hitbox.x <= game->en_cor.lower_right.x
			&& (player_hitbox.x + 32) >= game->en_cor.lower_right.x
			&& player_hitbox.y == game->en_cor.lower_right.y
			&& (player_hitbox.y + 32) >= game->en_cor.lower_right.y))
		ft_exit(game, EXIT_FAILURE, "You've been eaten by the monsterrr!");
}
