/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_moves_updater.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbakhit <sbakhit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 01:24:22 by sbakhit           #+#    #+#             */
/*   Updated: 2024/07/02 19:11:39 by sbakhit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	bonus_player_find(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i] != NULL)
	{
		j = 0;
		while (game->map[i][j] != '\0')
		{
			if (game->map[i][j] == 'P')
			{
				game->player.position_x = j * DIM;
				game->player.position_y = i * DIM;
			}
			j++;
		}
		i++;
	}
}

int	bonus_move_flag(t_game *game, int i, int j)
{
	if (game->map[i][j] == 'C')
	{
		game->player.collectable_counter++;
		game->map[i][j] = '0';
		return (1);
	}
	if (game->map[i][j] == '1')
		return (0);
	if (game->map[i][j] == 'N')
		return (4);
	if (game->map[i][j] == 'E' && (game->player.collectable_counter
		!= game->collectable_counter))
		return (3);
	if (game->map[i][j] == 'E' && (game->player.collectable_counter
		== game->collectable_counter))
		return (2);
	return (1);
}

void	bonus_update_game(t_game *game)
{
	char	*moves;

	game->player.moves_counter++;
	bonus_player_find(game);
	bonus_ft_draw_tiles(*game);
	moves = ft_itoa(game->player.moves_counter);
	mlx_put_image_to_window(game->mlx, game->win.mlx_win,
		game->album[0].img, (game->win.x / 2) * DIM + DIM, 0);
	mlx_string_put(game->mlx, game->win.mlx_win,
		(game->win.x / 2) * DIM, DIM / 2, 0x00FF66, "Moves:");
	mlx_string_put(game->mlx, game->win.mlx_win,
		(game->win.x / 2) * DIM + DIM, DIM / 2, 0x00FF66, moves);
	free(moves);
}
