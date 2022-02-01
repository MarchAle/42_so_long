/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_anim_enem.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchal <amarchal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 17:12:52 by amarchal          #+#    #+#             */
/*   Updated: 2022/02/01 13:48:25 by amarchal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_change_anim_enem_left(t_data *data)
{
	data->p_anim->p_1 = mlx_xpm_file_to_image(data->mlx->mlx, "./img/gl1.xpm", \
	data->mlx->width, data->mlx->height);
	data->p_anim->p_2 = mlx_xpm_file_to_image(data->mlx->mlx, "./img/gl2.xpm", \
	data->mlx->width, data->mlx->height);
	data->p_anim->p_3 = mlx_xpm_file_to_image(data->mlx->mlx, "./img/gl3.xpm", \
	data->mlx->width, data->mlx->height);
	data->p_anim->p_4 = mlx_xpm_file_to_image(data->mlx->mlx, "./img/gl4.xpm", \
	data->mlx->width, data->mlx->height);
}

void	ft_change_anim_enem_right(t_data *data)
{
	data->p_anim->p_1 = mlx_xpm_file_to_image(data->mlx->mlx, "./img/gr1.xpm", \
	data->mlx->width, data->mlx->height);
	data->p_anim->p_2 = mlx_xpm_file_to_image(data->mlx->mlx, "./img/gr2.xpm", \
	data->mlx->width, data->mlx->height);
	data->p_anim->p_3 = mlx_xpm_file_to_image(data->mlx->mlx, "./img/gr3.xpm", \
	data->mlx->width, data->mlx->height);
	data->p_anim->p_4 = mlx_xpm_file_to_image(data->mlx->mlx, "./img/gr4.xpm", \
	data->mlx->width, data->mlx->height);
}

void	ft_change_anim(t_data *data, char *dir)
{
	if (!ft_strncmp(dir, "left", 4))
		ft_change_anim_enem_left(data);
	if (!ft_strncmp(dir, "right", 5))
		ft_change_anim_enem_right(data);
}
