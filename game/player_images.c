/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_images.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamieta <anamieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 18:18:43 by anamieta          #+#    #+#             */
/*   Updated: 2024/04/11 20:24:04 by anamieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	idle_right_imgs(t_game *game)
{
	static const char	*imgs[] = {
		"images/idle-right/idle1.png",
		"images/idle-right/idle2.png",
		"images/idle-right/idle3.png",
		"images/idle-right/idle4.png",
		"images/idle-right/idle5.png",
		"images/idle-right/idle6.png",
		"images/idle-right/idle7.png",
		"images/idle-right/idle8.png",
		"images/idle-right/idle9.png",
		"images/idle-right/idle10.png",
		"images/idle-right/idle11.png",
		NULL
	};

	return (load_imgs_error_check(game, game->idle_right, imgs));
}

int	idle_left_imgs(t_game *game)
{
	static const char	*imgs[] = {
		"images/idle-left/idle1.png",
		"images/idle-left/idle2.png",
		"images/idle-left/idle3.png",
		"images/idle-left/idle4.png",
		"images/idle-left/idle5.png",
		"images/idle-left/idle6.png",
		"images/idle-left/idle7.png",
		"images/idle-left/idle8.png",
		"images/idle-left/idle9.png",
		"images/idle-left/idle10.png",
		"images/idle-left/idle11.png",
		NULL
	};

	return (load_imgs_error_check(game, game->idle_left, imgs));
}

int	run_left_imgs(t_game *game)
{
	static const char	*imgs[] = {
		"images/run-left/Run-left_1.png",
		"images/run-left/Run-left_2.png",
		"images/run-left/Run-left_3.png",
		"images/run-left/Run-left_4.png",
		"images/run-left/Run-left_5.png",
		"images/run-left/Run-left_6.png",
		"images/run-left/Run-left_7.png",
		"images/run-left/Run-left_8.png",
		"images/run-left/Run-left_9.png",
		"images/run-left/Run-left_10.png",
		"images/run-left/Run-left_11.png",
		"images/run-left/Run-left_12.png",
		NULL
	};

	return (load_imgs_error_check(game, game->run_left, imgs));
}

int	run_right_imgs(t_game *game)
{
	static const char	*imgs[] = {
		"images/run-right/Run-right_1.png",
		"images/run-right/Run-right_2.png",
		"images/run-right/Run-right_3.png",
		"images/run-right/Run-right_4.png",
		"images/run-right/Run-right_5.png",
		"images/run-right/Run-right_6.png",
		"images/run-right/Run-right_7.png",
		"images/run-right/Run-right_8.png",
		"images/run-right/Run-right_9.png",
		"images/run-right/Run-right_10.png",
		"images/run-right/Run-right_11.png",
		"images/run-right/Run-right_12.png",
		NULL
	};

	return (load_imgs_error_check(game, game->run_right, imgs));
}
