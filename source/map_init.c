/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: murilo <murilo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 09:12:30 by aconceic          #+#    #+#             */
/*   Updated: 2024/02/08 10:55:26 by murilo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

//Read the map file.
//Returns a double pointer with the map content stored on it.
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
//Count how many lines
//exist on the map file.
//returns an integer with the nbr of lines.
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
		return (-1);
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
//Counts the number of chars in the strings
//uses ft_countchar() instead of ft_strlen() because
//we need to take \n in consideration.
//returns an INT with the first_line_size.
//if there is some line that the size is not equal to the first, return error -1.
int     map_char_counter(char *file_path)
{
	char	**map;
	int		i;
	int	first_line_size;
	
	map = map_read(file_path);
	first_line_size = ft_countchar(map[0]);
	i = 1;
	while (map[i] != NULL)
	{
		if (ft_countchar(map[i]) != first_line_size)
		{	
			error_message(4);
			ft_printf("Line %i invalid\n", i + 1);
			free_dp_char(map);
			return (-1);
		}
		i ++;
	}
	free_dp_char(map);
	return (first_line_size);
}
//init the map structure with values
//that we took from other functions
//returns the map structure filled with values.
t_game	*map_init(char *file_path)
{
	t_game 		*game;
	t_map		*map;
	t_mlx_data *data_mlx;

	game = malloc(sizeof(t_game) * 1);
	map = malloc(sizeof(t_map) * 1);
	data_mlx = malloc(sizeof(t_mlx_data) * 1);
	if(!game || !map || !data_mlx)
	{
		error_message(3);
		return (NULL);
	}
	game->map = map;
	game->map->map_skeleton = map_read(file_path);
	game->map->qt_lines = map_lines_counter(file_path);
	game->map->qt_chars_lines = map_char_counter(file_path);
	game->map->qt_player = 0;
	game->map->qt_collect = 0;
	game->map->qt_exit = 0;
	game->data_mlx = data_mlx;
	
	return (game);
}