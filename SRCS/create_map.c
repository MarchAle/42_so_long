/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchal <amarchal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 11:33:15 by amarchal          #+#    #+#             */
/*   Updated: 2022/01/28 11:39:38 by amarchal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_check_file(char *file)
{
	int	i;

	i = 0;
	while (file[i])
		i++;
	if (file[--i] != 'r')
	{
		printf("Error : Wrong file extension\n");
		exit(EXIT_FAILURE);
	}
	if (file[--i] != 'e')
	{
		printf("Error : Wrong file extension\n");
		exit(EXIT_FAILURE);
	}
	if (file[--i] != 'b')
	{
		printf("Error : Wrong file extension\n");
		exit(EXIT_FAILURE);
	}
	if (file[--i] != '.')
	{
		printf("Error : Wrong file extension\n");
		exit(EXIT_FAILURE);
	}
}

char	**ft_create_map(char *file)
{
	int		fd;
	char	*str;
	char	*map;
	char	**map2d;

	ft_check_file(file);
	map = malloc(sizeof(char) * 1);
	map[0] = '\0';
	fd = open(file, O_RDONLY);
	str = get_next_line(fd);
	while (str)
	{
		map = ft_strjoin_gnl(map, str);
		free(str);
		str = get_next_line(fd);
		if (str && str[0] == '\n')
		{
			printf("Error : map error\n");
			exit(EXIT_FAILURE);
		}
	}
	map2d = ft_split(map, '\n');
	free(map);
	return (map2d);
}
