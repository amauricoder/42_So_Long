/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_draw_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: murilo <murilo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 12:54:13 by murilo            #+#    #+#             */
/*   Updated: 2024/02/23 20:08:12 by murilo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

int	game_drawmap_bonus(t_game *game)
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

//Set values of the enemy as the exit and do the first render
//This means that the enemy will aways spawn
//in the same place as the exit
int	game_draw_fenemy(t_enemy *bonus)
{
	t_game *game;

	game = bonus->game_main;
	bonus->ht_x = bonus->game_main->exit->exit_x;
	bonus->ht_y = bonus->game_main->exit->exit_y;
	render_elmt(game, bonus->ht_img[0], 
		bonus->ht_x * 32, bonus->ht_y * 32);
	return (0);
}

