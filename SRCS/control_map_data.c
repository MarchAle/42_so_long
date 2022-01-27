/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_map_data.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchal <amarchal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 14:23:33 by amarchal          #+#    #+#             */
/*   Updated: 2022/01/27 14:25:05 by amarchal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_control_map_data(t_parse_info *data)
{
	if (data->error == TRUE)
	{
		printf("Error : map error\n");
		exit(EXIT_FAILURE);
	}
	if (data->outline == FALSE)
	{
		printf("Error : incorrect outline\n");
		exit(EXIT_FAILURE);
	}
	if (data->collectible == 0)
	{
		printf("Error : no collectible\n");
		exit(EXIT_FAILURE);
	}
	if (data->exit == 0)
	{
		printf("Error : no exit\n");
		exit(EXIT_FAILURE);
	}
	if (data->player != 1)
	{
		printf("Error : must have 1 player\n");
		exit(EXIT_FAILURE);
	}
}
