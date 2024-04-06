/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_validity.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamieta <anamieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 19:16:41 by anamieta          #+#    #+#             */
/*   Updated: 2024/04/06 21:34:30 by anamieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"


t_point size = {count_lines - 1, ft_strlen(array[0]) - 1};
t_point begin = find_player;

void	fill(char **array, t_point size, t_point current, char to_fill)
{
	if (current.x < 0 || current.y < 0 || current.x >= size.x
		|| current.y >= size.y || array[current.y][current.x] != to_fill)
		return ;

	array[current.y][current.x] = '0';
	fill(array, size, (t_point){current.x +1, current.y}, to_fill);
	fill(array, size, (t_point){current.x -1, current.y}, to_fill);
	fill(array, size, (t_point){current.x, current.y +1}, to_fill);
	fill(array, size, (t_point){current.x, current.y -1}, to_fill);
}

void	flood_fill(char **array, t_point size, t_point begin)
{
	char	to_fill;

	to_fill = array[begin.y][begin.x];
	fill(array, size, begin, to_fill);
}
