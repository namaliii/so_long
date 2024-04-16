/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_array.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamieta <anamieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 18:46:34 by anamieta          #+#    #+#             */
/*   Updated: 2024/04/16 15:21:52 by anamieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	file_opening(t_game *game, char *file_name)
{
	int	file;

	file = open(file_name, O_RDONLY);
	if (file < 0)
		error_handling(game, game->map.array, "Failed to open the file.");
	return (file);
}

int	count_lines(t_game *game, char *file_name)
{
	char	*count_line;
	int		number_of_lines;
	int		file;

	file = file_opening(game, file_name);
	count_line = get_next_line(file);
	if (!count_line)
	{
		ft_printf("The file is empty!\n");
		close(file);
		return (0);
	}
	number_of_lines = 1;
	while (count_line)
	{
		free(count_line);
		count_line = get_next_line(file);
		if (count_line)
			number_of_lines++;
	}
	close(file);
	return (number_of_lines);
}

char	**create_array(t_game *game, char *file_name)
{
	char	**array;
	char	*temp;
	int		file;
	int		i;
	int		j;

	i = 0;
	array = ft_calloc(count_lines(game, file_name) + 1, sizeof(char *));
	file = file_opening(game, file_name);
	temp = get_next_line(file);
	while (temp)
	{
		array[i] = ft_calloc(ft_strlen(temp) + 1, sizeof(char));
		j = 0;
		while (temp[j])
		{
			array[i][j] = temp[j];
			j++;
		}
		i++;
		free(temp);
		temp = get_next_line(file);
	}
	close(file);
	return (array);
}
