/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamieta <anamieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 18:20:17 by anamieta          #+#    #+#             */
/*   Updated: 2024/04/05 17:26:49 by anamieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	main(int argc, char **argv)
{
	int		i;
	int		collectible;
	int		firstline_len;
	int		file;
	char	*line;

	i = 0;
	collectible = 0;
	file = open(argv[1]);
	line = get_next_line(file);
	firstline_len = ft_strlen(line);
    if (ft_strchr(line, 'E'))
	{
		ft_printf("There should be one EXIT\n");
		return (1);
	}
	else if (ft_strchar(line, 'P'))
	{
		ft_printf("There should be one PLAYER\n");
		return (1);
	}
	while (str[i])
	{
		if (str[i] == 'C')
			collectible++;
		i++;
	}
	map->collectible = collectible;
	if (!collectible)
	{
		ft_printf("There should be at least one COLLECTIBLE\n");
		return (1);
	}
	if (file < 0) 
    {
		ft_printf("Failed to open the file.\n");
        return (1);
	}
	while (line)
	{
		line = get_next_line(file);
		if (firstline_len != ft_strlen(line))
		{
			ft_printf("The map has to be rectangular\n");
			return (1);
		}
	}
}

// int	error_arguments(int argc, char **argv)
// {
// 	if (argc != 2)
// 		return (1);
// }

// int	valid_extension(t_map *map)
// {
// 	int		length;
// 	char	*str;

// 	str = map->path;
// 	length = ft_strlen(str) - 1;
// 	if (str[length - 3] != '.' || str[length - 2] != 'b'
// 		|| str[length - 1] != 'e' || str[length] != r)
// 		return (1);
// 	return (0);
// }

// int	empty_file_check(t_map *map)
// {
// 	char	*str;

// 	str = get_next_line(map->path);
// 	if (!str)
// 		return (1);
// 	return (0);
// }

// int	valid_characters(t_map *map)
// {
// 	char	*line;
// 	int		i;

// 	line = get_next_line(map->path);
// 	i = 0;
// 	while (line)
// 	{
// 		while (line[i])
// 		{
// 			if (line[i] != 'E' && line[i] != 'P' && line[i] != 'C'
// 				&& line[i] != '0' && line[i] != '1')
// 				return (1);
// 			i++;
// 		}
// 		line = get_next_line(map->path);
// 	}
// 	return (0);
// }

// int surrounded_by_walls(t_map *map)
// {
// 	char	*line;
// 	int		i;
// 	int		line_len;
// 	int		number_of_lines;

// 	line = get_next_line(map->path);
// 	i = 0;
// 	line_len = 0;
// 	number_of_lines = 0;
// 	while (line[i])
// 	{
// 		if (line[i] != '1')
// 			return (1);
// 		i++;
// 	}
// 	while (line)
// 	{
// 		line = get_next_line(map->path);
// 		number_of_lines++;
// 	}
// 	// jak to wykorzystac i sprawdzic czy ostatnia linia ma same 1
// 	while (line)
// 	{
// 		line = get_next_line(map->path);
// 		if (line[0] != '1')
// 			return (1);
// 		line_len = ft_strlen(line);
// 		if (line[line_len - 1] != 1)
// 			return (1);
// 	}
// }

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
