/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_draw2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: murilo <murilo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 13:04:35 by murilo            #+#    #+#             */
/*   Updated: 2024/02/18 18:18:42 by murilo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

//Draw the left walls of the map.
void	draw_mapwall_left(t_game *game)
{
	int i;
	int render_height;
	char	**map_skeleton;

	map_skeleton = game->map->map_skeleton;
	i = 0;
	render_height = 32;
	while(map_skeleton[i])
	{
		if (i == game->map->qt_lines - 2)
			break;
		if (map_skeleton[i][0] == '1')
			render_elmt(game, game->map->img_wallml, 0, render_height);
		render_height = render_height + 32;
		i ++;
	}
}

//Draw the right walls of the map
void	draw_mapwall_right(t_game *game)
{
	int i;
	int render_height;
	int line_width;
	char	**map_skeleton;

	map_skeleton = game->map->map_skeleton;
	line_width = game->map->qt_chars_lines - 1;
	render_height = 32;
	i = 0;
	while(map_skeleton[i])
	{
		if (map_skeleton[i][line_width] == '1')
		{
			render_elmt(game, game->map->img_wallmr, 
				line_width * 32, render_height);
		}
		if (i == game->map->qt_lines - 3)
			break;
		render_height = render_height + 32;
		i ++;
	}
}
//draw the center tiles of the map
//init player position from t_player struct
void	draw_mapcenter(t_game *game)
{
	int qt_chars;
	int i;
	int j;
	
	qt_chars = game->map->qt_chars_lines - 1;
	i = 0;
	while (game->map->map_skeleton[++i])
	{
		j = 0;
		while (game->map->map_skeleton[i][++j] != '\0' 
			&& i < game->map->qt_lines - 1)
		{
			if (game->map->map_skeleton[i][j] == '0' && j < qt_chars)
				render_elmt(game, game->map->img_floor, 32 * j, 32 * i);
			if (game->map->map_skeleton[i][j] == '1' && j < qt_chars)
				render_elmt(game, game->map->img_murr, 32 * j, 32 * i);
			if (game->map->map_skeleton[i][j] == 'P' && j < qt_chars)
			{
				game->player->pl_x = j;
				game->player->pl_y = i;
				render_elmt(game, game->player->img_sfront, 32 * j, 32 * i);
			}
		}
	}
}
//Check position of the coins.
void	draw_mapcoins(t_game *game)
{
	int qt_chars;
	int i;
	int j;

	qt_chars = game->map->qt_chars_lines - 1;
	i = 0;
	while (game->map->map_skeleton[++i])
	{
		j = 0;
		while (game->map->map_skeleton[i][++j] != '\0' 
			&& i < game->map->qt_lines - 1)
		{
			if (game->map->map_skeleton[i][j] == 'C' && j < qt_chars)
				render_coin(game, 32 * j, 32 * i);
		}
	}
}

//Check pos for the exit
void	draw_exit(t_game *game)
{
	int qt_chars;
	int i;
	int j;

	qt_chars = game->map->qt_chars_lines - 1;
	i = 0;
	while (game->map->map_skeleton[++i])
	{
		j = 0;
		while (game->map->map_skeleton[i][++j] != '\0' 
			&& i < game->map->qt_lines - 1)
		{
			if (game->map->map_skeleton[i][j] == 'E' && j < qt_chars)
				render_exit(game, 32 * j, 32 * i);
				
		}
	}
}