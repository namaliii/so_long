/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamieta <anamieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 18:20:17 by anamieta          #+#    #+#             */
/*   Updated: 2024/04/04 19:29:17 by anamieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	error_handling(char *str)
{
	int		i;
	int		collectible;
	int		firstline_len;
	int		file;
	char	*line;

	i = 0;
	collectible = 0;
	file = open("map.ber", 'r');
	line = get_next_line(file);
	firstline_len = ft_strlen(line);

	//checking if there's more than 1 exit/player
    if (ft_strchr(str, 'E'))
	//could put in each contidion ft_printf("There should be one exit!")
		return (1);
	else if (ft_strchar(str, 'P'))
		return (1);
	//checking if there's at least one collectible
	while (str[i])
	{
		if (str[i] == 'C')
			collectible++;
		i++;
	}
	if (!collectible)
		return (1);
	if (file < 0) 
    // printf("Failed to open the file.\n");
        return (1);
	//checking if the map is rectangular (if the length of each line is the same)
	while (line)
	{
		line = get_next_line(file);
		if (firstline_len != ft_strlen(line))
			return (1);
	}
}

void	fill(char **tab, t_point size, t_point current, char to_fill)
{
	if (current.x < 0 || current.y < 0 || current.x >= size.x
		|| current.y >= size.y || tab[current.y][current.x] != to_fill)
		return ;

	tab[current.y][current.x] = '0';
	fill(tab, size, (t_point){current.x +1, current.y}, to_fill);
	fill(tab, size, (t_point){current.x -1, current.y}, to_fill);
	fill(tab, size, (t_point){current.x, current.y +1}, to_fill);
	fill(tab, size, (t_point){current.x, current.y -1}, to_fill);
}

void	flood_fill(char **tab, t_point size, t_point begin)
{
	char	to_fill;

	to_fill = tab[begin.y][begin.x];
	fill(tab, size, begin, to_fill);
}
