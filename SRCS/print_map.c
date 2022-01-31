/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchal <amarchal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 16:04:13 by amarchal          #+#    #+#             */
/*   Updated: 2022/01/31 17:32:27 by amarchal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_init_wall_img(t_data *data)
{
	data->img->tl = mlx_xpm_file_to_image(data->mlx->mlx, "./img/tl.xpm", data->mlx->width, data->mlx->height);
	data->img->t = mlx_xpm_file_to_image(data->mlx->mlx, "./img/t.xpm", data->mlx->width, data->mlx->height);
	data->img->tr = mlx_xpm_file_to_image(data->mlx->mlx, "./img/tr.xpm", data->mlx->width, data->mlx->height);
	data->img->l = mlx_xpm_file_to_image(data->mlx->mlx, "./img/l.xpm", data->mlx->width, data->mlx->height);
	data->img->c = mlx_xpm_file_to_image(data->mlx->mlx, "./img/c.xpm", data->mlx->width, data->mlx->height);
	data->img->r = mlx_xpm_file_to_image(data->mlx->mlx, "./img/r.xpm", data->mlx->width, data->mlx->height);
	data->img->bl = mlx_xpm_file_to_image(data->mlx->mlx, "./img/bl.xpm", data->mlx->width, data->mlx->height);
	data->img->b = mlx_xpm_file_to_image(data->mlx->mlx, "./img/b.xpm", data->mlx->width, data->mlx->height);
	data->img->br = mlx_xpm_file_to_image(data->mlx->mlx, "./img/br.xpm", data->mlx->width, data->mlx->height);
	data->img->rocks = mlx_xpm_file_to_image(data->mlx->mlx, "./img/rocks.xpm", data->mlx->width, data->mlx->height);
	data->img->gem = mlx_xpm_file_to_image(data->mlx->mlx, "./img/gem.xpm", data->mlx->width, data->mlx->height);
}

void	ft_init_exit_img(t_data *data)
{
	data->img->e_open = mlx_xpm_file_to_image(data->mlx->mlx, "./img/e_open.xpm", data->mlx->width, data->mlx->height);
	data->img->e1 = mlx_xpm_file_to_image(data->mlx->mlx, "./img/e1.xpm", data->mlx->width, data->mlx->height);
	data->img->e2 = mlx_xpm_file_to_image(data->mlx->mlx, "./img/e2.xpm", data->mlx->width, data->mlx->height);
	data->img->e3 = mlx_xpm_file_to_image(data->mlx->mlx, "./img/e3.xpm", data->mlx->width, data->mlx->height);
	data->img->e4 = mlx_xpm_file_to_image(data->mlx->mlx, "./img/e4.xpm", data->mlx->width, data->mlx->height);
	data->img->e5 = mlx_xpm_file_to_image(data->mlx->mlx, "./img/e5.xpm", data->mlx->width, data->mlx->height);
	data->img->e6 = mlx_xpm_file_to_image(data->mlx->mlx, "./img/e6.xpm", data->mlx->width, data->mlx->height);
	data->img->e7 = mlx_xpm_file_to_image(data->mlx->mlx, "./img/e7.xpm", data->mlx->width, data->mlx->height);
}

void	ft_init_img(t_data *data)
{
	ft_init_wall_img(data);
	ft_init_exit_img(data);
	ft_change_anim_front(data);
	data->img->floor = mlx_xpm_file_to_image(data->mlx->mlx, "./img/c.xpm", data->mlx->width, data->mlx->height);
	data->img->collectible = mlx_xpm_file_to_image(data->mlx->mlx, "./img/gem.xpm", data->mlx->width, data->mlx->height);
}

void	ft_print_wall(t_data *data, int x, int y)
{
	if (y == 0 && x == 0)
		mlx_put_image_to_window(data->mlx->mlx, data->mlx->win, data->img->tl, x * SIZE, y * SIZE);
	else if (y == 0 && x == (int)ft_strlen(data->map2d[0]) - 1)
		mlx_put_image_to_window(data->mlx->mlx, data->mlx->win, data->img->tr, x * SIZE, y * SIZE);
	else if (y == 0)
		mlx_put_image_to_window(data->mlx->mlx, data->mlx->win, data->img->t, x * SIZE, y * SIZE);
	else if (y == (int)ft_strlen2d(data->map2d) - 1 && x == 0)
		mlx_put_image_to_window(data->mlx->mlx, data->mlx->win, data->img->bl, x * SIZE, y * SIZE);
	else if (y == (int)ft_strlen2d(data->map2d) - 1 && x == (int)ft_strlen(data->map2d[0]) - 1)
		mlx_put_image_to_window(data->mlx->mlx, data->mlx->win, data->img->br, x * SIZE, y * SIZE);
	else if (y == (int)ft_strlen2d(data->map2d) - 1)
		mlx_put_image_to_window(data->mlx->mlx, data->mlx->win, data->img->b, x * SIZE, y * SIZE);
	else if (x == 0)
		mlx_put_image_to_window(data->mlx->mlx, data->mlx->win, data->img->l, x * SIZE, y * SIZE);
	else if (x == (int)ft_strlen(data->map2d[0]) - 1)
		mlx_put_image_to_window(data->mlx->mlx, data->mlx->win, data->img->r, x * SIZE, y * SIZE);
	else
		mlx_put_image_to_window(data->mlx->mlx, data->mlx->win, data->img->rocks, x * SIZE, y * SIZE);
}

void	ft_print_exit(t_data *data, int x, int y)
{
	if (data->player->to_collect - data->player->collected == 0)
		mlx_put_image_to_window(data->mlx->mlx, data->mlx->win, data->img->e_open, x * SIZE, y * SIZE);
	else if (data->player->to_collect - data->player->collected == 1)
		mlx_put_image_to_window(data->mlx->mlx, data->mlx->win, data->img->e1, x * SIZE, y * SIZE);
	else if (data->player->to_collect - data->player->collected == 2)
		mlx_put_image_to_window(data->mlx->mlx, data->mlx->win, data->img->e2, x * SIZE, y * SIZE);
	else if (data->player->to_collect - data->player->collected == 3)
		mlx_put_image_to_window(data->mlx->mlx, data->mlx->win, data->img->e3, x * SIZE, y * SIZE);
	else if (data->player->to_collect - data->player->collected == 4)
		mlx_put_image_to_window(data->mlx->mlx, data->mlx->win, data->img->e4, x * SIZE, y * SIZE);
	else if (data->player->to_collect - data->player->collected == 5)
		mlx_put_image_to_window(data->mlx->mlx, data->mlx->win, data->img->e5, x * SIZE, y * SIZE);
	else if (data->player->to_collect - data->player->collected == 6)
		mlx_put_image_to_window(data->mlx->mlx, data->mlx->win, data->img->e6, x * SIZE, y * SIZE);
	else
		mlx_put_image_to_window(data->mlx->mlx, data->mlx->win, data->img->e7, x * SIZE, y * SIZE);
}

void	ft_print_sprite(t_data *data, char c, int x, int y)
{
	if (c == '1')
		ft_print_wall(data, x, y);
	if (c == '0')
		mlx_put_image_to_window(data->mlx->mlx, data->mlx->win, data->img->floor, x * SIZE, y * SIZE);
	// if (c == 'P')
		// mlx_put_image_to_window(data->mlx->mlx, data->mlx->win, data->p_anim->p_1, x * SIZE, y * SIZE);
	if (c == 'C')
		mlx_put_image_to_window(data->mlx->mlx, data->mlx->win, data->img->collectible, x * SIZE, y * SIZE);
	if (c == 'E')
		ft_print_exit(data, x, y);
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
			ft_print_sprite(data, MAP[i][j], j, i);
			j++;
		}
		i++;
	}
	return(0);
}
