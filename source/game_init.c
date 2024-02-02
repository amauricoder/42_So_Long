/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 15:27:56 by aconceic          #+#    #+#             */
/*   Updated: 2024/01/31 17:36:15 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

t_mlx_data	*game_init(t_mlx_data *render, t_map *map)
{
	int height;
	int width;

	height = map->qt_lines * 32;
	width = map->qt_chars_lines * 32;
	
	render = ft_calloc(sizeof(t_mlx_data), 1);
	if (!render)
		return (NULL);
	render->connect = mlx_init();
	render->window = mlx_new_window(render->connect, height, width, "So Long");

	return (render);
}
