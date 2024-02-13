/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: murilo <murilo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 15:27:56 by aconceic          #+#    #+#             */
/*   Updated: 2024/02/13 13:38:01 by murilo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

//Inits all the structures and elements necessary
//for the game. Ps. 32 is related to the size of the images.
void	game_init(t_game *game)
{
	int wnd_h;
	int wnd_w;
	t_mlx_data *conn;
	
	wnd_h = (game->map->qt_lines) * 32;
	wnd_w = (game->map->qt_chars_lines) * 32;
	game = game_structs_init(game);
	game->data_mlx->connect = mlx_init();
	conn = game->data_mlx->connect;
	game->data_mlx->window = mlx_new_window(conn, wnd_w, wnd_h, "So Long");
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
	game->coin->coin_pos = 0;
	game->coin->coin_loop = 0;
	return (game);
}
//Get the xpm images to the void pointers into he map structure
//check for null values after to mischeck error
void	game_get_mapimg(t_game *game)
{
	t_map *mp;
	t_mlx_data *conn;
	int gih;
	int giw;
	
	mp = game->map;
	conn = game->data_mlx->connect;
	gih = game->img_h;
	giw = game->img_w;
	mp->img_floor = mlx_xpm_file_to_image(conn, FLOOR, &gih, &giw);
	mp->img_murr = mlx_xpm_file_to_image(conn, MURR, &gih, &giw);
	mp->img_wallbl = mlx_xpm_file_to_image(conn, WALL_BL, &gih, &giw);
	mp->img_wallbr = mlx_xpm_file_to_image(conn, WALL_BR, &gih, &giw);
	mp->img_wallc = mlx_xpm_file_to_image(conn, WALL_C, &gih, &giw);
	mp->img_walll = mlx_xpm_file_to_image(conn, WALL_L, &gih, &giw);
	mp->img_wallml = mlx_xpm_file_to_image(conn, WALL_ML, &gih, &giw);
	mp->img_wallmr = mlx_xpm_file_to_image(conn, WALL_MR, &gih, &giw);
	mp->img_wallr = mlx_xpm_file_to_image(conn, WALL_R, &gih, &giw);
	mp->img_wallbc = mlx_xpm_file_to_image(conn, WALL_BC, &gih, &giw);
	check_nullvalues_m(game, 'm');
}

//Get the xpm images to the void pointers into the player structure
//check for null values after to mischeck error
void	game_get_playerimg(t_game *game)
{
	t_player *gp;
	t_mlx_data *conn;
	int	gih;
	int giw;

	gp = game->player;
	conn = game->data_mlx->connect;
	gih = game->img_h;
	giw = game->img_w;
	gp->img_sfront = mlx_xpm_file_to_image(conn, SFRONT, &gih, &giw);
 	gp->img_sback = mlx_xpm_file_to_image(conn, SBACK, &gih, &giw);
	gp->img_sleft = mlx_xpm_file_to_image(conn, SLEFT, &gih, &giw);
	gp->img_sright = mlx_xpm_file_to_image(conn, SRIGHT, &gih, &giw);
	gp->img_wback = mlx_xpm_file_to_image(conn, WBACK, &gih, &giw);
	gp->img_wback2 = mlx_xpm_file_to_image(conn, WBACK2, &gih, &giw);
	gp->img_wfront = mlx_xpm_file_to_image(conn, WFRONT, &gih, &giw);
	gp->img_wfront2 = mlx_xpm_file_to_image(conn, WFRONT2, &gih, &giw);
	gp->img_wleft = mlx_xpm_file_to_image(conn, WLEFT, &gih, &giw);
	gp->img_wleft2 = mlx_xpm_file_to_image(conn, WLEFT2, &gih, &giw);
	gp->img_wright = mlx_xpm_file_to_image(conn, WRIGHT, &gih, &giw);
	gp->img_wright2 = mlx_xpm_file_to_image(conn, WRIGHT2, &gih, &giw);
	check_nullvalues_pc(game, 'p');
}
//Get the xpm images to the void pointers into the coin structure
//check for null values after to mischeck error
void	game_get_coinimg(t_game *game)
{
	t_mlx_data *conn;
	t_coin	*coin;
	int		h;
	int		w;

	conn = game->data_mlx->connect;
	coin = game->coin;
	h = game->img_h;
	w = game->img_w;
	
	coin->c_imgs[0] = mlx_xpm_file_to_image(conn, COIN1, &h, &w);
	coin->c_imgs[1] = mlx_xpm_file_to_image(conn, COIN2, &h, &w);
	coin->c_imgs[2] = mlx_xpm_file_to_image(conn, COIN3, &h, &w);
	coin->c_imgs[3] = mlx_xpm_file_to_image(conn, COIN4, &h, &w);
	coin->c_imgs[4] = mlx_xpm_file_to_image(conn, COIN5, &h, &w);
	coin->c_imgs[5] = mlx_xpm_file_to_image(conn, COIN6, &h, &w);

	check_nullvalues_pc(game, 'c');
}
//check for image null values on the player and coin structures
//function just for debug, because if there is something NULL
//It will lead to seg fault
void	check_nullvalues_pc(t_game *game, char pointers)
{
	t_player *gp;
	//t_coin	*clb;
	
	gp = game->player;
	//clb = game->coin;
	if (pointers == 'p')
	{
		if (gp->img_sback == NULL || gp->img_sfront == NULL 
			|| gp->img_sleft == NULL || gp->img_sright == NULL
			|| gp->img_wback == NULL || gp->img_wback2 == NULL
			|| gp->img_wfront == NULL || gp->img_wfront2 == NULL
			|| gp->img_wleft == NULL || gp->img_wleft2 == NULL
			|| gp->img_wright == NULL || gp->img_wright2 == NULL)
		ft_printf("ERROR AT GAME_GET_PLAYERIMG\n");
	}
	 if (pointers == 'c')
	 {
		if (game->coin->c_imgs[5] == NULL)
		{
			ft_printf("ERROR AT GAME_GET_COINIMG\n");
		}
	 }
	 //	ft_printf("c pointers are not being checked\n");
}

//check for image null values on the map structure
//function just for debug, because if there is something NULL
//It will lead to seg fault
void	check_nullvalues_m(t_game *game, char pointers)
{
	t_map *map;

	map = game->map;
	if (pointers == 'm')
	{
		if(map->img_floor == NULL || map->img_murr == NULL 
			|| map->img_wallbl == NULL || map->img_wallbr == NULL
			|| map->img_wallc == NULL || map->img_walll == NULL
			|| map->img_wallml == NULL || map->img_wallmr == NULL 
			|| map->img_wallr == NULL || game->map->img_wallbc == NULL)
		ft_printf("ERROR AT GAME_GET_MAPIMG\n");		
	}
}
