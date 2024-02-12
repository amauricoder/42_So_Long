/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_commands.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: murilo <murilo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 12:39:09 by murilo            #+#    #+#             */
/*   Updated: 2024/02/12 09:33:27 by murilo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"


int	game_commands(t_game *game)
{
    mlx_key_hook(game->data_mlx->window, game_keypress, game);
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