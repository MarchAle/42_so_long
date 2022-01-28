/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchal <amarchal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 16:04:13 by amarchal          #+#    #+#             */
/*   Updated: 2022/01/28 17:42:46 by amarchal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_init_img(t_data *data)
{
	data->mlx->player = mlx_xpm_file_to_image(data->mlx->mlx, "./img/vert.xpm", data->mlx->width, data->mlx->height);
	data->mlx->wall = mlx_xpm_file_to_image(data->mlx->mlx, "./img/test.xpm", data->mlx->width, data->mlx->height);
	data->mlx->floor = mlx_xpm_file_to_image(data->mlx->mlx, "./img/black.xpm", data->mlx->width, data->mlx->height);
	data->mlx->collectible = mlx_xpm_file_to_image(data->mlx->mlx, "./img/jaune.xpm", data->mlx->width, data->mlx->height);
	data->mlx->exit = mlx_xpm_file_to_image(data->mlx->mlx, "./img/bleu.xpm", data->mlx->width, data->mlx->height);
}

void	ft_print_sprite(t_mlx *mlx, char c, int x, int y)
{
	if (c == '1')
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->wall, x * SIZE, y * SIZE);
	if (c == '0')
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->floor, x * SIZE, y * SIZE);
	// if (c == 'P')
	// 	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->player, x * SIZE, y * SIZE);
	if (c == 'C')
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->collectible, x * SIZE, y * SIZE);
	if (c == 'E')
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->exit, x * SIZE, y * SIZE);
}

int	ft_print_map(t_data *data)
{
	int		i;
	int		j;
	
	ft_init_img(data);
	i = 0;
	while (MAP[i])
	{
		j = 0;
		while (MAP[i][j])
		{
			ft_print_sprite(data->mlx, MAP[i][j], j, i);
			j++;
		}
		i++;
	}
	return(0);
}
