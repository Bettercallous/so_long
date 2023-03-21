/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oubelhaj <oubelhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 00:38:57 by oubelhaj          #+#    #+#             */
/*   Updated: 2023/03/20 06:03:14 by oubelhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	initialize(t_vars **vars)
{
	(*vars)->map = 0;
	(*vars)->map_dup = 0;
	(*vars)->width = 0;
	(*vars)->height = 0;
	(*vars)->mlx_ptr = 0;
	(*vars)->win_ptr = 0;
	(*vars)->img = 0;
	(*vars)->player = 0;
	(*vars)->ground = 0;
	(*vars)->wall = 0;
	(*vars)->door = 0;
	(*vars)->coll = 0;
	(*vars)->col_count = 0;
	(*vars)->moves = 0;
}

void	map_error(int start, int ext, int col)
{
	ft_printf("Error\n");
	if (start != 1)
		ft_printf("The map must contain 1 player\n");
	if (ext != 1)
		ft_printf("The map must contain 1 exit\n");
	if (col < 1)
		ft_printf("The map must contain at least 1 collectible\n");
	exit(1);
}

void	you_win(t_vars *vars)
{
	printf("Moves : %d\n", vars->moves);
	ft_printf("                                                           \n");
	ft_printf("                                                           \n");
	ft_printf("                                                           \n");
	ft_printf("\033[1;31m ######    ######      ##      ## ########\n\033[0m");
	ft_printf("\033[1;31m##    ##  ##    ##     ##  ##  ## ##     ##\n\033[0m");
	ft_printf("\033[1;31m##        ##           ##  ##  ## ##     ##\n\033[0m");
	ft_printf("\033[1;31m##   #### ##   ####    ##  ##  ## ########\n\033[0m");
	ft_printf("\033[1;31m##    ##  ##    ##     ##  ##  ## ##\n\033[0m");
	ft_printf("\033[1;31m##    ##  ##    ##     ##  ##  ## ##\n\033[0m");
	ft_printf("\033[1;31m ######    ######       ###  ###  ##\n\033[0m");
	ft_printf("                                                           \n");
	ft_printf("                                                           \n");
	ft_printf("                                                           \n");
}

void	read_map(t_vars *vars, char *path)
{
	int	i;
	int	fd;

	i = -1;
	fd = open(path, O_RDONLY);
	if (!fd)
		exit_error("Could not open map file\n");
	while (++i < vars->height)
	{
		vars->map[i] = get_next_line(fd);
		vars->map_dup[i] = ft_strdup(vars->map[i]);
	}
	vars->map[i] = 0;
	vars->map_dup[i] = 0;
	close(fd);
}

void	display_moves(t_vars *vars)
{
	char	*tmp;
	char	*str;

	tmp = ft_itoa(vars->moves);
	str = ft_strjoin(ft_strdup("	Moves : "), tmp);
	free(tmp);
	mlx_string_put(vars->mlx_ptr, vars->win_ptr, 25, 0, 0x00000000, str);
	free(str);
}
