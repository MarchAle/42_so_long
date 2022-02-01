/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchal <amarchal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 12:13:59 by amarchal          #+#    #+#             */
/*   Updated: 2022/02/01 17:53:58 by amarchal         ###   ########.fr       */
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

int	ft_exit(t_data *data)
{
	mlx_destroy_window(data->mlx, data->mlx->win);
	exit(EXIT_SUCCESS);
}

void	ft_animate_player(t_data *data)
{
	static int	i = 0;
	if (i == 0 || i == 4)
		mlx_put_image_to_window(data->mlx->mlx, data->mlx->win, data->p_anim->p_1, PLAYER->x * SIZE, PLAYER->y * SIZE);
	if (i == 1 || i == 3)
		mlx_put_image_to_window(data->mlx->mlx, data->mlx->win, data->p_anim->p_2, PLAYER->x * SIZE, PLAYER->y * SIZE);
	if (i == 2)
		mlx_put_image_to_window(data->mlx->mlx, data->mlx->win, data->p_anim->p_3, PLAYER->x * SIZE, PLAYER->y * SIZE);
	if (i == 5)
		mlx_put_image_to_window(data->mlx->mlx, data->mlx->win, data->p_anim->p_4, PLAYER->x * SIZE, PLAYER->y * SIZE);
	mlx_string_put(data->mlx->mlx, data->mlx->win, (PLAYER->x * 100) + 10, (PLAYER->y * 100) + 10, 0x934d1d, ft_itoa(PLAYER->step)); //ft_itoa(PLAYER->step)
	usleep(50000);
	i++;
	if (i == 6)
		i = 0;
}

void	ft_anim_l(t_data *data, t_enem *enemi, int i)
{
	if (i == 0 || i == 5)
		mlx_put_image_to_window(data->mlx->mlx, data->mlx->win, data->img->el_4, enemi->x * SIZE, enemi->y * SIZE);
	if (i == 1 || i == 3)
		mlx_put_image_to_window(data->mlx->mlx, data->mlx->win, data->img->el_3, enemi->x * SIZE, enemi->y * SIZE);
	if (i == 2)
		mlx_put_image_to_window(data->mlx->mlx, data->mlx->win, data->img->el_2, enemi->x * SIZE, enemi->y * SIZE);
	if (i == 6)
		mlx_put_image_to_window(data->mlx->mlx, data->mlx->win, data->img->el_1, enemi->x * SIZE, enemi->y * SIZE);
}

void	ft_anim_r(t_data *data, t_enem *enemi, int i)
{
	if (i == 0 || i == 5)
		mlx_put_image_to_window(data->mlx->mlx, data->mlx->win, data->img->er_4, enemi->x * SIZE, enemi->y * SIZE);
	if (i == 1 || i == 3)
		mlx_put_image_to_window(data->mlx->mlx, data->mlx->win, data->img->er_3, enemi->x * SIZE, enemi->y * SIZE);
	if (i == 2)
		mlx_put_image_to_window(data->mlx->mlx, data->mlx->win, data->img->er_2, enemi->x * SIZE, enemi->y * SIZE);
	if (i == 6)
		mlx_put_image_to_window(data->mlx->mlx, data->mlx->win, data->img->er_1, enemi->x * SIZE, enemi->y * SIZE);
}

void	ft_move_enem(t_data *data, t_enem *enemi)
{
	if (enemi->dir == 'r' && (MAP[enemi->y][enemi->x + 1] != '0' && MAP[enemi->y][enemi->x + 1] != 'P'))
		enemi->dir = 'l';
	else if (enemi->dir == 'l' && (MAP[enemi->y][enemi->x - 1] != '0' && MAP[enemi->y][enemi->x - 1] != 'P'))
		enemi->dir = 'r';
	if (enemi->dir == 'r' && (MAP[enemi->y][enemi->x + 1] == '0' || MAP[enemi->y][enemi->x + 1] == 'P'))
	{
		MAP[enemi->y][enemi->x] = '0';
		mlx_put_image_to_window(data->mlx->mlx, data->mlx->win, data->img->c, enemi->x * SIZE, enemi->y * SIZE);
		enemi->x++;
	}
	if (enemi->dir == 'l' && (MAP[enemi->y][enemi->x - 1] == '0' || MAP[enemi->y][enemi->x - 1] == 'P'))
	{
		MAP[enemi->y][enemi->x] = '0';
		mlx_put_image_to_window(data->mlx->mlx, data->mlx->win, data->img->c, enemi->x * SIZE, enemi->y * SIZE);
		enemi->x--;
	}
}

void	ft_animate_enemies(t_data *data)
{
	static int	i = 0;
	static int	j = 0;
	t_enem	*enemi;

	enemi = *data->enem_lst;
	while (enemi)
	{
		if (enemi->dir == 'r')
			ft_anim_r(data, enemi, i);
		else
			ft_anim_l(data, enemi, i);
		i++;
		j++;
		if (i == 7)
			i = 0;
		if (j == 14)
		{
			ft_move_enem(data, enemi);
			j = 0;
		}
		enemi = enemi->next;
	}
	usleep(80000);
}

int	ft_animate(t_data *data)
{
	ft_animate_player(data);
	ft_animate_enemies(data);
	return (0);
}

// void	ft_game(t_data *data)
// {
// 	// data->mlx->mlx = mlx_init();
// 	// data->mlx->win = mlx_new_window(data->mlx->mlx, ft_strlen(MAP[0]) * SIZE, ft_strlen2d(MAP) * SIZE, "So Long");
// 	ft_animate_player(data);
// 	// ft_print_map(data);
// 	// mlx_do_key_autorepeatoff(data->mlx->mlx);
// 	mlx_key_hook(data->mlx->win, key_hook, data);
// 	mlx_hook(data->mlx->win, 17, 0, ft_exit, data);
// 	mlx_loop(data->mlx->mlx);
// 	// mlx_loop_hook(data->mlx, ft_animate_player, data);
// }
