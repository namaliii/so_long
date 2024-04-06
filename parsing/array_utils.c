/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamieta <anamieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 18:20:17 by anamieta          #+#    #+#             */
/*   Updated: 2024/04/06 19:05:52 by anamieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	error_handling(char *str)
{
	ft_printf("%s\n", str);
	exit(0);
}

void	rectangular_check(char **array)
{
	int	firstline_len;
	int	line_len;
	int	i;

	i = 0;
	firstline_len = ft_strlen(array[0]);
	if (array[0][firstline_len - 1] == '\n')
		firstline_len--;
	while (array[i])
	{
		line_len = ft_strlen(array[i]);
		if (array[i][line_len - 1] == '\n')
			line_len--;
		if (line_len != firstline_len)
			error_handling("The map has to be rectangular!");
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

void	surrounded_by_walls(char **array)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (array[0][j] && array[0][j] != '\n')
	{
		if (array[0][j] != '1')
			error_handling("Game field must be surrounded by walls");
		j++;
	}
	while (i < last_line_idx(array) - 1)
	{
		if (array[i][0] != '1' || array[i][ft_strlen(array[i]) - 2] != '1')
			error_handling("Game field must be surrounded by walls");
		i++;
	}
	j = 0;
	while (array[last_line_idx(array) - 1][j])
	{
		if (array[last_line_idx(array) - 1][j] != '1')
			error_handling("Game field must be surrounded by walls");
		j++;
	}
}
