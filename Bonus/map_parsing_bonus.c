/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oubelhaj <oubelhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 00:38:34 by oubelhaj          #+#    #+#             */
/*   Updated: 2023/03/14 00:38:34 by oubelhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	check_first_last(char **lines, int len)
{
	int	i;

	i = 0;
	if (len < 3)
		exit_error("Invalid map\n");
	while (lines[0][i + 1])
	{
		if (lines[0][i] != '1')
			exit_error("Invalid map\n");
		i++;
	}
	i = 0;
	while (lines[len - 1][i])
	{
		if (lines[len - 1][i] != '1')
			exit_error("Invalid map\n");
		i++;
	}
}

static void	check_map_chars(char **lines)
{
	t_map	map;
	int		i;
	int		j;

	map.player = 0;
	map.exit = 0;
	map.collectible = 0;
	i = -1;
	while (lines[++i])
	{
		j = -1;
		while (lines[i][++j + 1])
		{
			if (lines[i][j] == 'P')
				map.player++;
			else if (lines[i][j] == 'C')
				map.collectible++;
			else if (lines[i][j] == 'E')
				map.exit++;
			else if (lines[i][j] != '0' && lines[i][j] != '1')
				exit_error("Invalid map elements\n");
		}
	}
	if (map.player != 1 || map.exit != 1 || map.collectible < 1)
		map_error(map.player, map.exit, map.collectible);
}

static int	get_len(char *path)
{
	int		fd;
	int		len;
	char	*tmp;

	len = 0;
	fd = open(path, O_RDONLY);
	if (!fd)
		exit_error("Could not open map file\n");
	tmp = get_next_line(fd);
	while (tmp)
	{
		len++;
		free(tmp);
		tmp = get_next_line(fd);
	}
	close(fd);
	return (len);
}

void	check_rect(char **lines)
{
	int	i;
	int	len;
	int	len2;
	int	len3;

	i = 0;
	len3 = 1;
	len = ft_strlen(lines[i]);
	while (lines[i + 1])
	{
		len2 = ft_strlen(lines[i]);
		if (len != len2)
			exit_error("Invalid map\n");
		if (lines[i][0] != '1' || lines[i][len2 - 2] != '1')
			exit_error("Invalid map\n");
		len3++;
		i++;
	}
	len2 = ft_strlen(lines[i]);
	if (len - 1 != len2)
		exit_error("Invalid map\n");
	if (lines[i][0] != '1' || lines[i][len2 - 1] != '1')
		exit_error("Invalid map\n");
	check_first_last(lines, len3);
	check_map_chars(lines);
}

t_vars	*initialize_vars(char *path)
{
	t_vars	*vars;

	vars = malloc(sizeof(t_vars));
	if (!vars)
		return (0);
	initialize(&vars);
	vars->height = get_len(path);
	if (!vars->height)
		exit_error("Empty map file\n");
	vars->map = malloc(sizeof(char *) * (vars->height + 1));
	if (!vars->map)
		return (0);
	vars->map_dup = malloc(sizeof(char *) * (vars->height + 1));
	if (!vars->map_dup)
		return (0);
	return (vars);
}
