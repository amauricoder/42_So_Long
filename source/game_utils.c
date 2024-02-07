/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: murilo <murilo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 10:27:46 by aconceic          #+#    #+#             */
/*   Updated: 2024/02/07 15:17:10 by murilo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	game_close(t_game *game)
{
	mlx_destroy_window(game->data_mlx->connect, game->data_mlx->window);
	mlx_destroy_display(game->data_mlx->connect);
	free_dp_char(game->map->map_skeleton);
	free(game->map);
	free(game->data_mlx->connect);
	free(game->data_mlx);
	free(game);
	exit(0);
}