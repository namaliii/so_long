/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamieta <anamieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 18:20:17 by anamieta          #+#    #+#             */
/*   Updated: 2024/04/05 19:02:15 by anamieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	main(int argc, char **argv)
{
	int		collectible;
	int		player;
	int		exit;
	int		file;

	if (argc != 2)
		error_handling("Wrong number of arguments, dude");
	collectible = 0;
	player = 0;
	exit = 0;
	file = open(argv[1], O_RDONLY);
	if (file < 0)
		error_handling("Failed to open the file.");
	cep_number_check(file, player, exit, collectible);
	valid_extension(argv);
	return (0);
}

void	error_handling(char *str)
{
	ft_printf("%s\n", str);
	exit(0);
}

void	rectangular_check(int file)
{
	int		firstline_len;
	char	*line;

	line = get_next_line(file);
	firstline_len = ft_strlen(line);
	while (line)
	{
		line = get_next_line(file);
		if (firstline_len != ft_strlen(line))
			error_handling("The map has to be rectangular!");
	}
}

int	cep_number_check(int file, int player, int exit, int collectible)
{
	cep_counter(file, player, exit, collectible);
	if (player != 1)
		error_handling("There should be one player!");
	if (exit != 1)
		error_handling("There should be one exit!");
	if (collectible < 1)
		error_handling("There should be at least one collectible!");
}

int	cep_counter(int file, int player, int exit, int collectible)
{
	int		i;
	char	*line;

	i = 0;
	line = get_next_line(file);
	while (line)
	{
		line = get_next_line(file);
		if (line)
		{
			i = 0;
			while (line[i])
			{
				if (line[i] == 'P')
					player++;
				else if (line[i] == 'E')
					exit++;
				else if (line[i] == 'C')
					collectible++;
				i++;
			}
		}
	}
}

void	valid_extension(char **argv)
{
	int		length;
	char	*str;

	str = argv[1];
	length = ft_strlen(str) - 1;
	if (str[length - 3] != '.' || str[length - 2] != 'b'
		|| str[length - 1] != 'e' || str[length] != 'r')
		error_handling("Map extension invalid");
}

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
