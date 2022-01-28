/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchal <amarchal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 12:13:59 by amarchal          #+#    #+#             */
/*   Updated: 2022/01/28 18:03:07 by amarchal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_move(t_data *data, char *move)
{
	if (MAP[PLAYER->y - 1][PLAYER->x] != '1' && !ft_strncmp(move, "up", 2))
		move_up(data);
	if (MAP[PLAYER->y + 1][PLAYER->x] != '1' && !ft_strncmp(move, "down", 4))
		move_down(data);
	if (MAP[PLAYER->y][PLAYER->x - 1] != '1' && !ft_strncmp(move, "left", 4))
		move_left(data);
	if (MAP[PLAYER->y][PLAYER->x + 1] != '1' && !ft_strncmp(move, "right", 5))
		move_right(data);
	printf("step %d\n", PLAYER->step);
}

int	key_hook(int keycode, t_data *data)
{
	if (keycode == 13)
		ft_move(data, "up");
	if (keycode == 1)
		ft_move(data, "down");
	if (keycode == 0)
		ft_move(data, "left");
	if (keycode == 2)
		ft_move(data, "right");
	if (keycode == 53)
	{
		mlx_destroy_window(data->mlx, data->mlx->win);
		exit(EXIT_SUCCESS);
	}
	ft_game(data);
	return (0);
}

int	ft_exit(void *param)
{
	(void)param;
	exit(EXIT_SUCCESS);
}

void	ft_animate_player(t_data *data)
{
	mlx_put_image_to_window(data->mlx->mlx, data->mlx->win, data->mlx->player, PLAYER->x * SIZE, PLAYER->y * SIZE);
}

void	ft_game(t_data *data)
{
	// data->mlx->mlx = mlx_init();
	// data->mlx->win = mlx_new_window(data->mlx->mlx, ft_strlen(MAP[0]) * SIZE, ft_strlen2d(MAP) * SIZE, "So Long");
	ft_animate_player(data);
	// ft_print_map(data);
	// mlx_do_key_autorepeatoff(data->mlx->mlx);
	mlx_key_hook(data->mlx->win, key_hook, data);
	mlx_hook(data->mlx->win, 17, 0, ft_exit, NULL);
	mlx_loop(data->mlx->mlx);
}
