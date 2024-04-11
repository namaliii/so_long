/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images_contents.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamieta <anamieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 12:38:59 by anamieta          #+#    #+#             */
/*   Updated: 2024/04/11 12:51:38 by anamieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	load_player_idle(t_game *game)
{
	char	*player_idle;

	player_idle[0]= load_image("images/idle/idle1.png", game);
	player_idle[1]= load_image("images/idle/idle2.png", game);
	player_idle[2]= load_image("images/idle/idle3.png", game);
	player_idle[3]= load_image("images/idle/idle4.png", game);
	player_idle[4]= load_image("images/idle/idle5.png", game);
	player_idle[5]= load_image("images/idle/idle6.png", game);
	player_idle[6]= load_image("images/idle/idle7.png", game);
	player_idle[7]= load_image("images/idle/idle8.png", game);
	player_idle[8]= load_image("images/idle/idle9.png", game);
	player_idle[9]= load_image("images/idle/idle10.png", game);
	player_idle[10]= load_image("images/idle/idle11.png", game);
}

void	load_melon(t_game *game)
{
	char	*collectible;

	collectible[0] = load_image("images/melon/Melon_1.png", game);
	collectible[1] = load_image("images/melon/Melon_2.png", game);
	collectible[2] = load_image("images/melon/Melon_3.png", game);
	collectible[3] = load_image("images/melon/Melon_4.png", game);
	collectible[4] = load_image("images/melon/Melon_5.png", game);
	collectible[5] = load_image("images/melon/Melon_6.png", game);
	collectible[6] = load_image("images/melon/Melon_7.png", game);
	collectible[7] = load_image("images/melon/Melon_8.png", game);
	collectible[8] = load_image("images/melon/Melon_9.png", game);
	collectible[9] = load_image("images/melon/Melon_10.png", game);
	collectible[10] = load_image("images/melon/Melon_11.png", game);
	collectible[11] = load_image("images/melon/Melon_12.png", game);
	collectible[12] = load_image("images/melon/Melon_13.png", game);
	collectible[13] = load_image("images/melon/Melon_14.png", game);
	collectible[14] = load_image("images/melon/Melon_15.png", game);
	collectible[15] = load_image("images/melon/Melon_16.png", game);
	collectible[16] = load_image("images/melon/Melon_17.png", game);
}

char	*load_run_right(t_game *game)
{
	char	*run_right;

	run_right[0]= load_image("images/run-right/Run-right_1.png", game);
	run_right[1]= load_image("images/run-right/Run-right_2.png", game);
	run_right[2]= load_image("images/run-right/Run-right_3.png", game);
	run_right[3]= load_image("images/run-right/Run-right_4.png", game);
	run_right[4]= load_image("images/run-right/Run-right_5.png", game);
	run_right[5]= load_image("images/run-right/Run-right_6.png", game);
	run_right[6]= load_image("images/run-right/Run-right_7.png", game);
	run_right[7]= load_image("images/run-right/Run-right_8.png", game);
	run_right[8]= load_image("images/run-right/Run-right_9.png", game);
	run_right[9]= load_image("images/run-right/Run-right_10.png", game);
	run_right[10]= load_image("images/run-right/Run-right_11.png", game);
	run_right[11]= load_image("images/run-right/Run-right_12.png", game);
}

void	load_run_left(t_game *game)
{
	char	*run_left;

	run_left[0]= load_image("images/run-left/Run-left_1.png", game);
	run_left[1]= load_image("images/run-left/Run-left_2.png", game);
	run_left[2]= load_image("images/run-left/Run-left_3.png", game);
	run_left[3]= load_image("images/run-left/Run-left_4.png", game);
	run_left[4]= load_image("images/run-left/Run-left_5.png", game);
	run_left[5]= load_image("images/run-left/Run-left_6.png", game);
	run_left[6]= load_image("images/run-left/Run-left_7.png", game);
	run_left[7]= load_image("images/run-left/Run-left_8.png", game);
	run_left[8]= load_image("images/run-left/Run-left_9.png", game);
	run_left[9]= load_image("images/run-left/Run-left_10.png", game);
	run_left[10]= load_image("images/run-left/Run-left_11.png", game);
	run_left[11]= load_image("images/run-left/Run-left_12.png", game);
}

mlx_image_t	load_the_rest(t_game *game)
{
	char	*background;
	char	*exit;
	char	*enemy;

	game->wall = load_image("images/wall.png", game);
	game->background[0] = load_image("images/background1.png", game);
	background[1] = load_image("images/background2.png", game);
	exit[0] = load_image("images/exit/exit_1.png", game);
	exit[1] = load_image("images/exit/exit_2.png", game);
	exit[2] = load_image("images/exit/exit_3.png", game);
	exit[3] = load_image("images/exit/exit_4.png", game);
	exit[4] = load_image("images/exit/exit_5.png", game);
	exit[5] = load_image("images/exit/exit_6.png", game);
	exit[6] = load_image("images/exit/exit_7.png", game);
	exit[7] = load_image("images/exit/exit_8.png", game);
	enemy[0] = load_image("images/enemy/enemy_1.png", game);
	enemy[1] = load_image("images/enemy/enemy_2.png", game);
	enemy[2] = load_image("images/enemy/enemy_3.png", game);
	enemy[3] = load_image("images/enemy/enemy_4.png", game);
}
