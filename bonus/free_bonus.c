/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: murilo <murilo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 11:44:26 by murilo            #+#    #+#             */
/*   Updated: 2024/02/24 12:19:37 by murilo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

int	game_close_bonus(t_enemy *bonus)
{
    t_game *game;

    ft_printf("gameclosebonus\n");
    game = bonus->game_main;
	free_dp_char(game->map->map_skeleton);
	free_map_imgptr(game);
	free_player_imgptr(game);
	free_coin_imgptr(game);
	free_exit_imgptr(game);
    free_enemy_imgptr(bonus);
	mlx_destroy_window(game->data_mlx->connect, game->data_mlx->window);
	mlx_destroy_display(game->data_mlx->connect);
	free(game->map);
	free(game->player);
	free(game->coin);
	free(game->exit);
	free(game->data_mlx->connect);
	free(game->data_mlx);
	free(game);
    free(bonus);
	exit(0);
	return (0);
}

void    free_enemy_imgptr(t_enemy *bonus)
{
    int i;

    i = 0;
    while (i < 9)
    {
        mlx_destroy_image(bonus->game_main->data_mlx->connect, bonus->ht_img[i]);
        i ++;
    }
}