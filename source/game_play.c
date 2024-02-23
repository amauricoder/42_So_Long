/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_play.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: murilo <murilo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 12:39:09 by murilo            #+#    #+#             */
/*   Updated: 2024/02/23 19:21:42 by murilo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	game_play(t_game *game)
{
	t_mlx_data	*conn;
	t_mlx_data	*window;

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
	else if (keypressed == KB_W || keypressed == KB_UP)
		key_up_pressed(game);
	else if (keypressed == KB_S || keypressed == KB_DOWN)
		key_down_pressed(game);
	else if (keypressed == KB_A || keypressed == KB_LEFT)
		key_left_pressed(game);
	else if (keypressed == KB_D || keypressed == KB_RIGHT)
		key_right_pressed(game);
	if (game->exit->exit_x == game->player->pl_x 
		&& game->exit->exit_y == game->player->pl_y
		&& game->exit->exit_yes == TRUE)
	{
		//mlx_clear_window(game->data_mlx->connect, game->data_mlx->window);
		//mlx_string_put(game->data_mlx->connect, game->data_mlx->window, 32, 16, 0xFFFFFF, "YOU WIN!!");
		//AQUI eu preciso fazer com que uma imagem vencedora apareca e nao feche a janela
		ft_printf("YOU WIN\n");
		game_close(game);
	}
	ft_printf("Quantity of moves %i\n", game->qt_mov);
	ft_printmovs(game);
	return (0);
}

void	ft_printmovs(t_game *game)
{
	char		*qt_movs;
	t_mlx_data	*conn;
	t_mlx_data	*wnd;

	qt_movs = ft_itoa(game->qt_mov);
	conn = game->data_mlx->connect;
	wnd = game->data_mlx->window;
	mlx_string_put(conn, wnd, 32, 16, 0xFFFFFF, "Moviments");
	if (game->qt_mov >= 0)
	{
		render_elmt(game, game->map->img_wallc, 96, 0);
		mlx_string_put(conn, wnd, 96, 16, 0xFFFFFF, qt_movs);
	}
	free(qt_movs);
}

//Make the player go up one tile.
//W and UP Arrow are up keys.
//Magic -1 is for render player on the y -1 position of map
void	key_up_pressed(t_game *game)
{
	t_player	*pl;
	t_map		*mp;
	char		**map_sk;

	pl = game->player;
	mp = game->map;
	map_sk = game->map->map_skeleton;
	if (map_sk[pl->pl_y - 1][pl->pl_x] == 'C')
		take_coin(game, 'u');
	else if (map_sk[pl->pl_y - 1][pl->pl_x] != '1' && pl->pl_lstep == FALSE)
	{
		game->player->pl_y --;
		render_elmt(game, mp->img_floor, 32 * pl->pl_x, 32 * (pl->pl_y + 1));
		render_elmt(game, pl->img_wback, 32 * pl->pl_x, 32 * pl->pl_y);
		pl->pl_lstep = TRUE;
		game->qt_mov++;
	}
	else if (map_sk[pl->pl_y - 1][pl->pl_x] != '1' && pl->pl_lstep == TRUE)
	{
		game->player->pl_y --;
		render_elmt(game, mp->img_floor, 32 * pl->pl_x, 32 * (pl->pl_y + 1));
		render_elmt(game, pl->img_wback2, 32 * pl->pl_x, 32 * pl->pl_y);
		pl->pl_lstep = FALSE;
		game->qt_mov++;
	}
}

//Function to make the player go down one
//S and DOWN Arrow are up keys.
void	key_down_pressed(t_game *game)
{
	t_player	*pl;
	t_map		*mp;
	char		**map_sk;

	pl = game->player;
	mp = game->map;
	map_sk = game->map->map_skeleton;
	if (map_sk[pl->pl_y + 1][pl->pl_x] == 'C')
		take_coin(game, 'd');
	else if (map_sk[pl->pl_y + 1][pl->pl_x] != '1' && pl->pl_lstep == FALSE)
	{
		game->player->pl_y ++;
		render_elmt(game, mp->img_floor, 32 * pl->pl_x, 32 * (pl->pl_y - 1));
		render_elmt(game, pl->img_wfront, 32 * pl->pl_x, 32 * pl->pl_y);
		pl->pl_lstep = TRUE;
		game->qt_mov++;
	}
	else if (map_sk[pl->pl_y + 1][pl->pl_x] != '1' && pl->pl_lstep == TRUE)
	{
		game->player->pl_y ++;
		render_elmt(game, mp->img_floor, 32 * pl->pl_x, 32 * (pl->pl_y - 1));
		render_elmt(game, pl->img_wfront2, 32 * pl->pl_x, 32 * pl->pl_y);
		pl->pl_lstep = FALSE;
		game->qt_mov++;
	}
}

//Function to make the player go left one
//A and LEFT Arrow are left keys.
void	key_left_pressed(t_game *game)
{
	t_player	*pl;
	t_map		*mp;
	char		**map_sk;

	pl = game->player;
	mp = game->map;
	map_sk = game->map->map_skeleton;
	if (map_sk[pl->pl_y][pl->pl_x - 1] == 'C')
		take_coin(game, 'l');
	else if (map_sk[pl->pl_y][pl->pl_x - 1] != '1' && pl->pl_lstep == FALSE)
	{
		game->player->pl_x --;
		render_elmt(game, mp->img_floor, 32 * (pl->pl_x + 1), 32 * pl->pl_y);
		render_elmt(game, pl->img_wleft, 32 * pl->pl_x, 32 * pl->pl_y);
		pl->pl_lstep = TRUE;
		game->qt_mov++;
	}
	else if (map_sk[pl->pl_y][pl->pl_x - 1] != '1' && pl->pl_lstep == TRUE)
	{
		game->player->pl_x --;
		render_elmt(game, mp->img_floor, 32 * (pl->pl_x + 1), 32 * pl->pl_y);
		render_elmt(game, pl->img_wleft2, 32 * pl->pl_x, 32 * pl->pl_y);
		pl->pl_lstep = FALSE;
		game->qt_mov++;
	}
}

//Function to make the player go right one
//S and RIGHT_ARROW are right keys.
void	key_right_pressed(t_game *game)
{
	t_player	*pl;
	t_map		*mp;
	char		**map_sk;

	pl = game->player;
	mp = game->map;
	map_sk = game->map->map_skeleton;
	if (map_sk[pl->pl_y][pl->pl_x + 1] == 'C')
		take_coin(game, 'r');
	else if (map_sk[pl->pl_y][pl->pl_x + 1] != '1' && pl->pl_lstep == FALSE)
	{
		game->player->pl_x ++;
		render_elmt(game, mp->img_floor, 32 * (pl->pl_x - 1), 32 * pl->pl_y);
		render_elmt(game, pl->img_wright, 32 * pl->pl_x, 32 * pl->pl_y);
		pl->pl_lstep = TRUE;
		game->qt_mov++;
	}
	else if (map_sk[pl->pl_y][pl->pl_x + 1] != '1' && pl->pl_lstep == TRUE)
	{
		game->player->pl_x ++;
		render_elmt(game, mp->img_floor, 32 * (pl->pl_x - 1), 32 * pl->pl_y);
		render_elmt(game, pl->img_wright2, 32 * pl->pl_x, 32 * pl->pl_y);
		pl->pl_lstep = FALSE;
		game->qt_mov++;
	}
}

//Update Coin value when player pass by.
void	take_coin(t_game *game, char keypressed)
{
	char		**map_skeleton;
	t_player	*pl;

	pl = game->player;
	map_skeleton = game->map->map_skeleton;
	if (map_skeleton[pl->pl_y][pl->pl_x + 1] == 'C' && keypressed == 'r')
	{
		map_skeleton[pl->pl_y][pl->pl_x + 1] = '0';
		game->map->qt_collect --;
		pl->pl_x ++;
		render_elmt(game, game->map->img_floor, 32 * (pl->pl_x - 1), 32 * pl->pl_y);
		render_elmt(game, pl->img_wright2, 32 * pl->pl_x, 32 * pl->pl_y);
		game->qt_mov++;
	}
	if (map_skeleton[pl->pl_y][pl->pl_x - 1] == 'C' && keypressed == 'l')
	{
		map_skeleton[pl->pl_y][pl->pl_x - 1] = '0';
		game->map->qt_collect --;
		pl->pl_x --;
		render_elmt(game, game->map->img_floor, 32 * (pl->pl_x + 1), 32 * pl->pl_y);
		render_elmt(game, pl->img_wleft2, 32 * pl->pl_x, 32 * pl->pl_y);
		game->qt_mov++;
	}
	if (map_skeleton[pl->pl_y + 1][pl->pl_x] == 'C' && keypressed == 'd')
	{
		map_skeleton[pl->pl_y + 1][pl->pl_x] = '0';
		game->map->qt_collect --;
		pl->pl_y ++;
		render_elmt(game, game->map->img_floor, 32 * pl->pl_x, 32 * (pl->pl_y - 1));
		render_elmt(game, pl->img_wfront, 32 * pl->pl_x, 32 * pl->pl_y);
		game->qt_mov++;
	}
	if (map_skeleton[pl->pl_y - 1][pl->pl_x] == 'C' && keypressed == 'u')
	{
		map_skeleton[pl->pl_y - 1][pl->pl_x] = '0';
		game->map->qt_collect --;
		pl->pl_y --;
		render_elmt(game, game->map->img_floor, 32 * pl->pl_x, 32 * (pl->pl_y + 1));
		render_elmt(game, pl->img_wback, 32 * pl->pl_x, 32 * pl->pl_y);
		game->qt_mov++;
	}

	if (game->map->qt_collect == 0)
	{
		game->exit->exit_yes = TRUE;
		mlx_loop_hook(game->data_mlx->connect, exit_animation, game);
	}
}
