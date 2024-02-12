/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_render.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: murilo <murilo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 09:43:32 by murilo            #+#    #+#             */
/*   Updated: 2024/02/12 14:13:35 by murilo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

//Main function to draw the map components
//32 value inside the function is related to img size
int game_drawmap(t_game *game)
{
	ft_printf("Entrou em game_drawmap\n");
	draw_mapcorners(game);
	draw_mapwallup(game);
	draw_mapwallbottom(game);
	draw_mapwall_left(game);
	draw_mapwall_right(game);
	draw_mapcenter(game);
	return (0);
}

//Draw the corners tiles of the map
//-1 on renders is because the map skeleton has \n and lines count '\0'
void draw_mapcorners(t_game *game)
{
	int render_w;
	int render_h;
	t_map *mp;

	mp = game->map;
	render_h = (game->map->qt_lines - 1) * 32;
	render_w = (game->map->qt_chars_lines - 1) * 32;
	render_element(game, mp->img_walll, 0, 0);
	render_element(game, mp->img_wallr, render_w, 0);
	render_element(game, mp->img_wallbl, 0, render_h);
	render_element(game, mp->img_wallbr, render_w, render_h);
}


//Draw the center tiles from the upside (expect the corners)
void draw_mapwallup(t_game *game)
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
			render_element(game, game->map->img_wallc, render_pos, 0);
			render_pos = render_pos + 32;
		}
		i ++;
	}
}

//Draw the center tiles from the bottomside (expect the corners)
void draw_mapwallbottom(t_game *game)
{
	char **map_skeleton;
	int	i;
	int render_pos;
	int render_h;

	map_skeleton = game->map->map_skeleton;
	render_pos = 32;
	i = 2;
	render_h = (game->map->qt_lines - 1) * 32;
	while (i < game->map->qt_chars_lines)
	{
		if (map_skeleton[game->map->qt_lines - 1][i] == '1')
		{
			render_element(game, game->map->img_wallbc, render_pos, render_h);
			render_pos = render_pos + 32;
		}
		i ++;
	}
}

//Draw the left walls of the map
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
			render_element(game, game->map->img_wallml, 0, render_height);
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
			render_element(game, game->map->img_wallmr, 
				line_width * 32, render_height);
		}
		if (i == game->map->qt_lines - 3)
			break;
		render_height = render_height + 32;
		i ++;
	}
}

//draw the center tiles of the map
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
				render_element(game, game->map->img_floor, 32 * j, 32 * i);
			if (game->map->map_skeleton[i][j] == '1' && j < qt_chars)
				render_element(game, game->map->img_murr, 32 * j, 32 * i);
			if (game->map->map_skeleton[i][j] == 'P' && j < qt_chars)
				render_element(game, game->player->img_sfront, 32 * j, 32 * i);
			if (game->map->map_skeleton[i][j] == 'C' && j < qt_chars)
				render_element(game, game->coin->img_c1, 32 * j, 32 * i);
		}
	}
}

void	render_element(t_game *game, void *img, int width, int height)
{
	t_mlx_data *conn;
	t_mlx_data *wnd;
	
	conn = game->data_mlx->connect;
	wnd = game->data_mlx->window;

	mlx_put_image_to_window(conn, wnd, img, width, height);
}
