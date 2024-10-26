/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_map_entries.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbakhit <sbakhit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 14:11:16 by sbakhit           #+#    #+#             */
/*   Updated: 2024/07/02 18:38:59 by sbakhit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	check_first_last_wall(char **map, int height, int i)
{
	int	j;

	j = 0;
	while ((i == 0 || i == height - 1) && map[i][j] != '\0')
	{
		if (map[i][j] != '1')
			error_print_msg(4, map);
		j++;
	}
}

void	check_borders(char **map, int i)
{
	int	j;

	j = 0;
	while (map[i][j] != '\0')
	{
		if ((j == 0 || j == (int)ft_strlen(map[i]) - 1)
			&& map[i][j] != '1')
			error_print_msg(4, map);
		j++;
	}
}

void	bonus_check_for_walls(char **map, int map_height)
{
	int	i;

	i = 0;
	while (map[i] && map[i] != NULL)
	{
		if (i == 0 || i == map_height - 1)
			check_first_last_wall(map, map_height, i);
		else
			check_borders(map, i);
		if (map[i + 1] != NULL
			&& (int)ft_strlen(map[i]) != (int)ft_strlen(map[i + 1]))
			error_print_msg(5, map);
		i++;
	}
}
