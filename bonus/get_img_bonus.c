/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_img_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 11:24:35 by aconceic          #+#    #+#             */
/*   Updated: 2024/03/20 14:34:27 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

//array 9 size
void	get_enemyimg(t_gmbonus *host, t_game *game)
{
	t_mlx_data	*conn;
	int			h;
	int			w;

	conn = game->data_mlx->connect;
	h = game->img_h;
	w = game->img_w;
	host->ht_img[0] = mlx_xpm_file_to_image(conn, H_SFRONT, &h, &w);
	host->ht_img[1] = mlx_xpm_file_to_image(conn, H_WFRONT, &h, &w);
	host->ht_img[2] = mlx_xpm_file_to_image(conn, H_WFRONT2, &h, &w);
	host->ht_img[3] = mlx_xpm_file_to_image(conn, H_WBACK, &h, &w);
	host->ht_img[4] = mlx_xpm_file_to_image(conn, H_WBACK2, &h, &w);
	host->ht_img[5] = mlx_xpm_file_to_image(conn, H_WLEFT, &h, &w);
	host->ht_img[6] = mlx_xpm_file_to_image(conn, H_WLEFT2, &h, &w);
	host->ht_img[7] = mlx_xpm_file_to_image(conn, H_WRIGHT, &h, &w);
	host->ht_img[8] = mlx_xpm_file_to_image(conn, H_WRIGHT2, &h, &w);
}
