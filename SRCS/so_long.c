/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchal <amarchal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 17:32:14 by amarchal          #+#    #+#             */
/*   Updated: 2022/01/27 17:46:32 by amarchal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	main(int ac, char **av)
{
	t_data	*data;
	char	**map2d;

	data = malloc(sizeof(t_data));
	if (ac != 2)
		return(0);
	map2d = ft_create_map(av[1]);
	ft_print_map(map2d);
	ft_map_info(map2d);
	ft_split_clear(map2d);
	return(0);
}