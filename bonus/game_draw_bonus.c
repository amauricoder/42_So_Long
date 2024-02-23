/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_draw_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: murilo <murilo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 12:54:13 by murilo            #+#    #+#             */
/*   Updated: 2024/02/23 19:43:44 by murilo           ###   ########.fr       */
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

