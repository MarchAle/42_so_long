/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchal <amarchal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 11:59:03 by amarchal          #+#    #+#             */
/*   Updated: 2022/02/02 12:09:34 by amarchal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_init_wall_img(t_data *data)
{
	data->img->tl = mlx_xpm_file_to_image(data->mlx->mlx, \
	"./img/tl.xpm", data->mlx->width, data->mlx->height);
	data->img->t = mlx_xpm_file_to_image(data->mlx->mlx, \
	"./img/t.xpm", data->mlx->width, data->mlx->height);
	data->img->tr = mlx_xpm_file_to_image(data->mlx->mlx, \
	"./img/tr.xpm", data->mlx->width, data->mlx->height);
	data->img->l = mlx_xpm_file_to_image(data->mlx->mlx, \
	"./img/l.xpm", data->mlx->width, data->mlx->height);
	data->img->c = mlx_xpm_file_to_image(data->mlx->mlx, \
	"./img/c.xpm", data->mlx->width, data->mlx->height);
	data->img->r = mlx_xpm_file_to_image(data->mlx->mlx, \
	"./img/r.xpm", data->mlx->width, data->mlx->height);
	data->img->bl = mlx_xpm_file_to_image(data->mlx->mlx, \
	"./img/bl.xpm", data->mlx->width, data->mlx->height);
	data->img->b = mlx_xpm_file_to_image(data->mlx->mlx, \
	"./img/b.xpm", data->mlx->width, data->mlx->height);
	data->img->br = mlx_xpm_file_to_image(data->mlx->mlx, \
	"./img/br.xpm", data->mlx->width, data->mlx->height);
	data->img->rocks = mlx_xpm_file_to_image(data->mlx->mlx, \
	"./img/rocks.xpm", data->mlx->width, data->mlx->height);
	data->img->gem = mlx_xpm_file_to_image(data->mlx->mlx, \
	"./img/gem.xpm", data->mlx->width, data->mlx->height);
}

void	ft_init_exit_img(t_data *data)
{
	data->img->e_open = mlx_xpm_file_to_image(data->mlx->mlx, \
	"./img/e_open.xpm", data->mlx->width, data->mlx->height);
	data->img->e1 = mlx_xpm_file_to_image(data->mlx->mlx, \
	"./img/e1.xpm", data->mlx->width, data->mlx->height);
	data->img->e2 = mlx_xpm_file_to_image(data->mlx->mlx, \
	"./img/e2.xpm", data->mlx->width, data->mlx->height);
	data->img->e3 = mlx_xpm_file_to_image(data->mlx->mlx, \
	"./img/e3.xpm", data->mlx->width, data->mlx->height);
	data->img->e4 = mlx_xpm_file_to_image(data->mlx->mlx, \
	"./img/e4.xpm", data->mlx->width, data->mlx->height);
	data->img->e5 = mlx_xpm_file_to_image(data->mlx->mlx, \
	"./img/e5.xpm", data->mlx->width, data->mlx->height);
	data->img->e6 = mlx_xpm_file_to_image(data->mlx->mlx, \
	"./img/e6.xpm", data->mlx->width, data->mlx->height);
	data->img->e7 = mlx_xpm_file_to_image(data->mlx->mlx, \
	"./img/e7.xpm", data->mlx->width, data->mlx->height);
}

void	ft_init_enemi_img(t_data *data)
{
	data->img->el_1 = mlx_xpm_file_to_image(data->mlx->mlx, \
	"./img/gl1.xpm", data->mlx->width, data->mlx->height);
	data->img->el_2 = mlx_xpm_file_to_image(data->mlx->mlx, \
	"./img/gl2.xpm", data->mlx->width, data->mlx->height);
	data->img->el_3 = mlx_xpm_file_to_image(data->mlx->mlx, \
	"./img/gl3.xpm", data->mlx->width, data->mlx->height);
	data->img->el_4 = mlx_xpm_file_to_image(data->mlx->mlx, \
	"./img/gl4.xpm", data->mlx->width, data->mlx->height);
	data->img->er_1 = mlx_xpm_file_to_image(data->mlx->mlx, \
	"./img/gr1.xpm", data->mlx->width, data->mlx->height);
	data->img->er_2 = mlx_xpm_file_to_image(data->mlx->mlx, \
	"./img/gr2.xpm", data->mlx->width, data->mlx->height);
	data->img->er_3 = mlx_xpm_file_to_image(data->mlx->mlx, \
	"./img/gr3.xpm", data->mlx->width, data->mlx->height);
	data->img->er_4 = mlx_xpm_file_to_image(data->mlx->mlx, \
	"./img/gr4.xpm", data->mlx->width, data->mlx->height);
}

void	ft_init_img(t_data *data)
{
	ft_init_wall_img(data);
	ft_init_exit_img(data);
	ft_init_enemi_img(data);
	ft_change_anim_front(data);
	data->img->floor = mlx_xpm_file_to_image(data->mlx->mlx, \
	"./img/c.xpm", data->mlx->width, data->mlx->height);
	data->img->collectible = mlx_xpm_file_to_image(data->mlx->mlx, \
	"./img/gem.xpm", data->mlx->width, data->mlx->height);
}
