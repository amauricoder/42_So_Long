/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_images.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 12:45:29 by aconceic          #+#    #+#             */
/*   Updated: 2024/03/20 14:31:02 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

//Get the xpm images to the void pointers into he map structure
//check for null values after to mischeck error
void	get_mapimg(t_game *game)
{
	t_map		*mp;
	t_mlx_data	*conn;
	int			gih;
	int			giw;

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
	check_nullvalues_me(game, 'm');
}

//Get the xpm images to the void pointers into the player structure
//check for null values after to mischeck error
void	get_playerimg(t_game *game)
{
	t_player	*gp;
	t_mlx_data	*conn;
	int			gih;
	int			giw;

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
void	get_coinimg(t_game *game)
{
	t_mlx_data	*conn;
	t_coin		*coin;
	int			h;
	int			w;

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

void	get_exitimg(t_game *game)
{
	t_mlx_data	*conn;
	t_exit		*exit;
	int			h;
	int			w;

	conn = game->data_mlx->connect;
	exit = game->exit;
	h = game->img_h;
	w = game->img_w;
	exit->e_imgs[0] = mlx_xpm_file_to_image(conn, EXIT1, &h, &w);
	exit->e_imgs[1] = mlx_xpm_file_to_image(conn, EXIT2, &h, &w);
	exit->e_imgs[2] = mlx_xpm_file_to_image(conn, EXIT3, &h, &w);
	exit->e_imgs[3] = mlx_xpm_file_to_image(conn, EXIT4, &h, &w);
	exit->e_imgs[4] = mlx_xpm_file_to_image(conn, EXIT5, &h, &w);
	exit->e_imgs[5] = mlx_xpm_file_to_image(conn, EXIT6, &h, &w);
	exit->e_imgs[6] = mlx_xpm_file_to_image(conn, EXIT7, &h, &w);
	exit->e_imgs[7] = mlx_xpm_file_to_image(conn, EXIT8, &h, &w);
	exit->e_imgs[8] = mlx_xpm_file_to_image(conn, EXIT9, &h, &w);
	exit->e_imgs[9] = mlx_xpm_file_to_image(conn, EXIT10, &h, &w);
	check_nullvalues_me(game, 'e');
}
