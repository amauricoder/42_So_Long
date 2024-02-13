/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_commands.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: murilo <murilo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 12:39:09 by murilo            #+#    #+#             */
/*   Updated: 2024/02/13 18:40:06 by murilo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"


int	game_commands(t_game *game)
{
	t_mlx_data *conn;
	t_mlx_data *window;

	conn = game->data_mlx->connect;
	window = game->data_mlx->window;
    mlx_key_hook(window, game_keypress, game);
	mlx_hook(window, 17, 1L << 17, game_close, game);
	mlx_loop_hook(conn, coin_animation, game);
    return (0);
}

int	game_keypress(int keypressed, t_game *game)
{
	if (keypressed == KB_ESC)
	{
        game_close(game);
	}
	ft_printf("Key pressed number %i\n", keypressed);
	return (0);
}