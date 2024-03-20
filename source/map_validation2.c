/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 11:23:44 by aconceic          #+#    #+#             */
/*   Updated: 2024/03/20 14:31:27 by aconceic         ###   ########.fr       */
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
	char	**map_dup;

	i = -1;
	valid = 0;
	map_dup = matrix_dup(map, map_copy);
	while (map_copy[++i] != NULL)
	{
		j = -1;
		while (map_copy[i][++j] != '\0')
		{
			if (map_copy[i][j] == 'P')
				valid = flood_fill(map_copy, i, j);
			if (map->map_skeleton[i][j] == 'C')
			{
				if (flood_fill_c(map_dup, i, j) == 0)
					return (free_dp_char(map_dup), 0);
				free_dp_char(map_dup);
				map_dup = matrix_dup(map, map->map_skeleton);
			}
		}
	}
	return (free_dp_char(map_dup), valid);
}

//row = x, collmun = y
int	flood_fill(char **map, int y, int x)
{
	if (map[y][x] == '1' || map[y][x] == 'X')
		return (0);
	if (map[y][x] == 'E')
		return (1);
	if (map[y][x] == '0' || map[y][x] == 'C')
		map[y][x] = 'X';
	if (flood_fill(map, y + 1, x) || flood_fill(map, y, x + 1)
		|| flood_fill(map, y - 1, x) || flood_fill(map, y, x - 1))
		return (1);
	return (0);
}

int	map_valid_havemaxsize(t_map *map)
{
	if (map->qt_chars_lines > 60
		|| map->qt_lines > 30)
		return (error_message(9), 0);
	return (1);
}

char	**matrix_dup(t_map *map, char **map_todup)
{
	int		i;
	char	**duplicated;

	duplicated = ft_calloc(sizeof(char *), map->qt_lines + 1);
	if (!duplicated)
		return (NULL);
	i = 0;
	while (map_todup[i])
	{
		duplicated[i] = ft_strdup(map_todup[i]);
		i ++;
	}
	duplicated[i] = NULL;
	return (duplicated);
}

int	flood_fill_c(char **map, int y, int x)
{
	if (map[y][x] == '1' || map[y][x] == 'X' || map[y][x] == 'E')
		return (0);
	if (map[y][x] == 'P')
		return (1);
	if (map[y][x] == '0' || map[y][x] == 'C' || map[y][x] == 'E')
		map[y][x] = 'X';
	if (flood_fill(map, y + 1, x) || flood_fill(map, y, x + 1)
		|| flood_fill(map, y - 1, x) || flood_fill(map, y, x - 1))
		return (1);
	return (0);
}
