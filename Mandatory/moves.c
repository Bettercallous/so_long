/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oubelhaj <oubelhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 17:30:12 by oubelhaj          #+#    #+#             */
/*   Updated: 2023/03/15 02:36:42 by oubelhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	is_valid_move(t_vars *vars, char move)
{
	int	x;
	int	y;

	if (move == '1')
		return (0);
	else if (move == 'C')
	{
		vars->col_count--;
		if (vars->col_count == 0)
		{
			vars->door = mlx_xpm_file_to_image(vars->mlx_ptr,
					"./assets/open_door.xpm", &x, &y);
		}
		return (1);
	}
	else if (move == 'E' && vars->col_count == 0)
	{
		vars->moves++;
		you_win(vars);
		return (close_game(vars));
	}
	else if (move == 'E' && vars->col_count != 0)
		return (0);
	else
		return (1);
}

void	go_up(t_vars *vars, t_pos *pos)
{
	if (is_valid_move(vars, vars->map[pos->y - 1][pos->x]))
	{
		vars->map[pos->y][pos->x] = '0';
		vars->map[pos->y - 1][pos->x] = 'P';
		vars->moves++;
		set_assets(vars);
		printf("Moves : %d\n", vars->moves);
	}
}

void	go_down(t_vars *vars, t_pos *pos)
{
	if (is_valid_move(vars, vars->map[pos->y + 1][pos->x]))
	{
		vars->map[pos->y][pos->x] = '0';
		vars->map[pos->y + 1][pos->x] = 'P';
		vars->moves++;
		set_assets(vars);
		printf("Moves : %d\n", vars->moves);
	}
}

void	go_right(t_vars *vars, t_pos *pos)
{
	int	x;
	int	y;

	if (is_valid_move(vars, vars->map[pos->y][pos->x + 1]))
	{
		vars->map[pos->y][pos->x] = '0';
		vars->map[pos->y][pos->x + 1] = 'P';
		vars->player = mlx_xpm_file_to_image(vars->mlx_ptr,
				"./assets/veridis.xpm", &x, &y);
		vars->moves++;
		set_assets(vars);
		ft_printf("Moves : %d\n", vars->moves);
	}
}

void	go_left(t_vars *vars, t_pos *pos)
{
	int	x;
	int	y;

	if (is_valid_move(vars, vars->map[pos->y][pos->x - 1]))
	{
		vars->map[pos->y][pos->x] = '0';
		vars->map[pos->y][pos->x - 1] = 'P';
		vars->player = mlx_xpm_file_to_image(vars->mlx_ptr,
				"./assets/rveridis.xpm", &x, &y);
		vars->moves++;
		set_assets(vars);
		ft_printf("Moves : %d\n", vars->moves);
	}
}
