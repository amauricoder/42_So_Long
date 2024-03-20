/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_play.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 12:39:09 by aconceic          #+#    #+#             */
/*   Updated: 2024/03/20 14:30:26 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

//Main function for the game
//Handle the event of keypress and animations
//for the main game, I am using mlx_hook() to maintain the keypressed.
//for bonus, mlx_key_hook*()
int	game_play(t_game *game)
{
	t_mlx_data	*conn;
	t_mlx_data	*window;

	conn = game->data_mlx->connect;
	window = game->data_mlx->window;
	mlx_hook(window, KeyPress, KeyPressMask, game_keypressed, game);
	mlx_hook(window, 17, 1L << 17, game_close, game);
	mlx_loop_hook(conn, coin_animation, game);
	return (0);
}

//Update Coin value when player pass by.
void	take_coin(t_game *game, char keypressed)
{
	take_coin_lr(game, keypressed);
	take_coin_du(game, keypressed);
	if (game->map->qt_collect == 0)
	{
		game->exit->exit_yes = TRUE;
		mlx_loop_hook(game->data_mlx->connect, exit_animation, game);
	}
}

void	take_coin_lr(t_game *game, int keypressed)
{
	char		**map_skeleton;
	t_player	*pl;

	pl = game->player;
	map_skeleton = game->map->map_skeleton;
	if (map_skeleton[pl->pl_y][pl->pl_x + 1] == 'C' && keypressed == 'r')
	{
		update_tookcoinvalues(game, pl->pl_y, pl->pl_x + 1);
		pl->pl_x ++;
		render_elmt(game, game->map->img_floor,
			32 * (pl->pl_x - 1), 32 * pl->pl_y);
		render_elmt(game, pl->img_wright2,
			32 * pl->pl_x, 32 * pl->pl_y);
	}
	if (map_skeleton[pl->pl_y][pl->pl_x - 1] == 'C' && keypressed == 'l')
	{
		update_tookcoinvalues(game, pl->pl_y, pl->pl_x - 1);
		pl->pl_x --;
		render_elmt(game, game->map->img_floor,
			32 * (pl->pl_x + 1), 32 * pl->pl_y);
		render_elmt(game, pl->img_wleft2,
			32 * pl->pl_x, 32 * pl->pl_y);
	}
}

void	take_coin_du(t_game *game, int keypressed)
{
	char		**map_skeleton;
	t_player	*pl;

	pl = game->player;
	map_skeleton = game->map->map_skeleton;
	if (map_skeleton[pl->pl_y + 1][pl->pl_x] == 'C' && keypressed == 'd')
	{
		update_tookcoinvalues(game, pl->pl_y + 1, pl->pl_x);
		pl->pl_y ++;
		render_elmt(game, game->map->img_floor,
			32 * pl->pl_x, 32 * (pl->pl_y - 1));
		render_elmt(game, pl->img_wfront,
			32 * pl->pl_x, 32 * pl->pl_y);
	}
	if (map_skeleton[pl->pl_y - 1][pl->pl_x] == 'C' && keypressed == 'u')
	{
		update_tookcoinvalues(game, pl->pl_y - 1, pl->pl_x);
		pl->pl_y --;
		render_elmt(game, game->map->img_floor,
			32 * pl->pl_x, 32 * (pl->pl_y + 1));
		render_elmt(game, pl->img_wback,
			32 * pl->pl_x, 32 * pl->pl_y);
	}
}

void	update_tookcoinvalues(t_game *game, int y, int x)
{
	char	**map;

	map = game->map->map_skeleton;
	map[y][x] = '0';
	game->map->qt_collect --;
	game->qt_mov++;
}
