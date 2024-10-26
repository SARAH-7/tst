/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_enemy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbakhit <sbakhit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 21:21:00 by sbakhit           #+#    #+#             */
/*   Updated: 2024/06/14 21:49:15 by sbakhit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	enemy_pos(t_game *game, int i, int j)
{
	int	k;

	k = 0;
	while (k < 4)
	{
		if (game->map[i][j - k] == '1' || game->map[i][j - k] == 'C')
		{
			ft_printf("Enemy Within 3 Spaces of a Wall or a Collectable\n");
			bonus_free_map(game->map);
			exit(EXIT_SUCCESS);
		}
		k++;
	}
}

void	find_enemy(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'N')
			{
				enemy_pos(game, i, j);
				game->enemy_checker++;
			}
			j++;
		}
		i++;
	}
}
