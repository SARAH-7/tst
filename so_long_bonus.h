/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbakhit <sbakhit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 15:59:32 by sbakhit           #+#    #+#             */
/*   Updated: 2024/07/02 19:07:12 by sbakhit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include <unistd.h>
# include <string.h> 
# include <stdarg.h>
# include "../libft/libft.h"
# include "../ft_printf/ft_printf.h"
// # include "../minilibx/mlx.h"
# include <fcntl.h>
# include <stdlib.h>
# include <limits.h>

# define DIM 48
# define W_KEY 13
# define A_KEY 0
# define S_KEY 1
# define D_KEY 2
# define ESC_KEY 53

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

typedef struct s_player
{
	int	position_x;
	int	position_y;
	int	moves_counter;
	int	collectable_counter;
	int	valid_exit;
	int	direction;
}		t_player;

typedef struct s_map
{
	int	moves_counter;
	int	collectable_counter;
}		t_map;

typedef struct s_window
{
	int		x;
	int		y;
	void	*mlx_win;
}			t_window;

typedef struct s_image
{
	void	*img;
	int		img_width;
	int		img_height;
}				t_image;

typedef struct s_game
{
	int			moves_counter;
	int			collectable_counter;
	int			player_checker;
	int			exit_checker;
	int			dfs_collectable_counter;
	int			winning_check;
	int			enemy_checker;
	int			enemy_direction;
	int			speed;
	int			timer;
	char		**map;
	void		*mlx;
	t_image		album[6];
	t_image		enemy_album[2];
	t_player	player;
	t_window	win;
}		t_game;

typedef struct s_index
{
	int	i;
	int	j;
}			t_index;

int		main(int ac, char **av);
int		bonus_file_parser(const char *str);
char	**bonus_map_parser(int fd, char **av);
char	*get_next_line(int fd);
char	*ft_strdup(const char *s1);
char	*ft_get_line(const char *s, int c);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(const char *s1, const char *s2);
int		bonus_map_width(char *map_row);
int		bonus_map_height(char **map);
void	bonus_checker(t_game *game);
void	bonus_ft_draw_map(t_game game);
void	bonus_ft_draw_tiles(t_game game);
void	player_find(t_game *game);
void	map_parsing_check(t_game game);
char	**bonus_dfs_marker(char **map);
void	bonus_dfs(t_game *game, char **mark_map, int j, int i);
int		bonus_valid_path_check(t_game *game, char **mark_map);
void	bonus_free_map(char **map);
void	bonus_destroy_game_pre(t_game *game);
int		bonus_destroy_game_post(t_game *game);
void	bonus_destroy_images(t_game *game);
void	bonus_move_up(t_game *game);
void	bonus_move_left(t_game *game);
void	bonus_move_down(t_game *game);
void	bonus_move_right(t_game *game);
void	bonus_player_find(t_game *game);
void	bonus_load_images(t_game *game);
void	bonus_imgmsg_loadcheck(t_game *game);
int		bonus_move_flag(t_game *game, int i, int j);
void	bonus_update_game(t_game *game);
void	error_print_msg_pre_map(int error_num);
void	error_print_msg(int error_num, char **map);
void	bonus_check_for_walls(char **map, int map_height);
void	enemy_put_image(t_game game, int i, int j);
int		move_animation(t_game *game);
int		enemy_kill(t_game *game);
void	find_enemy(t_game *game);
void	load_enemy_images(t_game *game);

void	bonus_dfs(t_game *game, char **mark_map, int j, int i);
int		valid_path_check(t_game *game, char **mark_map);

void	ft_common(t_game *game, int move_result);
#endif
