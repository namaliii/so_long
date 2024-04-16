/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamieta <anamieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 18:20:17 by anamieta          #+#    #+#             */
/*   Updated: 2024/04/16 15:50:33 by anamieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	error_handling(t_game *game, char **array, char *str)
{
	if (game->mlx)
	{
		mlx_terminate(game->mlx);
		mlx_close_window(game->mlx);
	}
	ft_printf("%s\n", str);
	free_2d_array(array);
	exit(EXIT_SUCCESS);
}

void	rectangular_check(t_game *game)
{
	int	firstline_len;
	int	line_len;
	int	i;

	i = 0;
	firstline_len = ft_strlen(game->map.array[0]);
	if (game->map.array[0][firstline_len - 1] == '\n')
		firstline_len--;
	while (game->map.array[i])
	{
		line_len = ft_strlen(game->map.array[i]);
		if (game->map.array[i][line_len - 1] == '\n')
			line_len--;
		if (line_len != firstline_len)
			error_handling(game, game->map.array,
				"The map has to be rectangular!");
		i++;
	}
}

static int	last_line_idx(char **array)
{
	int	number_of_lines;

	number_of_lines = 0;
	while (array[number_of_lines])
		number_of_lines++;
	return (number_of_lines);
}

void	surrounded_by_walls(t_game *game, char **array)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (array[0][j] && array[0][j] != '\n')
	{
		if (array[0][j] != '1')
			error_handling(game, array, "Walls must surround the game!");
		j++;
	}
	while (i < last_line_idx(array) - 1)
	{
		if (array[i][0] != '1' || array[i][ft_strlen(array[i]) - 2] != '1')
			error_handling(game, array, "Walls must surround the game!");
		i++;
	}
	j = 0;
	while (array[last_line_idx(array) - 1][j])
	{
		if (array[last_line_idx(array) - 1][j] != '1')
			error_handling(game, array, "Walls must surround the game!");
		j++;
	}
}
