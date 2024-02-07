/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: murilo <murilo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 15:27:56 by aconceic          #+#    #+#             */
/*   Updated: 2024/02/07 16:39:53 by murilo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	game_init(t_game *game)
{
	int height;
	int width;

	height = game->map->qt_lines * 32;
	width = game->map->qt_chars_lines * 32;

	game->data_mlx->connect = mlx_init();
	game->data_mlx->window = mlx_new_window(game->data_mlx->connect, height, width, "So Long");
	game_get_img(game);
}

void	game_get_img(t_game *game)
{
	int	img_h;
	int	img_w;

	img_h = 32;
	img_w = 27;

	ft_alloc_img(game);
	game->map->img_murr = mlx_xpm_file_to_image(game->data_mlx->connect, MURR, &img_h, &img_w);
	game->map->img_wallbl = mlx_xpm_file_to_image(game->data_mlx->connect, WALL_BL, &img_h, &img_w);
	game->map->img_wallbr = mlx_xpm_file_to_image(game->data_mlx->connect, WALL_BR, &img_h, &img_w);
	game->map->img_wallc = mlx_xpm_file_to_image(game->data_mlx->connect, WALL_C, &img_h, &img_w);
	game->map->img_walll = mlx_xpm_file_to_image(game->data_mlx->connect, WALL_L, &img_h, &img_w);
	game->map->img_wallml = mlx_xpm_file_to_image(game->data_mlx->connect, WALL_ML, &img_h, &img_w);
	game->map->img_wallmr = mlx_xpm_file_to_image(game->data_mlx->connect, WALL_MR, &img_h, &img_w);
	game->map->img_wallr = mlx_xpm_file_to_image(game->data_mlx->connect, WALL_R, &img_h, &img_w);
	game->map->img_wallbc = mlx_xpm_file_to_image(game->data_mlx->connect, WALL_BC, &img_h, &img_w);

	//ft_printf("Dont forget to clean this pointerss")
}