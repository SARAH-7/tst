/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_dfs_marker.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbakhit <sbakhit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 19:35:20 by sbakhit           #+#    #+#             */
/*   Updated: 2024/07/02 14:14:20 by sbakhit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	bonus_ft_line_length(char *map_row)
{
	int	i;

	i = 0;
	if (!map_row)
		return (0);
	while (map_row[i])
		i++;
	return (i);
}

int	bonus_ft_line_count(char **map)
{
	int	i;

	i = 0;
	if (!map || !map[i])
		return (0);
	while (map[i])
		i++;
	return (i);
}

char	**bonus_dfs_marker(char **map)
{
	char	**dfs_marker;
	int		rows;
	int		cols;
	int		i;
	int		j;

	rows = bonus_ft_line_count(map);
	cols = bonus_ft_line_length(map[0]);
	dfs_marker = (char **)malloc(sizeof(char *) * (rows + 1));
	i = 0;
	while (map[i])
		dfs_marker[i++] = malloc(sizeof(char) * (cols + 1));
	dfs_marker[i] = NULL;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
			dfs_marker[i][j++] = 'F';
		dfs_marker[i][j] = '\0';
		i++;
	}
	return (dfs_marker);
}
