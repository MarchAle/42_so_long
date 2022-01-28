/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchal <amarchal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 17:32:14 by amarchal          #+#    #+#             */
/*   Updated: 2022/01/28 17:18:13 by amarchal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_init_data(t_data *data)
{
	t_mlx		*mlx;
	t_player	*player;
	
	mlx = malloc(sizeof(t_mlx));
	player = malloc(sizeof(t_player));
	data->mlx = mlx;
	data->player = player;
}

int	main(int ac, char **av)
{
	t_data	*data;

	if (ac != 2)
		return(0);
	data = malloc(sizeof(t_data));
	if (!data)
		return (0);
	ft_init_data(data);
	data->map2d = ft_create_map(av[1]);
	ft_check_map(data->map2d);
	ft_map_info(data);
	
	data->mlx->mlx = mlx_init();
	data->mlx->win = mlx_new_window(data->mlx->mlx, ft_strlen(MAP[0]) * SIZE, ft_strlen2d(MAP) * SIZE, "So Long");
	ft_print_map(data);
	
	mlx_do_key_autorepeaton(data->mlx);

	ft_game(data);
	// mlx_loop(data->mlx->mlx);
	ft_split_clear(data->map2d);
	return(0);
}