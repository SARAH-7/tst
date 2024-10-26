/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_map_parser.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbakhit <sbakhit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 13:51:22 by sbakhit           #+#    #+#             */
/*   Updated: 2024/07/02 19:02:59 by sbakhit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	bonus_map_width(char *map_row)
{
	int	i;

	i = 0;
	if (!map_row)
		return (0);
	while (map_row[i])
		i++;
	if (i > 53)
	{
		ft_printf("You Exceed The Possible Window Width!\n");
		exit(0);
	}
	return (i);
}

int	bonus_map_height(char **map)
{
	int	i;

	i = 0;
	if (!map || !map[i])
		return (0);
	while (map[i])
		i++;
	if (i > 29)
	{
		ft_printf("You Exceed The Possible Window Height!\n");
		exit (0);
	}
	return (i);
}

char	*assign_map(char **map, char *line, int *i)
{
	map[*i] = ft_calloc(sizeof(char), (ft_strlen(line) + 1));
	if (!map[*i])
		return (NULL);
	if (line[ft_strlen(line) - 1] == '\n')
		line[ft_strlen(line) - 1] = '\0';
	ft_strlcpy(map[*i], line, (ft_strlen(line) + 1));
	free(line);
	return (map[(*i)]);
}

int	fd_map_height(int fd)
{
	char	*line;
	int		i;

	line = NULL;
	i = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line && i == 0)
		{
			close(fd);
			exit(EXIT_FAILURE);
		}
		if (!line)
			break ;
		i++;
		free(line);
	}
	if (i > 29)
	{
		ft_printf("You Exceed The Possible Window Height!\n");
		close(fd);
		exit(EXIT_FAILURE);
	}
	return (i);
}

char	**bonus_map_parser(int fd, char **av)
{
	char	*line;
	char	**map;
	int		i;

	line = NULL;
	i = 0;
	map = ft_calloc(sizeof(char *), fd_map_height(fd) + 1);
	close(fd);
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		error_print_msg_pre_map(3);
	line = get_next_line(fd);
	if (!map || !line)
	{
		close(fd);
		error_print_msg(6, map);
	}
	while (line != NULL)
	{
		map[i] = assign_map(map, line, &i);
		i++;
		line = get_next_line(fd);
	}
	bonus_check_for_walls(map, i);
	return (close(fd), map);
}
