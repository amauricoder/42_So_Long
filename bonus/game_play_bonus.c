/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_play_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: murilo <murilo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 12:39:09 by murilo            #+#    #+#             */
/*   Updated: 2024/02/23 19:40:51 by murilo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

int	game_play_bonus(t_enemy *bonus)
{
	ft_printf("gameplay bonus\n");
	t_mlx_data	*conn;
	t_mlx_data	*window;
	t_game		*game;

	game = bonus->bonus;
	conn = game->data_mlx->connect;
	window = game->data_mlx->window;
	mlx_key_hook(window, game_keypressed_bonus, bonus);
	mlx_hook(window, 17, 1L << 17, game_close, game);
	mlx_loop_hook(conn, coin_animation, game);
	return (0);
}
int	game_keypressed_bonus(int keypressed, t_enemy *bonus)
{
	t_game *game;

	game = bonus->bonus;
	if (keypressed == KB_ESC)
		game_close(game);
	p1_keypressed(bonus, keypressed);
	p2_keypressed(bonus, keypressed);
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

int	p1_keypressed(t_enemy *bonus, int keypressed)
{
	t_game *game;

	game = bonus->bonus;
	if (keypressed == KB_W)
		key_up_pressed(game);
	else if (keypressed == KB_S)
		key_down_pressed(game);
	else if (keypressed == KB_A)
		key_left_pressed(game);
	else if (keypressed == KB_D)
		key_right_pressed(game);

	if (bonus->ht_x == bonus->bonus->player->pl_x
	&& bonus->ht_y == bonus->bonus->player->pl_y)
	{
		ft_printf("TOUCH ME BABY\n");
	}
	return (0);
}

int	p2_keypressed(t_enemy *bonus, int keypressed)
{
	t_game *game;
	char **map;

	game = bonus->bonus;
	map = game->map->map_skeleton;

	if (keypressed == KB_UP)
		p2key_up_pressed(bonus, game, map);
	else if (keypressed == KB_DOWN)
		p2key_down_pressed(bonus, game, map);
	else if (keypressed == KB_LEFT)
		p2key_left_pressed(bonus, game, map);
	else if (keypressed == KB_RIGHT)
		p2key_right_pressed(bonus, game, map);
	
	if (bonus->ht_x == bonus->bonus->player->pl_x
	&& bonus->ht_y == bonus->bonus->player->pl_y)
	{
		ft_printf("TOUCH ME BABY\n");
	}
	return (0);
}