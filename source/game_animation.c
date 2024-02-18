/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_animation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: murilo <murilo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 10:48:49 by murilo            #+#    #+#             */
/*   Updated: 2024/02/18 11:59:51 by murilo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	coin_animation(t_game *game)
{
	if (game->coin->coin_loop < 2000)
	{
		game->coin->coin_loop++;
		return (0);
	}
	game->coin->coin_loop = 0;
    if (game->coin->coin_pos >= 6 || game->coin->coin_pos <= 0) {
        game->coin->coin_pos = 0;
    }
	draw_mapcoins(game);
	game->coin->coin_pos++;
	return (0);
}
