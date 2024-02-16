/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_commands.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: murilo <murilo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 12:39:09 by murilo            #+#    #+#             */
/*   Updated: 2024/02/16 20:21:05 by murilo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"


int	game_commands(t_game *game)
{
	t_mlx_data *conn;
	t_mlx_data *window;

	conn = game->data_mlx->connect;
	window = game->data_mlx->window;
    mlx_key_hook(window, game_keypressed, game);
	mlx_hook(window, 17, 1L << 17, game_close, game);
	mlx_loop_hook(conn, coin_animation, game);
    return (0);
}

int	game_keypressed(int keypressed, t_game *game)
{
	if (keypressed == KB_ESC)
        game_close(game);
	if (keypressed == KB_W || keypressed == KB_UP)
		key_up_pressed(game);
	if (keypressed == KB_S || keypressed == KB_DOWN)
		key_down_pressed(game);
	if (keypressed == KB_A || keypressed == KB_LEFT)
		key_left_pressed(game);
	if (keypressed == KB_D || keypressed == KB_RIGHT)
		key_right_pressed(game);
	ft_printf("Key pressed number game_keypressed() %i\n", keypressed);
	return (0);
}
//Function to make the player go up one
//W and UP Arrow are up keys.
//-1 is for render player on the y -1 position of map
void	key_up_pressed(t_game *game)
{
	t_player *pl;
	t_map *mp;
	char **map_skeleton;

	pl = game->player;
	mp = game->map;
	map_skeleton = game->map->map_skeleton;
	if (map_skeleton[pl->pl_y - 1][pl->pl_x] != '1')
	{
		game->player->pl_y --;
		render_elmt(game, mp->img_floor, 32 * pl->pl_x, 32 * (pl->pl_y + 1));
		render_elmt(game, pl->img_sback, 32 * pl->pl_x, 32 * pl->pl_y);
	}
}
//Function to make the player go down one
//S and DOWN Arrow are up keys.
void	key_down_pressed(t_game *game)
{
	t_player *pl;
	t_map *mp;
	char **map_skeleton;

	pl = game->player;
	mp = game->map;
	map_skeleton = game->map->map_skeleton;
	if (map_skeleton[pl->pl_y + 1][pl->pl_x] != '1')
	{
		game->player->pl_y ++;
		render_elmt(game, mp->img_floor, 32 * pl->pl_x, 32 * (pl->pl_y - 1));
		render_elmt(game, pl->img_sfront, 32 * pl->pl_x, 32 * pl->pl_y);
	}
}

//Function to make the player go left one
//A and LEFT Arrow are left keys.
void	key_left_pressed(t_game *game)
{
	t_player *pl;
	t_map *mp;
	char **map_skeleton;

	pl = game->player;
	mp = game->map;
	map_skeleton = game->map->map_skeleton;
	if (map_skeleton[pl->pl_y][pl->pl_x - 1] != '1')
	{
		game->player->pl_x --;
		render_elmt(game, mp->img_floor, 32 * (pl->pl_x + 1), 32 * pl->pl_y);
		render_elmt(game, pl->img_sleft, 32 * pl->pl_x, 32 * pl->pl_y);
	}
}

//Function to make the player go left one
//A and LEFT Arrow are left keys.
void	key_right_pressed(t_game *game)
{
	t_player *pl;
	t_map *mp;
	char **map_skeleton;

	pl = game->player;
	mp = game->map;
	map_skeleton = game->map->map_skeleton;
	if (map_skeleton[pl->pl_y][pl->pl_x + 1] != '1')
	{
		game->player->pl_x ++;
		render_elmt(game, mp->img_floor, 32 * (pl->pl_x - 1), 32 * pl->pl_y);
		render_elmt(game, pl->img_sright, 32 * pl->pl_x, 32 * pl->pl_y);
	}
}