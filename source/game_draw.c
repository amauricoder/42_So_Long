/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_draw.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 12:54:13 by aconceic          #+#    #+#             */
/*   Updated: 2024/03/20 14:31:42 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Call all the functions to make a mapping of the positions of
//the tiles and render(using render functions) the specific tile on the
//right place. Magic 32 value inside the functions is related to img size.
int	game_drawmap(t_game *game)
{
	draw_mapcorners(game);
	draw_mapwallup(game);
	draw_mapwallbottom(game);
	draw_mapwall_left(game);
	draw_mapwall_right(game);
	draw_mapcenter(game);
	draw_mapcoins(game);
	draw_exit(game);
	return (0);
}

//Draw the corners tiles of the map
//-1 on renders is because the map skeleton has \n and lines count '\0'.
void	draw_mapcorners(t_game *game)
{
	int		render_w;
	int		render_h;
	t_map	*mp;

	mp = game->map;
	render_h = (game->map->qt_lines - 1) * 32;
	render_w = (game->map->qt_chars_lines - 1) * 32;
	render_elmt(game, mp->img_walll, 0, 0);
	render_elmt(game, mp->img_wallr, render_w, 0);
	render_elmt(game, mp->img_wallbl, 0, render_h);
	render_elmt(game, mp->img_wallbr, render_w, render_h);
}

//Draw the center tiles from the upside (expect the corners).
void	draw_mapwallup(t_game *game)
{
	char	**map_skeleton;
	int		i;
	int		render_pos;
	int		tiles_width;

	tiles_width = game->map->qt_chars_lines;
	map_skeleton = game->map->map_skeleton;
	render_pos = 32;
	i = 2;
	while (i < tiles_width)
	{
		if (map_skeleton[0][i] == '1')
		{
			render_elmt(game, game->map->img_wallc, render_pos, 0);
			render_pos = render_pos + 32;
		}
		i ++;
	}
}

//Draw the center tiles from the bottomside (expect the corners).
void	draw_mapwallbottom(t_game *game)
{
	char	**map_skeleton;
	int		i;
	int		render_pos;
	int		render_h;

	map_skeleton = game->map->map_skeleton;
	render_pos = 32;
	i = 2;
	render_h = (game->map->qt_lines - 1) * 32;
	while (i < game->map->qt_chars_lines)
	{
		if (map_skeleton[game->map->qt_lines - 1][i] == '1')
		{
			render_elmt(game, game->map->img_wallbc, render_pos, render_h);
			render_pos = render_pos + 32;
		}
		i ++;
	}
}
