/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamieta <anamieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 18:04:23 by anamieta          #+#    #+#             */
/*   Updated: 2024/04/07 17:26:58 by anamieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	figure_counter(char **array, int *player,
	int *exit, int *collectible)
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
				(*player)++;
			else if (array[i][j] == 'E')
				(*exit)++;
			else if (array[i][j] == 'C')
				(*collectible)++;
			j++;
		}
		i++;
	}
}

void	figure_number_check(char **array, int *player,
	int *exit, int *collectible)
{
	figure_counter(array, player, exit, collectible);
	if (*player != 1)
		error_handling("There should be one player!");
	if (*exit != 1)
		error_handling("There should be one exit!");
	if (*collectible < 1)
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
				&& array[i][j] != '0' && array[i][j] != '1'
				&& array[i][j] != '\n')
				error_handling("Map contains invalid characters");
			j++;
		}
		i++;
	}
}

void	map_validity(char *str)
{
	int		collectible;
	int		player;
	int		exit;
	char	**array;

	collectible = 0;
	player = 0;
	exit = 0;
	array = create_array(str);
	figure_number_check(array, &player, &exit, &collectible);
	rectangular_check(array);
	valid_extension(str);
	valid_characters(array);
	surrounded_by_walls(array);
	valid_path(array);
}
