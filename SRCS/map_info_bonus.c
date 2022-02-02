/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_info_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchal <amarchal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 17:41:47 by amarchal          #+#    #+#             */
/*   Updated: 2022/02/02 13:18:02 by amarchal         ###   ########.fr       */
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
		data->player->enemies++;
}

void	ft_add_enemi(t_data *data, int i, int j)
{
	static int	k = 0;

	data->player->e_pos[k][0] = i;
	data->player->e_pos[k][1] = j;
	k++;
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
	while (MAP[++i])
	{
		j = -1;
		while (MAP[i][++j])
			ft_check_char(data, MAP[i][j], i, j);
	}
	i = -1;
	data->player->e_pos = ft_calloc(data->player->enemies, 2);
	while (MAP[++i])
	{
		j = -1;
		while (MAP[i][++j])
		{
			if (MAP[i][j] == 'X')
				ft_add_enemi(data, i, j);
		}
	}
}
