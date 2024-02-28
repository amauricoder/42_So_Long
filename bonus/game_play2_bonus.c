/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_play2_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: murilo <murilo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 15:56:44 by murilo            #+#    #+#             */
/*   Updated: 2024/02/26 22:06:05 by murilo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

void	p2key_up_pressed(t_gmbonus *bn, t_game *game, char **map_sk)
{
	t_map		*mp;

	mp = game->map;
	if (map_sk[bn->ht_y - 1][bn->ht_x] != '1' && bn->pl2_lstep == FALSE)
	{
		bn->ht_y --;
		render_elmt(game, mp->img_floor, 32 * bn->ht_x, 32 * (bn->ht_y + 1));
		render_elmt(game, bn->ht_img[3], 32 * bn->ht_x, 32 * bn->ht_y);
		bn->pl2_lstep = TRUE;
	}
	else if (map_sk[bn->ht_y - 1][bn->ht_x] != '1' && bn->pl2_lstep == TRUE)
	{
		bn->ht_y --;
		render_elmt(game, mp->img_floor, 32 * bn->ht_x, 32 * (bn->ht_y + 1));
		render_elmt(game, bn->ht_img[4], 32 * bn->ht_x, 32 * bn->ht_y);
		bn->pl2_lstep = FALSE;
	}
}

void	p2key_down_pressed(t_gmbonus *bn, t_game *game, char **map_sk)
{
	t_map		*mp;

	mp = game->map;
	if (map_sk[bn->ht_y + 1][bn->ht_x] != '1' && bn->pl2_lstep == FALSE)
	{
		bn->ht_y ++;
		render_elmt(game, mp->img_floor, 32 * bn->ht_x, 32 * (bn->ht_y - 1));
		render_elmt(game, bn->ht_img[1], 32 * bn->ht_x, 32 * bn->ht_y);
		bn->pl2_lstep = TRUE;
	}
	else if (map_sk[bn->ht_y + 1][bn->ht_x] != '1' && bn->pl2_lstep == TRUE)
	{
		bn->ht_y ++;
		render_elmt(game, mp->img_floor, 32 * bn->ht_x, 32 * (bn->ht_y - 1));
		render_elmt(game, bn->ht_img[2], 32 * bn->ht_x, 32 * bn->ht_y);
		bn->pl2_lstep = FALSE;
	}
}

void	p2key_left_pressed(t_gmbonus *bn, t_game *game, char **map_sk)
{
	t_map		*mp;

	mp = game->map;
	if (map_sk[bn->ht_y][bn->ht_x - 1] != '1' && bn->pl2_lstep == FALSE)
	{
		bn->ht_x --;
		render_elmt(game, mp->img_floor, 32 * (bn->ht_x + 1), 32 * bn->ht_y);
		render_elmt(game, bn->ht_img[5], 32 * bn->ht_x, 32 * bn->ht_y);
		bn->pl2_lstep = TRUE;
	}
	else if (map_sk[bn->ht_y][bn->ht_x - 1] != '1' && bn->pl2_lstep == TRUE)
	{
		bn->ht_x --;
		render_elmt(game, mp->img_floor, 32 * (bn->ht_x + 1), 32 * bn->ht_y);
		render_elmt(game, bn->ht_img[6], 32 * bn->ht_x, 32 * bn->ht_y);
		bn->pl2_lstep = FALSE;
	}
}

void	p2key_right_pressed(t_gmbonus *bn, t_game *game, char **map_sk)
{
	t_map		*mp;

	mp = game->map;
	if (map_sk[bn->ht_y][bn->ht_x + 1] != '1' && bn->pl2_lstep == FALSE)
	{
		bn->ht_x ++;
		render_elmt(game, mp->img_floor, 32 * (bn->ht_x - 1), 32 * bn->ht_y);
		render_elmt(game, bn->ht_img[7], 32 * bn->ht_x, 32 * bn->ht_y);
		bn->pl2_lstep = TRUE;
	}
	else if (map_sk[bn->ht_y][bn->ht_x + 1] != '1' && bn->pl2_lstep == TRUE)
	{
		bn->ht_x ++;
		render_elmt(game, mp->img_floor, 32 * (bn->ht_x - 1), 32 * bn->ht_y);
		render_elmt(game, bn->ht_img[8], 32 * bn->ht_x, 32 * bn->ht_y);
		bn->pl2_lstep = FALSE;
	}
}
