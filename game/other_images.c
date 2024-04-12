/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_images.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamieta <anamieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 12:38:59 by anamieta          #+#    #+#             */
/*   Updated: 2024/04/12 12:39:44 by anamieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	melon_imgs(t_game *game)
{
	static const char	*imgs[] = {
		"images/melon/Melon_1.png",
		"images/melon/Melon_2.png",
		"images/melon/Melon_3.png",
		"images/melon/Melon_4.png",
		"images/melon/Melon_5.png",
		"images/melon/Melon_6.png",
		"images/melon/Melon_7.png",
		"images/melon/Melon_8.png",
		"images/melon/Melon_9.png",
		"images/melon/Melon_10.png",
		"images/melon/Melon_11.png",
		"images/melon/Melon_12.png",
		"images/melon/Melon_13.png",
		"images/melon/Melon_14.png",
		"images/melon/Melon_15.png",
		"images/melon/Melon_16.png",
		"images/melon/Melon_17.png",
		NULL
	};

	return (load_imgs_error_check(game, game->collectible, imgs));
}

int	exit_imgs(t_game *game)
{
	static const char	*imgs[] = {
		"images/exit/exit_1.png",
		"images/exit/exit_2.png",
		"images/exit/exit_3.png",
		"images/exit/exit_4.png",
		"images/exit/exit_5.png",
		"images/exit/exit_6.png",
		"images/exit/exit_7.png",
		"images/exit/exit_8.png",
		NULL
	};

	return (load_imgs_error_check(game, game->exit, imgs));
}

int	enemy_imgs(t_game *game)
{
	static const char	*imgs[] = {
		"images/enemy/enemy_1.png",
		"images/enemy/enemy_2.png",
		"images/enemy/enemy_3.png",
		"images/enemy/enemy_4.png",
		NULL
	};

	return (load_imgs_error_check(game, game->enemy, imgs));
}

int	background_imgs(t_game *game)
{
	static const char	*imgs[] = {
		"images/background1.png",
		"images/background2.png",
		NULL
	};

	return (load_imgs_error_check(game, game->background, imgs));
}

int	wall_img(t_game *game)
{
	game->wall = load_image("images/wall.png", game);
	if (game->wall == NULL)
		return (1);
	return (0);
}
