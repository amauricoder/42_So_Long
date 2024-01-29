/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 09:00:53 by aconceic          #+#    #+#             */
/*   Updated: 2024/01/29 17:43:47 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

char	**map_read(char *file_path)
{
	int		fd;
	char	**map;
	char	*line;
	int		i;

	fd = open(file_path, O_RDONLY);
	map = ft_calloc(sizeof(char *), map_lines_counter(file_path) + 1);
	if (!map)
		return (NULL);
	i = 0;
	line = NULL;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		map[i] = ft_strdup(line);
		free(line);
		i++;
	}
	close(fd);
	return (map);
}

int	map_lines_counter(char *file_path)
{
	int		i;
	int		fd;
	char	*line;

	//ft_printf("entrou na funcao maps lines counter\n");
	fd = open(file_path, O_RDONLY);
	if (fd < 0)
	{
		error_message(1);
		return (0);
	}
	i = 0;
	line = NULL;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		free(line);
		i ++;
	}
	free(line);
	close(fd);
	return (i);
}
