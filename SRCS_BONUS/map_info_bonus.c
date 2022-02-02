/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchal <amarchal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 17:41:47 by amarchal          #+#    #+#             */
/*   Updated: 2022/02/02 13:22:35 by amarchal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_check_char(t_data *data, char c, int i, int j)
{
	if (c == 'P')
	{
		data->player->x = j;
		data->player->y = i;
	}
	if (c == 'C')
		data->player->to_collect++;
	if (c == 'E')
	{
		data->player->exit_x = j;
		data->player->exit_y = i;
	}
	if (c == 'X')
		ft_add_enemi(data, i, j);
}

void	ft_add_enemi(t_data *data, int i, int j)
{
	t_enem	*new_enem;

	new_enem = malloc(sizeof(t_enem));
	new_enem->x = j;
	new_enem->y = i;
	new_enem->dir = 'l';
	new_enem->next = *data->enem_lst;
	*data->enem_lst = new_enem;
}

void	ft_map_info(t_data *data)
{
	int	i;
	int	j;

	i = -1;
	data->player->step = 0;
	data->player->to_collect = 0;
	data->player->collected = 0;
	data->player->enemies = 0;
	*data->enem_lst = NULL;
	while (data->map2d[++i])
	{
		j = -1;
		while (data->map2d[i][++j])
			ft_check_char(data, data->map2d[i][j], i, j);
	}
}
