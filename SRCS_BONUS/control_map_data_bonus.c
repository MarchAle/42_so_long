/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_map_data_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchal <amarchal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 14:23:33 by amarchal          #+#    #+#             */
/*   Updated: 2022/02/03 10:55:12 by amarchal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_control_map_data(t_parse_info *data)
{
	if (data->outline == FALSE)
	{
		printf("Error\nIncorrect outline\n");
		exit(EXIT_FAILURE);
	}
	if (data->collectible == 0)
	{
		printf("Error\nNo collectible on map\n");
		exit(EXIT_FAILURE);
	}
	if (data->exit == 0)
	{
		printf("Error\nNo exit\n");
		exit(EXIT_FAILURE);
	}
	if (data->player != 1)
	{
		printf("Error\nMust have only 1 player\n");
		exit(EXIT_FAILURE);
	}
	if (data->error == TRUE)
	{
		printf("Error\nMap error\n");
		exit(EXIT_FAILURE);
	}
}
