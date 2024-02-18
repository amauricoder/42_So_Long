/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_render.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: murilo <murilo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 09:43:32 by murilo            #+#    #+#             */
/*   Updated: 2024/02/18 18:22:32 by murilo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

//Render the elements tiles
void	render_elmt(t_game *game, void *img, int width, int height)
{
	t_mlx_data *conn;
	t_mlx_data *wnd;
	
	conn = game->data_mlx->connect;
	wnd = game->data_mlx->window;
	mlx_put_image_to_window(conn, wnd, img, width, height);
}

//render the element coin according to the position
//coint is separate from general render_elements() because
//it has animation
void	render_coin(t_game *game, int width, int height)
{
	t_mlx_data 	*conn;
	t_mlx_data 	*wnd;
	t_coin		*gc;
	int			coin_value;

	conn = game->data_mlx->connect;
	wnd = game->data_mlx->window;
	coin_value = game->coin->coin_pos;
	gc = game->coin;
	if (coin_value >= 6 || coin_value <= 0)
        coin_value = 0;
	if (coin_value == 0)
		mlx_put_image_to_window(conn, wnd, gc->c_imgs[0], width, height);
	if (coin_value == 1)
		mlx_put_image_to_window(conn, wnd, gc->c_imgs[1], width, height);
	if (coin_value == 2)
		mlx_put_image_to_window(conn, wnd, gc->c_imgs[2], width, height);
	if (coin_value == 3)
		mlx_put_image_to_window(conn, wnd, gc->c_imgs[3], width, height);
	if (coin_value == 4)
		mlx_put_image_to_window(conn, wnd, gc->c_imgs[4], width, height);		
	if (coin_value == 5)
		mlx_put_image_to_window(conn, wnd, gc->c_imgs[5], width, height);
}

void	render_exit(t_game *game, int width, int height)
{
	t_mlx_data 	*conn;
	t_mlx_data 	*wnd;
	t_exit		*ge;
	int			exit_value;
	
	conn = game->data_mlx->connect;
	wnd = game->data_mlx->window;
	ge = game->exit;
	exit_value = game->exit->exit_pos;
	if (exit_value > 5)
        exit_value = 0;
	//ft_printf("EXIT VALUE render_exit() %i\n", exit_value);
	if (ge->exit_yes == FALSE)
		mlx_put_image_to_window(conn, wnd, game->map->img_floor, width, height);
	if (exit_value == 0 && ge->exit_yes == TRUE)
		mlx_put_image_to_window(conn, wnd, ge->e_imgs[5], width, height);
	if (exit_value == 1 && ge->exit_yes == TRUE)
		mlx_put_image_to_window(conn, wnd, ge->e_imgs[6], width, height);
	if (exit_value == 2 && ge->exit_yes == TRUE)
		mlx_put_image_to_window(conn, wnd, ge->e_imgs[5], width, height);
	if (exit_value == 3 && ge->exit_yes == TRUE)
		mlx_put_image_to_window(conn, wnd, ge->e_imgs[7], width, height);
	if (exit_value == 4 && ge->exit_yes == TRUE)
		mlx_put_image_to_window(conn, wnd, ge->e_imgs[5], width, height);
	if (exit_value == 5 && ge->exit_yes == TRUE)
		mlx_put_image_to_window(conn, wnd, ge->e_imgs[6], width, height);
}

