/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchal <amarchal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 17:31:31 by amarchal          #+#    #+#             */
/*   Updated: 2022/01/27 17:45:50 by amarchal         ###   ########.fr       */
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

typedef struct s_data
{
	t_parse_info	*map_data;
	t_mlx			*mlx;
}	t_data;


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
	void	*img;
	int		width[1];
	int		height[1];
}	t_mlx;

char	*get_next_line(int fd);
int		ft_end_of_line(char *buff);
char	*ft_strjoin_gnl(char *s1, char *s2);
char	*ft_fill_str(char *str, char *s1, char*s2);
char	**ft_create_map(char *file);
void	ft_check_map(char **map);
void	ft_control_map_data(t_parse_info *data);
void	ft_check_line(char *line, t_parse_info *data, int index, int last_line);
void	ft_check_inline(char c, t_parse_info *data);
void	ft_init_data(t_parse_info *data);
void	ft_print_map(char **map);


#endif