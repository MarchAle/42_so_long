/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchal <amarchal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 17:32:14 by amarchal          #+#    #+#             */
/*   Updated: 2022/02/03 14:07:49 by amarchal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_init_data(t_data *data)
{
	t_mlx		*mlx;
	t_player	*player;
	t_img		*img;
	t_anim		*p_anim;
	t_enem		**enem_lst;

	mlx = malloc(sizeof(t_mlx));
	player = malloc(sizeof(t_player));
	img = malloc(sizeof(t_img));
	p_anim = malloc(sizeof(t_anim));
	enem_lst = malloc(sizeof(t_enem));
	if (!mlx || !player || !img || !p_anim || !enem_lst)
		exit(EXIT_FAILURE);
	data->mlx = mlx;
	data->player = player;
	data->img = img;
	data->p_anim = p_anim;
	data->enem_lst = enem_lst;
}

int	main(int ac, char **av)
{
	t_data	*data;

	if (ac != 2)
		return (0);
	data = malloc(sizeof(t_data));
	if (!data)
		return (0);
	ft_init_data(data);
	data->map2d = ft_create_map(av[1]);
	ft_check_map(data->map2d);
	ft_map_info(data);
	data->mlx->mlx = mlx_init();
	data->mlx->win = mlx_new_window(data->mlx->mlx, \
	ft_strlen(data->map2d[0]) * SIZE, \
	ft_strlen2d(data->map2d) * SIZE, "So Long");
	ft_print_map(data);
	mlx_loop_hook(data->mlx->mlx, ft_animate, data);
	mlx_hook(data->mlx->win, 2, 0, key_hook, data);
	mlx_hook(data->mlx->win, 17, 0, ft_exit, data);
	mlx_loop(data->mlx->mlx);
	ft_split_clear(data->map2d);
	return (0);
}
