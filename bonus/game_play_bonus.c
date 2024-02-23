/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_play_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: murilo <murilo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 12:39:09 by murilo            #+#    #+#             */
/*   Updated: 2024/02/23 13:46:50 by murilo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

int	game_play_bonus(t_enemy *bonus)
{
	ft_printf("gameplay bonus\n");
	t_mlx_data	*conn;
	t_mlx_data	*window;
	t_game		*game;

	game = bonus->bonus;
	conn = game->data_mlx->connect;
	window = game->data_mlx->window;
	mlx_key_hook(window, game_keypressed, game);
	mlx_hook(window, 17, 1L << 17, game_close, game);
	mlx_loop_hook(conn, coin_animation, game);
	return (0);
}


