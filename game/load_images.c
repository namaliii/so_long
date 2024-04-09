/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamieta <anamieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 17:12:08 by anamieta          #+#    #+#             */
/*   Updated: 2024/04/09 20:13:24 by anamieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static mlx_image_t *load_image(const char *path, t_game *game)
{
    mlx_texture_t *texture;
    mlx_image_t *img;

    texture = mlx_load_png(path);
	if (!texture)
        exit(0); //error function that exits and frees
	img = mlx_texture_to_image(game->mlx, texture);
	if (!img)
        exit(0);
    return(img);
}

void load_images(t_game *game)
{
    game->background = load_image("images/background.png", game);
    game->wall = load_image("images/wall.png", game);
    game->player = load_image("images/player.png", game);
    game->exit = load_image("images/exit.png", game);
    game->collectible = load_image("images/collectible.png", game);
}

void render_map(t_game *game)
{
    int x;
    int y;

    x = 0;
    y = 0;
    while (game->map.array[y])
    {
        x = 0;
        while (game->map.array[y][x])
        {  
            mlx_image_to_window(game->mlx, game->background, x * game->background->width, y * game->background->height);
            x++;
        }
        y++;
    }
}

