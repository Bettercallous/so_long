/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oubelhaj <oubelhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 00:37:56 by oubelhaj          #+#    #+#             */
/*   Updated: 2023/03/14 00:37:56 by oubelhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	flood_fill(t_vars *vars, int x, int y)
{
	if (x < 0 || y < 0 || y >= vars->height || y >= vars->width)
		return ;
	if (vars->map_dup[y][x] != 'P' && vars->map_dup[y][x] != 'C'
		&& vars->map_dup[y][x] != '0')
		return ;
	vars->map_dup[y][x] = 'S';
	flood_fill(vars, x + 1, y);
	flood_fill(vars, x - 1, y);
	flood_fill(vars, x, y + 1);
	flood_fill(vars, x, y - 1);
}

static int	check_exit(char **map, int x, int y)
{
	if (map[x + 1][y] == 'S' || map[x - 1][y] == 'S'
		|| map[x][y + 1] == 'S' || map[x][y - 1] == 'S')
		return (1);
	else
		return (0);
}

static int	valid_exit(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'E')
				return (check_exit(map, i, j));
			j++;
		}
		i++;
	}
	return (0);
}

int	get_player_pos(t_vars *var, t_pos *pos)
{
	int	y;
	int	x;

	y = 0;
	while (var->map[y])
	{
		x = 0;
		while (var->map[y][x])
		{
			if (var->map[y][x] == 'P')
			{
				pos->y = y;
				pos->x = x;
				return (1);
			}
			x++;
		}
		y++;
	}
	return (0);
}

void	check_if_valid_path(t_vars	*var)
{
	int		i;
	int		j;
	int		c;
	t_pos	pos;

	c = 0;
	i = -1;
	get_player_pos(var, &pos);
	flood_fill(var, pos.x, pos.y);
	if (!valid_exit(var->map_dup))
		exit_error("No valid path in the map\n");
	while (var->map_dup[++i])
	{
		j = -1;
		while (var->map_dup[i][++j])
		{
			if (var->map_dup[i][j] == 'C')
				c++;
		}
	}
	if (c != 0)
		exit_error("No valid path in the map\n");
}
