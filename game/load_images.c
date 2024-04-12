/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_images2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamieta <anamieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 12:39:05 by anamieta          #+#    #+#             */
/*   Updated: 2024/04/12 12:39:54 by anamieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

mlx_image_t	*load_image(const char *path, t_game *game)
{
	mlx_texture_t	*texture;
	mlx_image_t		*img;

	texture = mlx_load_png(path);
	if (!texture)
		return (NULL);
	img = mlx_texture_to_image(game->mlx, texture);
	if (!img)
		return (NULL);
	mlx_resize_image(img, 64, 64);
	return (img);
}

int	load_imgs_error_check(t_game *game, mlx_image_t **imgs, const char **paths)
{
	while (*paths != NULL)
	{
		*imgs = load_image(*paths, game);
		if (*imgs == NULL)
			return (1);
		imgs++;
		paths++;
	}
	return (0);
}

int	load_images(t_game *game)
{
	if (background_imgs(game) || wall_img(game) || idle_right_imgs(game)
		|| idle_left_imgs(game) || run_left_imgs(game) || run_right_imgs(game)
		|| melon_imgs(game) || exit_imgs(game) || enemy_imgs(game))
		return (1);
	return (0);
}
