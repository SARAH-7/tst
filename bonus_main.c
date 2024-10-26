/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbakhit <sbakhit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 15:58:18 by sbakhit           #+#    #+#             */
/*   Updated: 2024/07/02 19:12:10 by sbakhit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	key_hook(int keycode, t_game *game)
{
	if (keycode == W_KEY)
		bonus_move_up(game);
	else if (keycode == A_KEY)
		bonus_move_left(game);
	else if (keycode == S_KEY)
		bonus_move_down(game);
	else if (keycode == D_KEY)
		bonus_move_right(game);
	else if (keycode == ESC_KEY)
		bonus_destroy_game_post(game);
	else
	{
		ft_printf("Error! You Pressed Wrong Key.\n");
		return (1);
	}
	return (0);
}

void	game_initializer(t_game *game)
{
	game->win.x = bonus_map_width(game->map[0]);
	game->win.y = bonus_map_height(game->map);
	if (game->win.x == 0 || game->win.y == 0 || (game->win.x == game->win.y))
	{
		if (game->win.x == game->win.y)
			error_print_msg(8, game->map);
		bonus_free_map(game->map);
		exit(EXIT_FAILURE);
	}
	game->player_checker = 0;
	game->exit_checker = 0;
	game->collectable_counter = 0;
	game->dfs_collectable_counter = 0;
	game->player.collectable_counter = 0;
	game->player.moves_counter = 0;
	game->player.direction = 0;
	game->winning_check = 0;
	game->enemy_checker = 0;
	game->enemy_direction = 0;
	game->speed = 0;
	bonus_player_find(game);
}

void	window_initializer(t_game *game)
{
	int	j;

	j = 0;
	game->win.mlx_win = mlx_new_window(game->mlx,
			game->win.x * DIM, game->win.y * DIM, "sbakhit's So_Long");
	bonus_load_images(game);
	load_enemy_images(game);
	bonus_imgmsg_loadcheck(game);
	while (game->map[0][j])
	{
		if (game->map[0][j] == '1')
			mlx_put_image_to_window(game->mlx, game->win.mlx_win,
				game->album[0].img, j * DIM, 0 * DIM);
		j++;
	}
}

void	valid_path_checker(t_game *game)
{
	char	**marked_map;

	find_enemy(game);
	marked_map = bonus_dfs_marker(game->map);
	if (!marked_map)
		error_print_msg(6, game->map);
	bonus_dfs(game, marked_map, game->player.position_x / DIM,
		game->player.position_y / DIM);
	if (bonus_valid_path_check(game, marked_map) == 0)
		error_print_msg(7, game->map);
}

int	main(int ac, char **av)
{
	int		fd;
	t_game	game;

	if (ac != 2)
		error_print_msg_pre_map(1);
	if (!bonus_file_parser(av[1]))
		error_print_msg_pre_map(2);
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		error_print_msg_pre_map(3);
	game.map = bonus_map_parser(fd, av);
	game_initializer(&game);
	bonus_checker(&game);
	valid_path_checker(&game);
	game.mlx = mlx_init();
	if (!game.mlx)
		exit(EXIT_FAILURE);
	window_initializer(&game);
	mlx_hook(game.win.mlx_win, 17, 0L, bonus_destroy_game_post, &game);
	bonus_ft_draw_map(game);
	mlx_key_hook(game.win.mlx_win, key_hook, &game);
	mlx_loop_hook(game.mlx, move_animation, &game);
	mlx_loop(game.mlx);
	bonus_free_map(game.map);
	return (close(fd), 0);
}
