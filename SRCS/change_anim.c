/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_anim.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchal <amarchal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 17:12:52 by amarchal          #+#    #+#             */
/*   Updated: 2022/01/31 17:29:46 by amarchal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_change_anim_front(t_data *data)
{
	data->p_anim->p_1 = mlx_xpm_file_to_image(data->mlx->mlx, "./img/f1.xpm", \
	data->mlx->width, data->mlx->height);
	data->p_anim->p_2 = mlx_xpm_file_to_image(data->mlx->mlx, "./img/f2.xpm", data->mlx->width, data->mlx->height);
	data->p_anim->p_3 = mlx_xpm_file_to_image(data->mlx->mlx, "./img/f3.xpm", data->mlx->width, data->mlx->height);
	data->p_anim->p_4 = mlx_xpm_file_to_image(data->mlx->mlx, "./img/f4.xpm", data->mlx->width, data->mlx->height);
}

void	ft_change_anim_back(t_data *data)
{
	data->p_anim->p_1 = mlx_xpm_file_to_image(data->mlx->mlx, "./img/d1.xpm", data->mlx->width, data->mlx->height);
	data->p_anim->p_2 = mlx_xpm_file_to_image(data->mlx->mlx, "./img/d2.xpm", data->mlx->width, data->mlx->height);
	data->p_anim->p_3 = mlx_xpm_file_to_image(data->mlx->mlx, "./img/d3.xpm", data->mlx->width, data->mlx->height);
	data->p_anim->p_4 = mlx_xpm_file_to_image(data->mlx->mlx, "./img/d4.xpm", data->mlx->width, data->mlx->height);
}

void	ft_change_anim_left(t_data *data)
{
	data->p_anim->p_1 = mlx_xpm_file_to_image(data->mlx->mlx, "./img/l1.xpm", data->mlx->width, data->mlx->height);
	data->p_anim->p_2 = mlx_xpm_file_to_image(data->mlx->mlx, "./img/l2.xpm", data->mlx->width, data->mlx->height);
	data->p_anim->p_3 = mlx_xpm_file_to_image(data->mlx->mlx, "./img/l3.xpm", data->mlx->width, data->mlx->height);
	data->p_anim->p_4 = mlx_xpm_file_to_image(data->mlx->mlx, "./img/l4.xpm", data->mlx->width, data->mlx->height);
}

void	ft_change_anim_right(t_data *data)
{
	data->p_anim->p_1 = mlx_xpm_file_to_image(data->mlx->mlx, "./img/r1.xpm", data->mlx->width, data->mlx->height);
	data->p_anim->p_2 = mlx_xpm_file_to_image(data->mlx->mlx, "./img/r2.xpm", data->mlx->width, data->mlx->height);
	data->p_anim->p_3 = mlx_xpm_file_to_image(data->mlx->mlx, "./img/r3.xpm", data->mlx->width, data->mlx->height);
	data->p_anim->p_4 = mlx_xpm_file_to_image(data->mlx->mlx, "./img/r4.xpm", data->mlx->width, data->mlx->height);
}

void	ft_change_anim(t_data *data, char *dir)
{
	if (!ft_strncmp(dir, "up", 2))
		ft_change_anim_back(data);
	if (!ft_strncmp(dir, "down", 4))
		ft_change_anim_front(data);
	if (!ft_strncmp(dir, "left", 4))
		ft_change_anim_left(data);
	if (!ft_strncmp(dir, "right", 5))
		ft_change_anim_right(data);
}