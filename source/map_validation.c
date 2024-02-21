/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: murilo <murilo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 09:00:53 by aconceic          #+#    #+#             */
/*   Updated: 2024/02/21 21:24:51 by murilo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
//Valid all the requisites for a valid map
//return 1 for a valid map and error_message(), 0 for invalid
int	map_valid_allrequisites(t_map *map)
{
	if (map_valid_characters(map) && map_valid_isclosed(map)
		&& map_valid_mustchar(map) && map_valid_minsize(map)
		&& map_isvalid_path(map))
	{
		return (1);
	}
	else
		return (error_message(2), 0);
}

//Check to see if there is some invalid char in the map
//return 1 if there is only valid chars and 0 if not
int	map_valid_characters(t_map *map)
{
	char	**line;
	int		i;
	int		j;

	line = map->map_skeleton;
	i = 0;
	while (line[i] != NULL)
	{
		j = 0;
		while (line[i][j] != '\0')
		{
			if (line[i][j] != 'C' && line[i][j] != 'P' && line[i][j] != 'E'
				&& line[i][j] != '1' && line[i][j] != '0' && line[i][j] != '\n')
				return (error_message(5), 0);
			j ++;
		}
		i ++;
	}
	return (1);
}

//Verify if the map is sorrounded by 11111
//return 1 for valid and 0 and error for invalid map
int	map_valid_isclosed(t_map *map)
{
	char	**lines;
	char	*last;
	int		i;

	lines = map->map_skeleton;
	last = lines[map->qt_lines - 1];
	i = -1;
	while (++i <= map->qt_chars_lines)
	{
		if ((lines[0][i] != '1' && lines[0][i] != '\n') 
			|| (last[i] != '1' && last[i] != '\n' && last[i] != '\0'))
			return (error_message(6), 0);
	}
	i = 0;
	while (lines[++i] != NULL)
	{
		if (lines[i][0] != '1' || lines[i][map->qt_chars_lines - 1] != '1') 
			return (error_message(6), 0);
	}
	return (1);
}

//Validate if there is at least 1C, ONLY 1E and ONLY 1P.
//Returns error_messa(), 0 for not valid and 1 for valid.
int	map_valid_mustchar(t_map *map)
{
	char	**lines;
	int		i;
	int		j;

	lines = map->map_skeleton;
	i = -1;
	while (lines[++i] != NULL)
	{
		j = 0;
		while (lines[i][j] != '\0')
		{
			if (lines[i][j] == 'P')
				map->qt_player ++;
			if (lines[i][j] == 'C')
				map->qt_collect ++;
			if (lines[i][j] == 'E')
				map->qt_exit ++;
			j ++;
		}
	}
	if (map->qt_collect < 1)
		return (error_message(7), 0);
	if (map->qt_player != 1 || map->qt_exit != 1)
		return (error_message(8), 0);
	return (1);
}

//Validate the minimun size of the map.
//The minimun size acceptable is if the sum of the sizes if smaller than 8.
//Return error_message(), 0 for invalid map, and 1 for valid map.
int	map_valid_minsize(t_map *map)
{
	if (map->qt_lines + map->qt_chars_lines < 8)
		return (error_message(9), 0);
	return (1);
}

int	map_isvalid_path(t_map *map)
{
	int i;
	int j;
	char **lines;
	
	i = -1;
	lines = map->map_skeleton;
	while (lines[++i] != NULL)
	{
		j = 0;
		while (lines[i][j] != '\0')
		{
			if (lines[i][j] == 'P')
			{
				return (ft_printf("flood result %i\n", flood_fill(map, i, j)));
			}
			j ++;
		}
	}
	return (1);
}

//row = x, collmun = y
int flood_fill(t_map *map, int y, int x) 
{
	char **ms = map->map_skeleton;

	if (ms[y][x] == '1' || ms[y][x] == 'X')
		return 0;
	if (ms[y][x] == 'E')
		return 1;
	if (ms[y][x] == 'C' || ms[y][x] == '0')
		ms[y][x] = 'X';
	if (flood_fill(map, y + 1, x) || flood_fill(map, y, x + 1) ||
				 flood_fill(map, y - 1, x) || flood_fill(map, y, x - 1))
		return 1;
	return 0; // No path found
}
