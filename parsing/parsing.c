/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamieta <anamieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 18:20:17 by anamieta          #+#    #+#             */
/*   Updated: 2024/04/06 15:49:02 by anamieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	error_handling(char *str)
{
	ft_printf("%s\n", str);
	exit(0);
}

int	file_opening(char **argv)
{
	int	file;

	file = open(argv[1], O_RDONLY);
	if (file < 0)
		error_handling("Failed to open the file.");
	return (file);
}

int	count_lines(int file)
{
	char	*count_line;
	int		number_of_lines;

	count_line = get_next_line(file);
	if (!count_line)
	{
		ft_printf("The file is empty!\n");
		return (0);
	}
	number_of_lines = 1;
	while (count_line)
	{
		count_line = get_next_line(file);
		if (count_line)
			number_of_lines++;
	}
	return (number_of_lines);
}

char	**create_array(char **str)
{
	char	**array;
	char	*temp;
	int		file;
	int		i;
	int		j;
	int		number_of_lines;

	i = 0;
	j = 0;
	file = file_opening(str);
	number_of_lines = count_lines(file);
	close(file);
	temp = get_next_line(file_opening(str));
	array = ft_calloc(number_of_lines + 1, sizeof(char*));
	while (temp)
	{
		array[i] = ft_calloc(ft_strlen(temp) + 1, sizeof(char));
		while (temp[j])
		{
			array[i][j] = temp[j];
			j++;
		}
		j = 0;
		i++;
		temp = get_next_line(file);
	}
	close(file);
	return (array);
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

static void	figure_counter(char **array, int player, int exit, int collectible)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (array[i])
	{
		j = 0;
		while (array[i][j])
		{
			if (array[i][j] == 'P')
				player++;
			else if (array[i][j] == 'E')
				exit++;
			else if (array[i][j] == 'C')
				collectible++;
			j++;
		}
		i++;
	}
}

void	figure_number_check(char **array, int player, int exit, int collectible)
{
	figure_counter(array, player, exit, collectible);
	if (player != 1)
		error_handling("There should be one player!");
	if (exit != 1)
		error_handling("There should be one exit!");
	if (collectible < 1)
		error_handling("There should be at least one collectible!");
}

void	valid_extension(char *str)
{
	int		length;

	length = ft_strlen(str) - 1;
	if (str[length - 3] != '.' || str[length - 2] != 'b'
		|| str[length - 1] != 'e' || str[length] != 'r')
		error_handling("Map extension invalid");
}

void	valid_characters(char **array)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (array[i])
	{
		j = 0;
		while (array[i][j])
		{
			if (array[i][j] != 'E' && array[i][j] != 'P' && array[i][j] != 'C'
				&& array[i][j] != '0' && array[i][j] != '1')
				error_handling("Map contains invalid characters");
			j++;
		}
		i++;
	}
}

void surrounded_by_walls(char **array)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (array[0][j])
	{
		if (array[0][j] != '1')
			error_handling("Game field must be surrounded by walls");
		j++;
	}
	while (array[i])
	{
		if (array[i][0] != '1' || array[i][ft_strlen(array[i]) - 1] != '1')
			error_handling("Game field must be surrounded by walls");
		i++;
	}
	while (array[i])
		i++;
	j = 0;
	while (array[i][j])
	{
		if (array[i][j] != '1')
			error_handling("Game field must be surrounded by walls");
		j++;
	}
}

void map_validity(char **str)
{
	int		collectible;
	int		player;
	int		exit;
	char	**array;

	collectible = 0;
	player = 0;
	exit = 0;
	array = create_array(str);
	figure_number_check(array, player, exit, collectible);
	valid_extension((char *)str);
	valid_characters(array);
	surrounded_by_walls(array);
}

int	main(int argc, char **argv)
{
	if (argc != 2)
		error_handling("Wrong number of arguments, dude");
	map_validity(&argv[1]);
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
