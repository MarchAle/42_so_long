/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchal <amarchal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 12:13:59 by amarchal          #+#    #+#             */
/*   Updated: 2022/02/02 13:35:47 by amarchal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_move(t_data *data, char *move)
{
	if (data->map2d[data->player->y - 1][data->player->x] != '1'
		&& !ft_strncmp(move, "up", 2))
		move_up(data);
	if (data->map2d[data->player->y + 1][data->player->x] != '1'
		&& !ft_strncmp(move, "down", 4))
		move_down(data);
	if (data->map2d[data->player->y][data->player->x - 1] != '1'
		&& !ft_strncmp(move, "left", 4))
		move_left(data);
	if (data->map2d[data->player->y][data->player->x + 1] != '1'
		&& !ft_strncmp(move, "right", 5))
		move_right(data);
	printf("step %d\n", data->player->step);
}

int	key_hook(int keycode, t_data *data)
{
	if (keycode == 13)
	{
		ft_change_anim(data, "up");
		ft_move(data, "up");
	}
	if (keycode == 1)
	{
		ft_change_anim(data, "down");
		ft_move(data, "down");
	}
	if (keycode == 0)
	{
		ft_change_anim(data, "left");
		ft_move(data, "left");
	}
	if (keycode == 2)
	{
		ft_change_anim(data, "right");
		ft_move(data, "right");
	}
	if (keycode == 53)
		ft_exit(data);
	return (0);
}

void	ft_animate_player(t_data *data)
{
	static int	i = 0;
	char		*step;

	if (i == 0 || i == 4)
		mlx_put_image_to_window(data->mlx->mlx, data->mlx->win, \
		data->p_anim->p_1, data->player->x * SIZE, data->player->y * SIZE);
	if (i == 1 || i == 3)
		mlx_put_image_to_window(data->mlx->mlx, data->mlx->win, \
		data->p_anim->p_2, data->player->x * SIZE, data->player->y * SIZE);
	if (i == 2)
		mlx_put_image_to_window(data->mlx->mlx, data->mlx->win, \
		data->p_anim->p_3, data->player->x * SIZE, data->player->y * SIZE);
	if (i == 5)
		mlx_put_image_to_window(data->mlx->mlx, data->mlx->win, \
		data->p_anim->p_4, data->player->x * SIZE, data->player->y * SIZE);
	step = ft_itoa(data->player->step);
	mlx_string_put(data->mlx->mlx, data->mlx->win, \
	(data->player->x * 100) + 10, (data->player->y * 100) + 10, 0x934d1d, step);
	free(step);
	i++;
	if (i == 6)
		i = 0;
}

int	ft_animate(t_data *data)
{
	ft_animate_player(data);
	ft_animate_enemies(data);
	usleep(50000);
	return (0);
}

int	ft_exit(t_data *data)
{
	mlx_destroy_window(data->mlx, data->mlx->win);
	exit(EXIT_SUCCESS);
}
