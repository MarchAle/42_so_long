/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchal <amarchal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 17:41:47 by amarchal          #+#    #+#             */
/*   Updated: 2022/01/28 17:07:18 by amarchal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_map_info(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	PLAYER->step = 0;
	PLAYER->to_collect = 0;
	PLAYER->collected = 0;
	while (MAP[i])
	{
		j = 0;
		while (MAP[i][j])
		{
			if (MAP[i][j] == 'P')
			{
				PLAYER->x = j;
				PLAYER->y = i;
			}
			if (MAP[i][j] == 'C')
				PLAYER->to_collect++;
			j++;
		}
		i++;
	}
}
