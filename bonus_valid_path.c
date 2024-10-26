/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_valid_path.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbakhit <sbakhit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 21:56:37 by sbakhit           #+#    #+#             */
/*   Updated: 2024/07/02 14:27:10 by sbakhit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	find_neighbors(int j, int i, t_index *neighbors)
{
	neighbors[0] = (t_index){i - 1, j};
	neighbors[1] = (t_index){i + 1, j};
	neighbors[2] = (t_index){i, j - 1};
	neighbors[3] = (t_index){i, j + 1};
}

void	bonus_dfs(t_game *game, char **mark_map, int j, int i)
{
	t_index			neighbors[4];
	int				k;

	if (i < 0 || j < 0 || i >= game->win.y
		|| j >= game->win.x)
		exit(EXIT_FAILURE);
	mark_map[i][j] = 'T';
	if (game->map[i][j] == 'C')
		game->dfs_collectable_counter++;
	k = 0;
	find_neighbors(j, i, neighbors);
	while (k < 4)
	{
		i = neighbors[k].i;
		j = neighbors[k].j;
		if (i >= 0 && j >= 0 && i < game->win.y
			&& j < game->win.x && (!(game->map[i][j] == '1'
				|| game->map[i][j] == 'E' || game->map[i][j] == '\0')
			&& mark_map[i][j] == 'F'))
			bonus_dfs(game, mark_map, j, i);
		k++;
	}
}

int	check_exit(t_game *game, char **mark_map, int j, int i)
{
	t_index	neighbors[4];
	int		k;
	int		untraversables;

	if (game->dfs_collectable_counter != game->collectable_counter)
		return (0);
	find_neighbors(j, i, neighbors);
	k = 0;
	untraversables = 0;
	while (k < 4)
	{
		i = neighbors[k].i;
		j = neighbors[k].j;
		if (game->map[i][j] == '1' ||
			(game->map[i][j] == 'E' && mark_map[i][j] == 'F'))
			untraversables++;
		k++;
	}
	if (untraversables == 4)
		return (0);
	return (1);
}

int	valid_path_map_check(t_game *game, char **mark_map, int i, int flag)
{
	int	j;

	j = 0;
	while (game->map[i][j])
	{
		if (game->map[i][j] == 'P' && mark_map[i][j] == 'T')
			flag++;
		if (game->map[i][j] == 'C' && mark_map[i][j] == 'T')
			flag++;
		if (game->map[i][j] == 'E'
			&& check_exit(game, mark_map, j, i))
			flag++;
		j++;
	}
	return (flag);
}

int	bonus_valid_path_check(t_game *game, char **mark_map)
{
	int	i;
	int	flag;

	if (game->map == NULL || mark_map == NULL)
		error_print_msg(6, game->map);
	i = 0;
	flag = 0;
	while (game->map[i] && game->map[i] != NULL)
	{
		flag = valid_path_map_check(game, mark_map, i, flag);
		i++;
	}
	if (flag == 2 + game->dfs_collectable_counter)
		return (bonus_free_map(mark_map), 1);
	return (bonus_free_map(mark_map), 0);
}
