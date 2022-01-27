/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchal <amarchal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 16:04:13 by amarchal          #+#    #+#             */
/*   Updated: 2022/01/27 17:30:01 by amarchal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_print_sprite(t_mlx *mlx, char c, int x, int y)
{
	if (c == '1')
		mlx->img = mlx_xpm_file_to_image(mlx->mlx, "./img/test.xpm", mlx->width, mlx->height);
	if (c == '0')
		mlx->img = mlx_xpm_file_to_image(mlx->mlx, "./img/black.xpm", mlx->width, mlx->height);
	if (c == 'P')
		mlx->img = mlx_xpm_file_to_image(mlx->mlx, "./img/vert.xpm", mlx->width, mlx->height);
	if (c == 'C')
		mlx->img = mlx_xpm_file_to_image(mlx->mlx, "./img/jaune.xpm", mlx->width, mlx->height);
	if (c == 'E')
		mlx->img = mlx_xpm_file_to_image(mlx->mlx, "./img/bleu.xpm", mlx->width, mlx->height);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, x * SIZE, y * SIZE);
}

void	ft_print_map(char **map)
{
	t_mlx	*mlx;
	int		i;
	int		j;

	mlx = malloc(sizeof(t_mlx));
	mlx->mlx = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx, ft_strlen(map[0]) * SIZE, ft_strlen2d(map) * SIZE, "So Long");
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			ft_print_sprite(mlx, map[i][j], j, i);
			j++;
		}
		i++;
	}
	mlx_loop(mlx->mlx);
}