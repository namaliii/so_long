/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_validity.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamieta <anamieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 19:16:41 by anamieta          #+#    #+#             */
/*   Updated: 2024/04/07 17:23:21 by anamieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static t_point	size_set(char **array)
{
	int		x;
	int		y;
	t_point	size;

	x = 0;
	y = 0;
	while (array[0][x] != '\n' && array[0][x] != '\0')
		x++;
	while (array[y])
		y++;
	size.x = x;
	size.y = y;
	return (size);
}

static t_point	player_position_set(char **array)
{
	int		x;
	int		y;
	t_point	player;

	x = 0;
	y = 0;
	while (array[y])
	{
		x = 0;
		while (array[y][x])
		{
			if (array[y][x] == 'P')
			{
				player.x = x;
				player.y = y;
				return (player);
			}
			x++;
		}
		y++;
	}
	player.x = x;
	player.y = y;
	return (player);
}

static void	fill(char **array, t_point size, t_point current)
{
	if (current.x < 0 || current.y < 0 || current.x >= size.x
		|| current.y >= size.y || array[current.y][current.x] == '1')
		return ;
	array[current.y][current.x] = '1';
	fill(array, size, (t_point){current.x +1, current.y});
	fill(array, size, (t_point){current.x -1, current.y});
	fill(array, size, (t_point){current.x, current.y +1});
	fill(array, size, (t_point){current.x, current.y -1});
}

static void	flood_fill(char **array)
{
	t_point	size;
	t_point	player;

	size = size_set(array);
	player = player_position_set(array);
	fill(array, size, player);
}

void	valid_path(char **array)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	flood_fill(array);
	while (array[i])
	{
		j = 0;
		while (array[i][j])
		{
			if (array[i][j] != '1' && array[i][j] != '0' && array[i][j] != '\n')
				error_handling("Some significant characters are unreachable!");
			j++;
		}
		i++;
	}
}
