/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_play_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: murilo <murilo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 12:39:09 by murilo            #+#    #+#             */
/*   Updated: 2024/03/02 20:13:30 by murilo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

//handle events of minilibx
//functions to the gameplay of the bonus inside
int	game_play_bonus(t_gmbonus *bonus)
{
	t_mlx_data	*conn;
	t_mlx_data	*window;
	t_game		*game;

	game = bonus->game_main;
	conn = game->data_mlx->connect;
	window = game->data_mlx->window;
	mlx_key_hook(window, game_keypressed_bonus, bonus);
	mlx_hook(window, 17, 1L << 17, game_close_bonus, game);
	mlx_loop_hook(conn, coin_animation_bonus, bonus);
	return (0);
}

//do the events of the game when specific keys are pressed
int	game_keypressed_bonus(int keypressed, t_gmbonus *bonus)
{
	t_game	*game;

	game = bonus->game_main;
	if (keypressed == KB_ESC)
		game_close_bonus(bonus);
	p1_keypressed(bonus, keypressed);
	p2_keypressed(bonus, keypressed);
	if (game->exit->exit_x == game->player->pl_x
		&& game->exit->exit_y == game->player->pl_y
		&& game->exit->exit_yes == TRUE && game->player->pl_isonexit == FALSE)
	{
		game->player->pl_isonexit = TRUE;
		render_message(bonus, 1);
	}
	else if (game->player->pl_isonexit == FALSE)
		ft_printmovs(game);
	return (0);
}

//Handle with events for keys W, S, A, D
//For the moviments of main character
int	p1_keypressed(t_gmbonus *bonus, int keypressed)
{
	t_game	*game;

	game = bonus->game_main;
	if (keypressed == KB_W && game->player->pl_isonexit == FALSE)
		key_up_pressed(game);
	else if (keypressed == KB_S && game->player->pl_isonexit == FALSE)
		key_down_pressed(game);
	else if (keypressed == KB_A && game->player->pl_isonexit == FALSE)
		key_left_pressed(game);
	else if (keypressed == KB_D && game->player->pl_isonexit == FALSE)
		key_right_pressed(game);
	if (bonus->ht_x == bonus->game_main->player->pl_x
		&& bonus->ht_y == bonus->game_main->player->pl_y
		&& game->player->pl_isonexit == FALSE)
	{
		game->player->pl_isonexit = TRUE;
		render_message(bonus, 2);
	}
	return (0);
}

//Handle with events for keys ARROWS UP, LEFT, DOWN, RIGHT
//For the moviments of main character
int	p2_keypressed(t_gmbonus *bonus, int keypressed)
{
	t_game	*game;
	char	**map;

	game = bonus->game_main;
	map = game->map->map_skeleton;
	if (keypressed == KB_UP
		&& game->player->pl_isonexit == FALSE)
		p2key_up_pressed(bonus, game, map);
	else if (keypressed == KB_DOWN
		&& game->player->pl_isonexit == FALSE)
		p2key_down_pressed(bonus, game, map);
	else if (keypressed == KB_LEFT
		&& game->player->pl_isonexit == FALSE)
		p2key_left_pressed(bonus, game, map);
	else if (keypressed == KB_RIGHT
		&& game->player->pl_isonexit == FALSE)
		p2key_right_pressed(bonus, game, map);
	if (bonus->ht_x == bonus->game_main->player->pl_x
		&& bonus->ht_y == bonus->game_main->player->pl_y
		&& game->player->pl_isonexit == FALSE)
	{
		game->player->pl_isonexit = TRUE;
		render_message(bonus, 2);
	}
	return (0);
}

void	render_message(t_gmbonus *bonus, int flag)
{
	t_game *game;

	game = bonus->game_main;
	if (flag == 1)
	{
		render_elmt(game, game->map->img_wallc, 32, 0);
		render_elmt(game, game->map->img_wallc, 64, 0);
		render_elmt(game, game->map->img_wallc, 96, 0);
		mlx_string_put(game->data_mlx->connect, 
			game->data_mlx->window, 32, 16, 0xFFFFFF, "Player 1 Victory");
	}
	if (flag == 2)
	{
		render_elmt(game, game->map->img_wallc, 32, 0);
		render_elmt(game, game->map->img_wallc, 64, 0);
		render_elmt(game, game->map->img_wallc, 96, 0);
		mlx_string_put(game->data_mlx->connect, 
			game->data_mlx->window, 32, 16, 0xFFFFFF, "Player 1 has died");
	}
}
