/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchal <amarchal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 16:04:13 by amarchal          #+#    #+#             */
/*   Updated: 2022/02/05 13:37:14 by amarchal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_print_wall(t_data *data, int x, int y)
{
	if (y == 0 && x == 0)
		mlx_put_image_to_window(data->mlx->mlx, data->mlx->win, \
		data->img->tl, x * SIZE, y * SIZE);
	else if (y == 0 && x == (int)ft_strlen(data->map2d[0]) - 1)
		mlx_put_image_to_window(data->mlx->mlx, data->mlx->win, \
		data->img->tr, x * SIZE, y * SIZE);
	else if (y == 0)
		mlx_put_image_to_window(data->mlx->mlx, data->mlx->win, \
		data->img->t, x * SIZE, y * SIZE);
	else if (y == (int)ft_strlen2d(data->map2d) - 1 && x == 0)
		mlx_put_image_to_window(data->mlx->mlx, data->mlx->win, \
		data->img->bl, x * SIZE, y * SIZE);
	else if (y == (int)ft_strlen2d(data->map2d) - 1
		&& x == (int)ft_strlen(data->map2d[0]) - 1)
		mlx_put_image_to_window(data->mlx->mlx, data->mlx->win, \
		data->img->br, x * SIZE, y * SIZE);
	else
		ft_print_wall_bis(data, x, y);
}

void	ft_print_wall_bis(t_data *data, int x, int y)
{
	if (y == (int)ft_strlen2d(data->map2d) - 1)
		mlx_put_image_to_window(data->mlx->mlx, data->mlx->win, \
		data->img->b, x * SIZE, y * SIZE);
	else if (x == 0)
		mlx_put_image_to_window(data->mlx->mlx, data->mlx->win, \
		data->img->l, x * SIZE, y * SIZE);
	else if (x == (int)ft_strlen(data->map2d[0]) - 1)
		mlx_put_image_to_window(data->mlx->mlx, data->mlx->win, \
		data->img->r, x * SIZE, y * SIZE);
	else
		mlx_put_image_to_window(data->mlx->mlx, data->mlx->win, \
		data->img->rocks, x * SIZE, y * SIZE);
}

void	ft_print_exit(t_data *data, int x, int y)
{
	if (data->player->to_collect - data->player->collected == 0)
		mlx_put_image_to_window(data->mlx->mlx, data->mlx->win, \
		data->img->e_open, x * SIZE, y * SIZE);
	else if (data->player->to_collect - data->player->collected == 1)
		mlx_put_image_to_window(data->mlx->mlx, data->mlx->win, \
		data->img->e1, x * SIZE, y * SIZE);
	else if (data->player->to_collect - data->player->collected == 2)
		mlx_put_image_to_window(data->mlx->mlx, data->mlx->win, \
		data->img->e2, x * SIZE, y * SIZE);
	else if (data->player->to_collect - data->player->collected == 3)
		mlx_put_image_to_window(data->mlx->mlx, data->mlx->win, \
		data->img->e3, x * SIZE, y * SIZE);
	else if (data->player->to_collect - data->player->collected == 4)
		mlx_put_image_to_window(data->mlx->mlx, data->mlx->win, \
		data->img->e4, x * SIZE, y * SIZE);
	else if (data->player->to_collect - data->player->collected == 5)
		mlx_put_image_to_window(data->mlx->mlx, data->mlx->win, \
		data->img->e5, x * SIZE, y * SIZE);
	else if (data->player->to_collect - data->player->collected == 6)
		mlx_put_image_to_window(data->mlx->mlx, data->mlx->win, \
		data->img->e6, x * SIZE, y * SIZE);
	else
		mlx_put_image_to_window(data->mlx->mlx, data->mlx->win, \
		data->img->e7, x * SIZE, y * SIZE);
}

void	ft_print_sprite(t_data *data, char c, int x, int y)
{
	if (c == '1')
		ft_print_wall(data, x, y);
	if (c == '0')
		mlx_put_image_to_window(data->mlx->mlx, data->mlx->win, \
		data->img->floor, x * SIZE, y * SIZE);
	if (c == 'C')
		mlx_put_image_to_window(data->mlx->mlx, data->mlx->win, \
		data->img->collectible, x * SIZE, y * SIZE);
	if (c == 'E')
		ft_print_exit(data, x, y);
}

int	ft_print_map(t_data *data)
{
	int		i;
	int		j;

	ft_init_img(data);
	i = 0;
	while (data->map2d[i])
	{
		j = 0;
		while (data->map2d[i][j])
		{
			ft_print_sprite(data, data->map2d[i][j], j, i);
			j++;
		}
		i++;
	}
	return (0);
}
