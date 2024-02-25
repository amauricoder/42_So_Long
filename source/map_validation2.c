/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: murilo <murilo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 11:23:44 by murilo            #+#    #+#             */
/*   Updated: 2024/02/25 11:40:51 by murilo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

//Verify if there is a valid path from the
//P to the exit through flood_fill(), that will
//return 1 for valid and 0 for invalid
int	map_valid_havepath(t_map *map, char **map_copy)
{
	int		i;
	int		j;
	int		valid;
	char	**lines;

	i = -1;
	lines = map->map_skeleton;
	valid = 0;
	while (lines[++i] != NULL)
	{
		j = 0;
		while (lines[i][j] != '\0')
		{
			if (lines[i][j] == 'P')
				valid = flood_fill(map_copy, i, j);
			j ++;
		}
	}
	return (valid);
}

//row = x, collmun = y
int	flood_fill(char **map, int y, int x)
{
	if (map[y][x] == '1' || map[y][x] == 'X')
		return (0);
	if (map[y][x] == 'E')
		return (1);
	if (map[y][x] == 'C' || map[y][x] == '0')
		map[y][x] = 'X';
	if (flood_fill(map, y + 1, x) || flood_fill(map, y, x + 1)
		|| flood_fill(map, y - 1, x) || flood_fill(map, y, x - 1))
		return (1);
	return (0);
}
