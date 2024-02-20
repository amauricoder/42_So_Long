/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 15:27:56 by aconceic          #+#    #+#             */
/*   Updated: 2024/02/20 12:56:55 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

//Inits all the structures and elements necessary
//for the game. Ps. 32 is related to the size of the images.
void	game_init_master(t_game *game)
{
	int			wnd_h;
	int			wnd_w;
	t_mlx_data	*conn;

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
	game_drawmap(game);
	ft_printmovs(game);
}

//Initialize the structures for the game
//except for the main struct and the map struct.
//Return the main struct with the structures inside initialized
t_game	*game_init_structs(t_game *game)
{
	t_mlx_data	*data_mlx;
	t_player	*player;
	t_coin		*coin;
	t_exit		*exit;

	data_mlx = malloc(sizeof(t_mlx_data));
	player = malloc(sizeof(t_player));
	coin = malloc(sizeof(t_coin));
	exit = malloc(sizeof(t_exit));
	if (!data_mlx || !player || !coin || !exit)
	{
		error_message(11);
		return (NULL);
	}
	game->data_mlx = data_mlx;
	game->player = player;
	game->exit = exit;
	game->coin = coin;
	return (game);
}

//Set initial values for variables of the structs
void	game_init_values(t_game *game)
{
	game->exit->exit_y = 0;
	game->exit->exit_x = 0;
	game->qt_mov = 0;
	game->player->pl_x = 0;
	game->player->pl_y = 0;
	game->player->pl_lstep = 0;
	game->player->pl_rstep = 0;
	game->coin->coin_pos = 0;
	game->coin->coin_loop = 0;
	game->exit->exit_pos = 0;
	game->exit->exit_loop = 0;
	game->exit->exit_yes = FALSE;
}
