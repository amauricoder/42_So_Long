/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: murilo <murilo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 15:27:56 by aconceic          #+#    #+#             */
/*   Updated: 2024/02/07 13:43:56 by murilo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	game_init(t_game *game)
{

	int height;
	int width;

	height = game->map->qt_lines * 32;
	width = game->map->qt_chars_lines * 32;

	game->mlx_data->connect = mlx_init();
	game->mlx_data->window = mlx_new_window(game->mlx_data->connect, height, width, "So Long");
}
