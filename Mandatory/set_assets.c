/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_assets.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oubelhaj <oubelhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 19:12:43 by oubelhaj          #+#    #+#             */
/*   Updated: 2023/03/14 00:35:10 by oubelhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ground(t_vars *vars, int x, int y)
{
	mlx_put_image_to_window(vars->mlx_ptr,
		vars->win_ptr, vars->ground, x * 70, y * 70);
}

void	wall(t_vars *vars, int x, int y)
{
	mlx_put_image_to_window(vars->mlx_ptr,
		vars->win_ptr, vars->wall, x * 70, y * 70);
}

void	coll(t_vars *vars, int x, int y)
{
	mlx_put_image_to_window(vars->mlx_ptr,
		vars->win_ptr, vars->ground, x * 70, y * 70);
	mlx_put_image_to_window(vars->mlx_ptr,
		vars->win_ptr, vars->coll, x * 70, y * 70);
}

void	door(t_vars *vars, int x, int y)
{
	mlx_put_image_to_window(vars->mlx_ptr,
		vars->win_ptr, vars->ground, x * 70, y * 70);
	mlx_put_image_to_window(vars->mlx_ptr,
		vars->win_ptr, vars->door, x * 70, y * 70);
}

void	player(t_vars *vars, int x, int y)
{
	mlx_put_image_to_window(vars->mlx_ptr,
		vars->win_ptr, vars->ground, x * 70, y * 70);
	mlx_put_image_to_window(vars->mlx_ptr,
		vars->win_ptr, vars->player, x * 70, y * 70);
}
