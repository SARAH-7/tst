/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_enemy_funcs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbakhit <sbakhit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 01:38:54 by sbakhit           #+#    #+#             */
/*   Updated: 2024/07/02 19:11:31 by sbakhit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	move_back(t_game *game, int i, int j)
{
	static int	steps_back;
	int			limit;

	limit = game->enemy_checker * 3;
	if (steps_back == limit)
	{
		steps_back = 0;
		game->enemy_direction = 0;
	}
	if (steps_back < limit && game->enemy_direction == 1)
	{
		game->map[i][j] = '0';
		game->map[i][j + 1] = 'N';
		bonus_ft_draw_tiles(*game);
		steps_back++;
	}
}

void	move_enemy(t_game *game, int i, int j)
{
	static int	steps;
	int			limit;

	limit = game->enemy_checker * 3;
	if (steps == limit)
	{
		steps = 0;
		game->enemy_direction = 1;
	}
	if (steps < limit && game->enemy_direction == 0)
	{
		game->map[i][j] = '0';
		game->map[i][j - 1] = 'N';
		bonus_ft_draw_tiles(*game);
		steps++;
	}
}

void	anim_find1(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'N')
				move_enemy(game, i, j);
			j++;
		}
		i++;
	}
}

void	anim_find2(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
			j++;
		while (j >= 0)
		{
			if (game->map[i][j] == 'N')
				move_back(game, i, j);
			j--;
		}
		i++;
	}
}

int	move_animation(t_game *game)
{
	game->speed++;
	if (game->speed >= 1450)
	{
		if (game->enemy_direction == 0)
			anim_find1(game);
		if (game->enemy_direction == 1)
			anim_find2(game);
		game->speed = 0;
	}
	if (enemy_kill(game) == 0)
	{
		ft_printf("You touched an enemy!\n");
		bonus_destroy_game_post(game);
	}
	return (0);
}
