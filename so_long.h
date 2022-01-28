/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchal <amarchal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 17:31:31 by amarchal          #+#    #+#             */
/*   Updated: 2022/01/28 17:39:50 by amarchal         ###   ########.fr       */
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

# define SIZE 32

# define MAP data->map2d
# define PLAYER data->player

typedef struct s_player
{
	int	x;
	int	y;
	int	to_collect;
	int	collected;
	int	step;
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
	void	*player;
	void	*wall;
	void	*floor;
	void	*collectible;
	void	*exit;
	int		width[1];
	int		height[1];
}	t_mlx;

typedef struct s_data
{
	char			**map2d;
	t_mlx			*mlx;
	t_player		*player;
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

void	ft_map_info(t_data *data);
void	ft_print_sprite(t_mlx *mlx, char c, int x, int y);
int		ft_print_map(t_data *data);

void	ft_game(t_data *data);
void	move_up(t_data *data);
void	move_down(t_data *data);
void	move_left(t_data *data);
void	move_right(t_data *data);

#endif