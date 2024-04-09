/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_array.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamieta <anamieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 18:46:34 by anamieta          #+#    #+#             */
/*   Updated: 2024/04/09 13:42:58 by anamieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	file_opening(char *str)
{
	int	file;

	file = open(str, O_RDONLY);
	if (file < 0)
		error_handling(NULL, "Failed to open the file.");
	return (file);
}

int	count_lines(char *str)
{
	char	*count_line;
	int		number_of_lines;
	int		file;

	file = file_opening(str);
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
	close(file);
	return (number_of_lines);
}

char	**create_array(char *str)
{
	char	**array;
	char	*temp;
	int		file;
	int		i;
	int		j;

	i = 0;
	array = ft_calloc(count_lines(str) + 1, sizeof(char *));
	file = file_opening(str);
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
		temp = get_next_line(file);
	}
	close(file);
	return (array);
}
