/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchal <amarchal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 17:41:47 by amarchal          #+#    #+#             */
/*   Updated: 2022/01/31 18:37:37 by amarchal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_check_char(t_data *data, char c, int i, int j)
{
	if (c == 'P')
	{
		PLAYER->x = j;
		PLAYER->y = i;
	}
	if (c == 'C')
		PLAYER->to_collect++;
	if (c == 'E')
	{
		PLAYER->exit_x = j;
		PLAYER->exit_y = i;
	}
	if (c == 'X')
		PLAYER->enemies++;
}

void	ft_add_enemi(t_data *data, int i, int j)
{
	static int	k = 0;
	
	PLAYER->e_pos[k][0] = i;
	PLAYER->e_pos[k][1] = j;
	k++;
}

void	ft_map_info(t_data *data)
{
	int	i;
	int	j;

	i = -1;
	PLAYER->step = 0;
	PLAYER->to_collect = 0;
	PLAYER->collected = 0;
	PLAYER->enemies = 0;
	while (MAP[++i])
	{
		j = -1;
		while (MAP[i][++j])
			ft_check_char(data, MAP[i][j], i, j);
	}
	i = -1;
	PLAYER->e_pos = ft_calloc(PLAYER->enemies, 2);
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
