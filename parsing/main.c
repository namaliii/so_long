/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamieta <anamieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 18:07:34 by anamieta          #+#    #+#             */
/*   Updated: 2024/04/06 18:52:48 by anamieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	main(int argc, char **argv)
{
	if (argc != 2)
		error_handling("Wrong number of arguments, dude");
	map_validity(argv[1]);
	return (0);
}

// void	fill(char **tab, t_point size, t_point current, char to_fill)
// {
// 	if (current.x < 0 || current.y < 0 || current.x >= size.x
// 		|| current.y >= size.y || tab[current.y][current.x] != to_fill)
// 		return ;

// 	tab[current.y][current.x] = '0';
// 	fill(tab, size, (t_point){current.x +1, current.y}, to_fill);
// 	fill(tab, size, (t_point){current.x -1, current.y}, to_fill);
// 	fill(tab, size, (t_point){current.x, current.y +1}, to_fill);
// 	fill(tab, size, (t_point){current.x, current.y -1}, to_fill);
// }

// void	flood_fill(char **tab, t_point size, t_point begin)
// {
// 	char	to_fill;

// 	to_fill = tab[begin.y][begin.x];
// 	fill(tab, size, begin, to_fill);
// }
