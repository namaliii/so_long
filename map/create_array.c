/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_array.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamieta <anamieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 18:46:34 by anamieta          #+#    #+#             */
/*   Updated: 2024/04/14 18:21:20 by anamieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	file_opening(char *file_name)
{
	int	file;

	file = open(file_name, O_RDONLY);
	if (file < 0)
		error_handling(NULL, "Failed to open the file.");
	return (file);
}

int	count_lines(char *file_name)
{
	char	*count_line;
	int		number_of_lines;
	int		file;

	file = file_opening(file_name);
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

char	**create_array(char *file_name)
{
	char	**array;
	char	*temp;
	int		file;
	int		i;
	int		j;

	i = 0;
	array = ft_calloc(count_lines(file_name) + 1, sizeof(char *));
	file = file_opening(file_name);
	temp = get_next_line(file);
	while (temp)
	{
		array[i] = ft_calloc(ft_strlen(temp) + 1, sizeof(char));
		j = 0;
		while (temp[j])
		{
			// ft_printf("%d", array[i][j]);
			array[i][j] = temp[j];
			j++;
		}
		// ft_printf("\n");
		i++;
		temp = get_next_line(file);
	}
	close(file);
	return (array);
}
