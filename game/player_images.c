/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_images.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamieta <anamieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 18:18:43 by anamieta          #+#    #+#             */
/*   Updated: 2024/04/14 17:56:58 by anamieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	player_imgs(t_game *game)
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

	return (load_imgs_error_check(game, game->player, imgs));
}
