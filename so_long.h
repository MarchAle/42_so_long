/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchal <amarchal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 17:31:31 by amarchal          #+#    #+#             */
/*   Updated: 2022/02/01 16:51:29 by amarchal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <fcntl.h>
# include "./mlx/mlx.h"
# include "./libft/libft.h"

# define TRUE 1
# define FALSE 0

# define SIZE 100

# define MAP data->map2d
# define PLAYER data->player

typedef struct s_player
{
	int		x;
	int		y;
	int		to_collect;
	int		collected;
	int		step;
	int		exit_x;
	int		exit_y;
	int		enemies;
	char	**e_pos;
}	t_player;

typedef struct s_parse_info
{
	int	outline;
	int	collectible;
	int	exit;
	int	player;
	int	error;
	int	line_len;
}	t_parse_info;

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	int		width[1];
	int		height[1];
}	t_mlx;

typedef struct s_img
{
	void	*tl;
	void	*t;
	void	*tr;
	void	*l;
	void	*c;
	void	*r;
	void	*bl;
	void	*b;
	void	*br;
	void	*e_open;
	void	*e1;
	void	*e2;
	void	*e3;
	void	*e4;
	void	*e5;
	void	*e6;
	void	*e7;
	void	*rocks;
	void	*gem;
	// void	*player;
	void	*enem;
	void	*floor;
	void	*collectible;
	void	*el_1;
	void	*el_2;
	void	*el_3;
	void	*el_4;
	void	*er_1;
	void	*er_2;
	void	*er_3;
	void	*er_4;
}	t_img;

typedef struct s_anim
{
	void	*p_1;
	void	*p_2;
	void	*p_3;
	void	*p_4;
}	t_anim;

typedef struct s_enem
{
	int				x;
	int				y;
	char			dir;
	struct s_enem	*next;
}	t_enem;

typedef struct s_data
{
	char			**map2d;
	t_mlx			*mlx;
	t_player		*player;
	t_img			*img;
	t_anim			*p_anim;
	t_enem			**enem_lst;
}	t_data;

char	*get_next_line(int fd);
int		ft_end_of_line(char *buff);
char	*ft_strjoin_gnl(char *s1, char *s2);
char	*ft_fill_str(char *str, char *s1, char*s2);
void	ft_check_file(char *file);
char	**ft_create_map(char *file);
void	ft_check_map(char **map);
void	ft_init_map_info(t_parse_info *data);
void	ft_check_line(char *line, t_parse_info *data, int index, int last_line);
void	ft_check_inline(char c, t_parse_info *data);
void	ft_control_map_data(t_parse_info *data);

void	ft_add_enemi(t_data *data, int i, int j);
void	ft_map_info(t_data *data);

void	ft_print_sprite(t_data *data, char c, int x, int y);
void	ft_print_wall(t_data *data, int x, int y);
void	ft_print_exit(t_data *data, int x, int y);
int		ft_print_map(t_data *data);

int		key_hook(int keycode, t_data *data);

int		ft_animate(t_data *data);
void	ft_animate_player(t_data *data);
void	ft_change_anim(t_data *data, char *dir);
void	ft_change_anim_front(t_data *data);
void	ft_change_anim_back(t_data *data);
void	ft_change_anim_left(t_data *data);
void	ft_change_anim_right(t_data *data);

void	ft_game(t_data *data);
void	move_up(t_data *data);
void	move_down(t_data *data);
void	move_left(t_data *data);
void	move_right(t_data *data);

int		ft_exit(t_data *data);

#endif