/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: murilo <murilo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 15:27:56 by aconceic          #+#    #+#             */
/*   Updated: 2024/02/12 09:55:25 by murilo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	game_init(t_game *game)
{
	int window_height;
	int window_width;

	window_height = (game->map->qt_lines) * 32;
	window_width = (game->map->qt_chars_lines) * 32;
	game = game_structs_init(game);
	game->data_mlx->connect = mlx_init();
	game->data_mlx->window = mlx_new_window(game->data_mlx->connect, window_width, window_height, "So Long");
	game_get_mapimg(game);
	game_get_playerimg(game);
	game_get_coinimg(game);
	game_drawmap(game);
}
//Initialize the structures for the game
//except for the main struct and the map struct.
//Return the main struct with the structures inside initialized
t_game	*game_structs_init(t_game *game)
{
	t_mlx_data *data_mlx;
	t_player	*player;
	t_coin		*coin;
	
	data_mlx = malloc(sizeof(t_mlx_data));
	player = malloc(sizeof(t_player));
	coin = malloc(sizeof(t_coin));
	if (!data_mlx || !player || !coin)
	{
		error_message(11);
		return (NULL);
	}
	game->data_mlx = data_mlx;
	game->player = player;
	game->coin = coin;
	return (game);
}
void	game_get_mapimg(t_game *game)
{
	t_map *mp;
	t_mlx_data *dp;
	
	mp = game->map;
	dp = game->data_mlx->connect;
	mp->img_floor = mlx_xpm_file_to_image(dp, FLOOR, &game->img_h, &game->img_w);
	mp->img_murr = mlx_xpm_file_to_image(dp, MURR, &game->img_h, &game->img_w);
	mp->img_wallbl = mlx_xpm_file_to_image(dp, WALL_BL, &game->img_h, &game->img_w);
	mp->img_wallbr = mlx_xpm_file_to_image(dp, WALL_BR, &game->img_h, &game->img_w);
	mp->img_wallc = mlx_xpm_file_to_image(dp, WALL_C, &game->img_h, &game->img_w);
	mp->img_walll = mlx_xpm_file_to_image(dp, WALL_L, &game->img_h, &game->img_w);
	mp->img_wallml = mlx_xpm_file_to_image(dp, WALL_ML, &game->img_h, &game->img_w);
	mp->img_wallmr = mlx_xpm_file_to_image(dp, WALL_MR, &game->img_h, &game->img_w);
	mp->img_wallr = mlx_xpm_file_to_image(dp, WALL_R, &game->img_h, &game->img_w);
	mp->img_wallbc = mlx_xpm_file_to_image(dp, WALL_BC, &game->img_h, &game->img_w);
	if(game->map->img_floor == NULL || game->map->img_murr == NULL || game->map->img_wallbl == NULL ||
		game->map->img_wallbr == NULL || game->map->img_wallc == NULL || game->map->img_walll == NULL ||
		game->map->img_wallml == NULL || game->map->img_wallmr == NULL || game->map->img_wallr == NULL
		|| game->map->img_wallbc == NULL)
		ft_printf("ERROR IN SOME IMAGE!!! SOME IMAGE IS NULL!! AT GAME_GET_MAPIMG\n");
}

void	game_get_playerimg(t_game *game)
{
	game->player->img_sfront = mlx_xpm_file_to_image(game->data_mlx->connect, SFRONT, &game->img_h, &game->img_w);
 	game->player->img_sback = mlx_xpm_file_to_image(game->data_mlx->connect, SBACK, &game->img_h, &game->img_w);
	game->player->img_sleft = mlx_xpm_file_to_image(game->data_mlx->connect, SLEFT, &game->img_h, &game->img_w);
	game->player->img_sright = mlx_xpm_file_to_image(game->data_mlx->connect, SRIGHT, &game->img_h, &game->img_w);
	game->player->img_wback = mlx_xpm_file_to_image(game->data_mlx->connect, WBACK, &game->img_h, &game->img_w);
	game->player->img_wback2 = mlx_xpm_file_to_image(game->data_mlx->connect, WBACK2, &game->img_h, &game->img_w);
	game->player->img_wfront = mlx_xpm_file_to_image(game->data_mlx->connect, WFRONT, &game->img_h, &game->img_w);
	game->player->img_wfront2 = mlx_xpm_file_to_image(game->data_mlx->connect, WFRONT2, &game->img_h, &game->img_w);
	game->player->img_wleft = mlx_xpm_file_to_image(game->data_mlx->connect, WLEFT, &game->img_h, &game->img_w);
	game->player->img_wleft2 = mlx_xpm_file_to_image(game->data_mlx->connect, WLEFT2, &game->img_h, &game->img_w);
	game->player->img_wright = mlx_xpm_file_to_image(game->data_mlx->connect, WRIGHT, &game->img_h, &game->img_w);
	game->player->img_wright2 = mlx_xpm_file_to_image(game->data_mlx->connect, WRIGHT2, &game->img_h, &game->img_w);
	
	if (game->player->img_sback == NULL || game->player->img_sfront == NULL || game->player->img_sleft == NULL
		|| game->player->img_sright == NULL || game->player->img_wback == NULL || game->player->img_wback2 == NULL
		|| game->player->img_wfront == NULL || game->player->img_wfront2 == NULL || game->player->img_wleft == NULL
		|| game->player->img_wleft2 == NULL || game->player->img_wright == NULL || game->player->img_wright2 == NULL)
		ft_printf("ERROR IN SOME PLAYER IMAGE!!! SOME IMAGE IS NULL!! AT GAME_GET_PLAYERIMG\n");
}

void	game_get_coinimg(t_game *game)
{
	ft_printf("entrou em coinimg\n");
	
	t_mlx_data *conn;
	t_coin	*coin;
	int		h;
	int		w;

	conn = game->data_mlx->connect;
	coin = game->coin;
	h = game->img_h;
	w = game->img_w;
	coin->img_c1 = mlx_xpm_file_to_image(conn, COIN1, &h, &w);
	coin->img_c2 = mlx_xpm_file_to_image(conn, COIN2, &h, &w);
	coin->img_c3 = mlx_xpm_file_to_image(conn, COIN3, &h, &w);
	coin->img_c4 = mlx_xpm_file_to_image(conn, COIN4, &h, &w);
	coin->img_c5 = mlx_xpm_file_to_image(conn, COIN5, &h, &w);
	coin->img_c6 = mlx_xpm_file_to_image(conn, COIN6, &h, &w);

	if (coin->img_c1 == NULL || coin->img_c2 == NULL || coin->img_c3 == NULL 
		|| coin->img_c4 == NULL || coin->img_c5 == NULL || coin->img_c6 == NULL)
		ft_printf("ERROR IN SOME COIN IMAGE!!! SOME COIN IMG IS NULL|| AT GAME_GET_COINIMG");
}
