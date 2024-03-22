/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 10:59:06 by aconceic          #+#    #+#             */
/*   Updated: 2024/03/21 11:09:57 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

//Valid all the requisites for a valid map
//return 1 for a valid map and error_message(), 0 for invalid
int	map_valid_allrequisites_bn(t_map *map, char *file_path)
{
	char	**map_copy;

	map_copy = map_read(file_path);
	if (map_valid_havecharacters(map) && map_valid_isclosed(map)
		&& map_valid_havemustchar(map) && map_valid_haveminsize(map)
		&& map_valid_havepath(map, map_copy) && map_valid_havemaxsize(map)
		&& map->qt_lines > 3)
	{
		free_dp_char(map_copy);
		return (1);
	}
	else
	{
		free_dp_char(map_copy);
		return (error_message(2), 0);
	}
}
