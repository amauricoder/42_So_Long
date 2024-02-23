/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: murilo <murilo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 11:27:18 by murilo            #+#    #+#             */
/*   Updated: 2024/02/22 18:30:22 by murilo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

t_enemy	*game_init_bonus(t_game *game)
{
	ft_printf("Game init bonus\n");
	int			wnd_h;
	int			wnd_w;
	t_mlx_data	*conn;
	t_enemy		*enemy;

	wnd_h = ((game->map->qt_lines) * 32);
	wnd_w = (game->map->qt_chars_lines) * 32;
	game = game_init_structs(game);
	game_init_values(game);
	game->data_mlx->connect = mlx_init();
	conn = game->data_mlx->connect;
	game->data_mlx->window = mlx_new_window(conn, wnd_w, wnd_h, "So Long");
	get_mapimg(game);
	get_playerimg(game);
	get_coinimg(game);
	get_exitimg(game);
	enemy = bonus_init_enemystruct(game);
	game_drawmap_bonus(enemy->bonus);
	ft_printmovs(enemy->bonus);
	return (enemy);
}

//h for HOSTILE.
t_enemy *bonus_init_enemystruct(t_game *game)
{
	t_enemy *h;

	h = malloc(sizeof(t_enemy));
	if (!h)
		return NULL;
	get_enemyimg(h, game);
	h->bonus = game;
	h->ht_x = 0;
	h->ht_y = 0;
	h->ht_loop = 0;
	return (h);
}