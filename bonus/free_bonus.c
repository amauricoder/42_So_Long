/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 11:44:26 by aconceic          #+#    #+#             */
/*   Updated: 2024/03/20 14:33:37 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

//function to clean everything when user press
//ESC or click on the X
int	game_close_bonus(t_gmbonus *bonus)
{
	t_game	*game;

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

//Clean the img pointers of the enemy charactere
void	free_enemy_imgptr(t_gmbonus *bonus)
{
	int	i;

	i = 0;
	while (i < 9)
	{
		mlx_destroy_image(bonus->game_main->data_mlx->connect,
			bonus->ht_img[i]);
		i ++;
	}
}
