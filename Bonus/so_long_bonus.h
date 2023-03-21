/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oubelhaj <oubelhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 00:38:49 by oubelhaj          #+#    #+#             */
/*   Updated: 2023/03/14 00:38:49 by oubelhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# define UP 126
# define DOWN 125
# define LEFT 123
# define RIGHT 124
# define KEY_W 13
# define KEY_S 1
# define KEY_A 0
# define KEY_D 2
# define KEY_Q 12
# define KEY_ESC 53

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <mlx.h>

typedef struct s_map
{
	int	i;
	int	j;
	int	player;
	int	exit;
	int	collectible;
}	t_map;

typedef struct s_pos
{
	int	x;
	int	y;
}	t_pos;

typedef struct s_vars
{
	char	**map;
	char	**map_dup;
	int		width;
	int		height;
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img;
	void	*player;
	void	*ground;
	void	*wall;
	void	*door;
	void	*coll;
	int		col_count;
	int		moves;
}	t_vars;

int		get_player_pos(t_vars *var, t_pos *pos);
char	*ft_itoa(int n);
char	**ft_split(char const *s, char c);
char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char const *s2);
size_t	ft_strlen(const char *str);
void	set_assets(t_vars *vars);
int		key_check(int key_code, t_vars *vars);
void	read_map(t_vars *vars, char *path);
t_vars	*initialize_vars(char *path);
void	check_rect(char **lines);
void	check_if_valid_path(t_vars	*var);
void	go_left(t_vars *vars, t_pos *pos);
void	go_right(t_vars *vars, t_pos *pos);
void	go_down(t_vars *vars, t_pos *pos);
void	go_up(t_vars *vars, t_pos *pos);
void	ground(t_vars *vars, int x, int y);
void	wall(t_vars *vars, int x, int y);
void	coll(t_vars *vars, int x, int y);
void	door(t_vars *vars, int x, int y);
void	player(t_vars *vars, int x, int y);
int		close_game(t_vars *vars);
void	ft_putstr_fd(char *str, int fd);
int		ft_strstr(const char *haystack, const char *needle);
char	*ft_strdup(const char *s1);
void	exit_error(char *message);
void	initialize(t_vars **vars);
void	map_error(int start, int ext, int col);
void	you_win(t_vars *vars);
int		ft_printf(const char *str, ...);
void	display_moves(t_vars *vars);

#endif