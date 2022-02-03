/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemies_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchal <amarchal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 10:27:46 by amarchal          #+#    #+#             */
/*   Updated: 2022/02/03 14:31:11 by amarchal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_anim_l(t_data *data, t_enem *enemi, int i)
{
	if (i == 0 || i == 8)
		mlx_put_image_to_window(data->mlx->mlx, data->mlx->win, \
		data->img->el_1, enemi->x * SIZE, enemi->y * SIZE);
	if (i == 2 || i == 6)
		mlx_put_image_to_window(data->mlx->mlx, data->mlx->win, \
		data->img->el_2, enemi->x * SIZE, enemi->y * SIZE);
	if (i == 4)
		mlx_put_image_to_window(data->mlx->mlx, data->mlx->win, \
		data->img->el_3, enemi->x * SIZE, enemi->y * SIZE);
	if (i == 10)
		mlx_put_image_to_window(data->mlx->mlx, data->mlx->win, \
		data->img->el_4, enemi->x * SIZE, enemi->y * SIZE);
}

void	ft_anim_r(t_data *data, t_enem *enemi, int i)
{
	if (i == 0 || i == 8)
		mlx_put_image_to_window(data->mlx->mlx, data->mlx->win, \
		data->img->er_1, enemi->x * SIZE, enemi->y * SIZE);
	if (i == 2 || i == 6)
		mlx_put_image_to_window(data->mlx->mlx, data->mlx->win, \
		data->img->er_2, enemi->x * SIZE, enemi->y * SIZE);
	if (i == 4)
		mlx_put_image_to_window(data->mlx->mlx, data->mlx->win, \
		data->img->er_3, enemi->x * SIZE, enemi->y * SIZE);
	if (i == 10)
		mlx_put_image_to_window(data->mlx->mlx, data->mlx->win, \
		data->img->er_4, enemi->x * SIZE, enemi->y * SIZE);
}

void	ft_move_enem(t_data *data, t_enem *enemi, int i)
{
	if (enemi->dir == 'r' && (data->map2d[enemi->y][enemi->x + 1] == '0'
		|| data->map2d[enemi->y][enemi->x + 1] == 'P'))
	{
		data->map2d[enemi->y][enemi->x] = '0';
		mlx_put_image_to_window(data->mlx->mlx, data->mlx->win, \
		data->img->c, enemi->x * SIZE, enemi->y * SIZE);
		enemi->x++;
		ft_anim_r(data, enemi, i);
	}
	if (enemi->dir == 'l' && (data->map2d[enemi->y][enemi->x - 1] == '0'
		|| data->map2d[enemi->y][enemi->x - 1] == 'P'))
	{
		data->map2d[enemi->y][enemi->x] = '0';
		mlx_put_image_to_window(data->mlx->mlx, data->mlx->win, \
		data->img->c, enemi->x * SIZE, enemi->y * SIZE);
		enemi->x--;
		ft_anim_l(data, enemi, i);
	}
	if (enemi->dir == 'r' && (data->map2d[enemi->y][enemi->x + 1] != '0'
		&& data->map2d[enemi->y][enemi->x + 1] != 'P'))
		enemi->dir = 'l';
	else if (enemi->dir == 'l' && (data->map2d[enemi->y][enemi->x - 1] != '0'
		&& data->map2d[enemi->y][enemi->x - 1] != 'P'))
		enemi->dir = 'r';
}

void	ft_animate_enemies(t_data *data)
{
	static int	i = 0;
	static int	j = 0;
	t_enem		*enemi;

	enemi = *data->enem_lst;
	while (enemi)
	{
		if (enemi->dir == 'r')
			ft_anim_r(data, enemi, i);
		else
			ft_anim_l(data, enemi, i);
		if (j == 14)
		{
			ft_move_enem(data, enemi, i);
			ft_check_contact(data);
		}
		enemi = enemi->next;
	}
	i++;
	if (i == 12)
		i = 0;
	j++;
	if (j == 15)
		j = 0;
}

void	ft_check_contact(t_data *data)
{
	t_enem	*enemi;

	enemi = *data->enem_lst;
	while (enemi)
	{
		if (enemi->x == data->player->x && enemi->y == data->player->y)
			ft_exit(data);
		enemi = enemi->next;
	}
}
