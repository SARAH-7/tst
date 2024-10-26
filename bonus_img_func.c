/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_img_func.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbakhit <sbakhit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 01:16:02 by sbakhit           #+#    #+#             */
/*   Updated: 2024/07/02 19:12:01 by sbakhit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	load_enemy_images(t_game *game)
{
	game->enemy_album[0].img = mlx_xpm_file_to_image(game->mlx,
			"bonus/texture/sprite_left.xpm",
			&game->enemy_album[0].img_width,
			&game->enemy_album[0].img_height);
	game->enemy_album[1].img = mlx_xpm_file_to_image(game->mlx,
			"bonus/texture/sprite_right.xpm",
			&game->enemy_album[1].img_width,
			&game->enemy_album[1].img_height);
}

int	image_parser(t_game game)
{
	int	i;

	i = 0;
	while (i < 6)
	{
		if (game.album[i].img == NULL)
			return (0);
		i++;
	}
	i = 0;
	while (i < 2)
	{
		if (game.enemy_album[i].img == NULL)
			return (0);
		i++;
	}
	return (1);
}

void	bonus_imgmsg_loadcheck(t_game *game)
{
	if (!image_parser(*game))
	{
		ft_printf("Error! Check all image files are present\n");
		bonus_destroy_images(game);
		mlx_destroy_window(game->mlx, game->win.mlx_win);
		free(game->mlx);
		bonus_free_map(game->map);
		exit(EXIT_FAILURE);
	}
}

void	bonus_load_images(t_game *game)
{
	game->album[0].img = mlx_xpm_file_to_image(game->mlx,
			"texture/wall.xpm", &game->album[0].img_width,
			&game->album[0].img_height);
	game->album[1].img = mlx_xpm_file_to_image(game->mlx,
			"texture/collectable.xpm", &game->album[1].img_width,
			&game->album[1].img_height);
	game->album[2].img = mlx_xpm_file_to_image(game->mlx,
			"texture/player_right.xpm", &game->album[2].img_width,
			&game->album[2].img_height);
	game->album[3].img = mlx_xpm_file_to_image(game->mlx,
			"texture/player_left.xpm", &game->album[3].img_width,
			&game->album[3].img_height);
	game->album[4].img = mlx_xpm_file_to_image(game->mlx,
			"texture/portal.xpm", &game->album[4].img_width,
			&game->album[4].img_height);
	game->album[5].img = mlx_xpm_file_to_image(game->mlx,
			"texture/background.xpm", &game->album[5].img_width,
			&game->album[5].img_height);
}
