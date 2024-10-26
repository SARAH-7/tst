/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_common.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbakhit <sbakhit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 18:05:08 by sbakhit           #+#    #+#             */
/*   Updated: 2024/07/02 14:38:39 by sbakhit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_common(t_game *game, int move_result)
{
	if (move_result == 3)
		ft_printf("First, Eat All the Meat!\n");
	else if (move_result == 2)
	{
		game->winning_check = 1;
		bonus_destroy_game_post(game);
	}
	else if (move_result == 4)
	{
		ft_printf("You Touched an Enemy, You Died!\n");
		bonus_destroy_game_post(game);
	}
}
