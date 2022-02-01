/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchal <amarchal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 17:41:47 by amarchal          #+#    #+#             */
/*   Updated: 2022/02/01 17:09:50 by amarchal         ###   ########.fr       */
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
	PLAYER->step = 0;
	PLAYER->to_collect = 0;
	PLAYER->collected = 0;
	PLAYER->enemies = 0;
	*data->enem_lst = NULL;
	while (MAP[++i])
	{
		j = -1;
		while (MAP[i][++j])
			ft_check_char(data, MAP[i][j], i, j);
	}
	// i = -1;
	// PLAYER->e_pos = ft_calloc(PLAYER->enemies, 2);
	// while (MAP[++i])
	// {
	// 	j = -1;
	// 	while (MAP[i][++j])
	// 	{
	// 		if (MAP[i][j] == 'X')
	// 			ft_add_enemi(data, i, j);
	// 	}
	// }
	// printf("Ennemis : %d\n", data->player->enemies);
}
