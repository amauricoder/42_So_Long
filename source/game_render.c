/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_render.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: murilo <murilo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 09:43:32 by murilo            #+#    #+#             */
/*   Updated: 2024/02/12 10:06:41 by murilo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int game_drawmap(t_game *game)
{
	ft_printf("Entrou em game_drawmap\n");
	draw_mapcorners(game);
	draw_mapwallup(game);
	draw_mapwallbottom(game);
	draw_mapsides(game);
	draw_mapcenter(game);
	return (0);
}
//Draw the corners tiles of the map
int draw_mapcorners(t_game *game)
{
	char **map_skeleton;
	int render_width;
	int render_height;
	int qt_tiles_height;
	int qt_tiles_width;
	
	render_height = (game->map->qt_lines - 1) * 32;
	render_width = (game->map->qt_chars_lines - 1) * 32;
	qt_tiles_height = game->map->qt_lines - 1;
	qt_tiles_width = game->map->qt_chars_lines - 1;
	map_skeleton = game->map->map_skeleton;
	if(map_skeleton[0][0] == '1')
		mlx_put_image_to_window(game->data_mlx->connect, game->data_mlx->window, game->map->img_walll, 0, 0);
	if (map_skeleton[0][qt_tiles_width] == '1')
		mlx_put_image_to_window(game->data_mlx->connect, game->data_mlx->window, game->map->img_wallr, render_width, 0);   
	if (map_skeleton[qt_tiles_height][0] == '1')
	   mlx_put_image_to_window(game->data_mlx->connect, game->data_mlx->window, game->map->img_wallbl, 0, render_height);
	if (map_skeleton[qt_tiles_height][qt_tiles_width] == '1')
	   mlx_put_image_to_window(game->data_mlx->connect, game->data_mlx->window, game->map->img_wallbr, render_width, render_height);
	//dont forget to clen this map skeleton double pointer char
	return (0);
}
//Draw the center tiles from the upside (expect the corners)
int draw_mapwallup(t_game *game)
{
	char **map_skeleton;
	int	i;
	int render_pos;
	int tiles_width;

	tiles_width = game->map->qt_chars_lines;
	map_skeleton = game->map->map_skeleton;
	render_pos = 32;
	i = 2;
	while (i < tiles_width)
	{
		if (map_skeleton[0][i] == '1')
		{
			mlx_put_image_to_window(game->data_mlx->connect, game->data_mlx->window, game->map->img_wallc, render_pos, 0);
			render_pos = render_pos + 32;
		}
		i ++;
	}
	return (0);
}
//Draw the center tiles from the bottomside (expect the corners)
int draw_mapwallbottom(t_game *game)
{
	char **map_skeleton;
	int	i;
	int render_pos;
	int render_height;
	int tiles_width;
	int	last_line;

	tiles_width = game->map->qt_chars_lines;
	map_skeleton = game->map->map_skeleton;
	render_pos = 32;
	last_line = game->map->qt_lines - 1;
	i = 2;
	render_height = last_line* 32;
	while (i < tiles_width)
	{
		if (map_skeleton[last_line][i] == '1')
		{
			mlx_put_image_to_window(game->data_mlx->connect, game->data_mlx->window, game->map->img_wallbc, render_pos, render_height);
			render_pos = render_pos + 32;
		}
		i ++;
	}
	//dont forget to clean the double pointer char here
	return (0);
}
////Draw the center tiles from the both sides (expect the corners)
int	draw_mapsides(t_game *game)
{
	int i;
	int render_height;
	int line_width;
	char	**map_skeleton;

	map_skeleton = game->map->map_skeleton;
	i = 0;
	render_height = 32;
	while(map_skeleton[i])
	{
		if (i == game->map->qt_lines - 2)
			break;
		if (map_skeleton[i][0] == '1')
			mlx_put_image_to_window(game->data_mlx->connect, game->data_mlx->window, game->map->img_wallml, 0, render_height);
		render_height = render_height + 32;
		i ++;
	}
	line_width = game->map->qt_chars_lines - 1;
	render_height = 32;
	i = 0;
	while(map_skeleton[i])
	{
		if (map_skeleton[i][line_width] == '1')
		{
			mlx_put_image_to_window(game->data_mlx->connect, game->data_mlx->window, game->map->img_wallmr, (line_width) * 32, render_height);
		}
		if (i == game->map->qt_lines - 3)
			break;
		render_height = render_height + 32;
		i ++;
	}
	//dont forget to clent this double pointer char
	return (0);
}

//draw the center tiles of the map
int	draw_mapcenter(t_game *game)
{
	char **map_skeleton;
	int qt_chars;
	int i;
	int j;
	
	map_skeleton = game->map->map_skeleton;
	qt_chars = game->map->qt_chars_lines - 1;
	i = 1;
	while (map_skeleton[i])
	{
		j = 1;
		while (map_skeleton[i][j] != '\0')
		{
			if (map_skeleton[i][j] == '0' && j < qt_chars)
			{
				mlx_put_image_to_window(game->data_mlx->connect, game->data_mlx->window, game->map->img_floor, 32 * j, 32 * i);
			}
			if (map_skeleton[i][j] == '1' && j < qt_chars)
			{
				mlx_put_image_to_window(game->data_mlx->connect, game->data_mlx->window, game->map->img_murr, 32 * j, 32 * i);
			}
			if (map_skeleton[i][j] == 'P' && j < qt_chars)
			{
				mlx_put_image_to_window(game->data_mlx->connect, game->data_mlx->window, game->player->img_sfront, 32 * j, 32 * i);
			}
			if (map_skeleton[i][j] == 'C' && j < qt_chars)
			{
				mlx_put_image_to_window(game->data_mlx->connect, game->data_mlx->window, game->coin->img_c1, 32 * j, 32 * i);
			}
			j ++;
		}
		if (i == game->map->qt_lines - 2)
			break;
		i ++;
	}
	return (0);
}
