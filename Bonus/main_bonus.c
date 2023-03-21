/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oubelhaj <oubelhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 00:38:28 by oubelhaj          #+#    #+#             */
/*   Updated: 2023/03/20 06:06:43 by oubelhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	key_check(int key_code, t_vars *vars)
{
	t_pos	pos;

	get_player_pos(vars, &pos);
	if (key_code == UP || key_code == KEY_W)
	{
		go_up(vars, &pos);
	}
	else if (key_code == DOWN || key_code == KEY_S)
	{
		go_down(vars, &pos);
	}
	else if (key_code == RIGHT || key_code == KEY_D)
	{
		go_right(vars, &pos);
	}
	else if (key_code == LEFT || key_code == KEY_A)
	{
		go_left(vars, &pos);
	}
	else if (key_code == KEY_ESC || key_code == KEY_Q)
		close_game(vars);
	return (0);
}

void	set_assets(t_vars *vars)
{
	int	x;
	int	y;

	y = 0;
	while (vars->map[y])
	{
		x = 0;
		while (vars->map[y][x])
		{
			if (vars->map[y][x] == '0')
				ground(vars, x, y);
			else if (vars->map[y][x] == '1')
				wall(vars, x, y);
			else if (vars->map[y][x] == 'C')
				coll(vars, x, y);
			else if (vars->map[y][x] == 'E')
				door(vars, x, y);
			else if (vars->map[y][x] == 'P')
				player(vars, x, y);
			x++;
		}
		y++;
	}
	display_moves(vars);
}

static t_vars	*parse_map(char *path)
{
	int		i;
	int		j;
	t_vars	*vars;

	i = -1;
	if (!ft_strstr(path, ".ber"))
		exit_error("Invalid map file\n");
	vars = initialize_vars(path);
	read_map(vars, path);
	check_rect(vars->map);
	vars->width = ft_strlen(vars->map[0]) - 1;
	check_if_valid_path(vars);
	while (vars->map[++i])
	{
		j = 0;
		while (vars->map[i][j])
		{
			if (vars->map[i][j] == 'C')
				vars->col_count++;
			j++;
		}
	}
	return (vars);
}

static void	set_images(t_vars *vars)
{
	int	x;
	int	y;

	x = 70;
	y = 70;
	vars->player = mlx_xpm_file_to_image(vars->mlx_ptr,
			"./assets/veridis.xpm", &x, &y);
	vars->ground = mlx_xpm_file_to_image(vars->mlx_ptr,
			"./assets/ground.xpm", &x, &y);
	vars->coll = mlx_xpm_file_to_image(vars->mlx_ptr,
			"./assets/milk.xpm", &x, &y);
	vars->door = mlx_xpm_file_to_image(vars->mlx_ptr,
			"./assets/closed_door.xpm", &x, &y);
	vars->wall = mlx_xpm_file_to_image(vars->mlx_ptr,
			"./assets/wall.xpm", &x, &y);
	if (!vars->player || !vars->ground || !vars->coll
		|| !vars->door || !vars->wall)
		exit_error("Invalid images\n");
}

int	main(int ac, char **av)
{
	t_vars	*vars;

	if (ac != 2)
		exit_error("Invalid number of arguments\n");
	vars = parse_map(av[1]);
	vars->mlx_ptr = mlx_init();
	vars->win_ptr = mlx_new_window(vars->mlx_ptr,
			vars->width * 70, vars->height * 70, "so_long");
	set_images(vars);
	set_assets(vars);
	mlx_hook(vars->win_ptr, 2, 0, key_check, vars);
	mlx_hook(vars->win_ptr, 17, 0, close_game, vars);
	mlx_loop(vars->mlx_ptr);
}
