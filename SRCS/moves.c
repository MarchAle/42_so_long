/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchal <amarchal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 16:10:20 by amarchal          #+#    #+#             */
/*   Updated: 2022/02/03 11:38:04 by amarchal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_check_exit(t_data *data)
{
	if (data->player->collected == data->player->to_collect)
	{
		mlx_destroy_window(data->mlx, data->mlx->win);
		exit(EXIT_SUCCESS);
	}
	printf("%d remaining items to collect !\n", \
	data->player->to_collect - data->player->collected);
}

void	move_up(t_data *data)
{
	if (data->map2d[data->player->y - 1][data->player->x] == 'E')
		ft_check_exit(data);
	else
	{
		if (data->map2d[data->player->y - 1][data->player->x] == 'C')
		{
			data->player->collected++;
			ft_print_exit(data, data->player->exit_x, data->player->exit_y);
		}
		data->map2d[data->player->y][data->player->x] = '0';
		data->player->y--;
		ft_print_sprite(data, 'P', data->player->x, data->player->y);
		ft_print_sprite(data, '0', data->player->x, data->player->y + 1);
		data->player->step++;
	}
}

void	move_down(t_data *data)
{
	if (data->map2d[data->player->y + 1][data->player->x] == 'E')
		ft_check_exit(data);
	else
	{
		if (data->map2d[data->player->y + 1][data->player->x] == 'C')
		{
			data->player->collected++;
			ft_print_exit(data, data->player->exit_x, data->player->exit_y);
		}
		data->map2d[data->player->y][data->player->x] = '0';
		data->player->y++;
		ft_print_sprite(data, 'P', data->player->x, data->player->y);
		ft_print_sprite(data, '0', data->player->x, data->player->y - 1);
		data->player->step++;
	}
}

void	move_left(t_data *data)
{
	if (data->map2d[data->player->y][data->player->x - 1] == 'E')
		ft_check_exit(data);
	else
	{
		if (data->map2d[data->player->y][data->player->x - 1] == 'C')
		{
			data->player->collected++;
			ft_print_exit(data, data->player->exit_x, data->player->exit_y);
		}
		data->map2d[data->player->y][data->player->x] = '0';
		data->player->x--;
		ft_print_sprite(data, 'P', data->player->x, data->player->y);
		ft_print_sprite(data, '0', data->player->x + 1, data->player->y);
		data->player->step++;
	}
}

void	move_right(t_data *data)
{
	if (data->map2d[data->player->y][data->player->x + 1] == 'E')
		ft_check_exit(data);
	else
	{
		if (data->map2d[data->player->y][data->player->x + 1] == 'C')
		{
			data->player->collected++;
			ft_print_exit(data, data->player->exit_x, data->player->exit_y);
		}
		data->map2d[data->player->y][data->player->x] = '0';
		data->player->x++;
		ft_print_sprite(data, 'P', data->player->x, data->player->y);
		ft_print_sprite(data, '0', data->player->x - 1, data->player->y);
		data->player->step++;
	}
}
