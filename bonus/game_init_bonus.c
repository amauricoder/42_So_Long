/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: murilo <murilo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 11:27:18 by murilo            #+#    #+#             */
/*   Updated: 2024/02/26 22:58:39 by murilo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"
//enemy->ht_x e enemy->ht_y defined in the middle of the function, 
//but I need to fix this.
t_gmbonus	*game_init_bonus(t_game *game)
{
	int				wnd_h;
	int				wnd_w;
	t_mlx_data		*conn;
	t_gmbonus		*enemy;

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
	game_drawmap_bonus(enemy->game_main);
	game_draw_fenemy(enemy);
	ft_printmovs(enemy->game_main);
	return (enemy);
}

//h for HOSTILE.
//Funtion to init the t_gmbonus struct
//with initial values
t_gmbonus	*bonus_init_enemystruct(t_game *game)
{
	t_gmbonus	*h;

	h = malloc(sizeof(t_gmbonus));
	if (!h)
		return (NULL);
	get_enemyimg(h, game);
	h->game_main = game;
	h->ht_x = 0;
	h->ht_y = 0;
	h->ht_loop = 0;
	h->pl2_lstep = 0;
	h->ht_isoncoin = 0;
	h->hpos_x = 0;
	h->hpos_y = 0;
	h->chprevious = '0';
	return (h);
}
