/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchal <amarchal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 16:10:20 by amarchal          #+#    #+#             */
/*   Updated: 2022/01/31 11:51:46 by amarchal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_check_exit(t_data *data)
{
	if (PLAYER->collected == PLAYER->to_collect)
	{
		mlx_destroy_window(data->mlx, data->mlx->win);
		exit(EXIT_SUCCESS);
	}
	printf("%d remaining items to collect !\n", PLAYER->to_collect - PLAYER->collected);
}

void	move_up(t_data *data)
{
	if (MAP[PLAYER->y - 1][PLAYER->x] == 'E')
		ft_check_exit(data);
	else
	{
		if (MAP[PLAYER->y - 1][PLAYER->x] == 'C')
		{
			PLAYER->collected++;
			ft_print_exit(data, data->player->exit_x, data->player->exit_y);
		}
		MAP[PLAYER->y - 1][PLAYER->x] = 'P';
		MAP[PLAYER->y][PLAYER->x] = '0';
		ft_print_sprite(data, '0', PLAYER->x, PLAYER->y);
		PLAYER->y--;
		ft_print_sprite(data, 'P', PLAYER->x, PLAYER->y);	
		PLAYER->step++;
	}
}

void	move_down(t_data *data)
{
	if (MAP[PLAYER->y + 1][PLAYER->x] == 'E')
		ft_check_exit(data);
	else
	{
		if (MAP[PLAYER->y + 1][PLAYER->x] == 'C')
		{
			PLAYER->collected++;
			ft_print_exit(data, data->player->exit_x, data->player->exit_y);
		}
		MAP[PLAYER->y + 1][PLAYER->x] = 'P';
		MAP[PLAYER->y][PLAYER->x] = '0';
		ft_print_sprite(data, '0', PLAYER->x, PLAYER->y);
		PLAYER->y++;
		ft_print_sprite(data, 'P', PLAYER->x, PLAYER->y);
		PLAYER->step++;
	}
}

void	move_left(t_data *data)
{
	if (MAP[PLAYER->y][PLAYER->x - 1] == 'E')
		ft_check_exit(data);
	else
	{
		if (MAP[PLAYER->y][PLAYER->x - 1] == 'C')
		{
			PLAYER->collected++;
			ft_print_exit(data, data->player->exit_x, data->player->exit_y);
		}
		MAP[PLAYER->y][PLAYER->x - 1] = 'P';
		MAP[PLAYER->y][PLAYER->x] = '0';
		ft_print_sprite(data, '0', PLAYER->x, PLAYER->y);
		PLAYER->x--;
		ft_print_sprite(data, 'P', PLAYER->x, PLAYER->y);
		PLAYER->step++;
	}
}

void	move_right(t_data *data)
{
	if (MAP[PLAYER->y][PLAYER->x + 1] == 'E')
		ft_check_exit(data);
	else
	{
		if (MAP[PLAYER->y][PLAYER->x + 1] == 'C')
		{
			PLAYER->collected++;
			ft_print_exit(data, data->player->exit_x, data->player->exit_y);
		}
		MAP[PLAYER->y][PLAYER->x + 1] = 'P';
		MAP[PLAYER->y][PLAYER->x] = '0';
		ft_print_sprite(data, '0', PLAYER->x, PLAYER->y);
		PLAYER->x++;
		ft_print_sprite(data, 'P', PLAYER->x, PLAYER->y);		
		PLAYER->step++;
	}
}
