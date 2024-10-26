/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbakhit <sbakhit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 14:07:40 by sbakhit           #+#    #+#             */
/*   Updated: 2024/07/02 14:57:49 by sbakhit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	bonus_checker(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'P')
				game->player_checker++;
			else if (game->map[i][j] == 'C')
				game->collectable_counter++;
			else if (game->map[i][j] == 'E')
				game->exit_checker++;
			else if (!(game->map[i][j] == '1' || game->map[i][j] == '0'
				|| game->map[i][j] == 'N'))
				error_print_msg(4, game->map);
			j++;
		}
		i++;
	}
	if (!(game->player_checker == 1 && game->collectable_counter >= 1
			&& game->exit_checker == 1))
		error_print_msg(4, game->map);
}
