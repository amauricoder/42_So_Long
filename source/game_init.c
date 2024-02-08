/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: murilo <murilo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 15:27:56 by aconceic          #+#    #+#             */
/*   Updated: 2024/02/08 14:00:19 by murilo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	game_init(t_game *game)
{
	int height;
	int width;

	width = (game->map->qt_lines - 1) * 32;
	height = (game->map->qt_chars_lines - 1) * 32;

	ft_printf("MAP WIDTH %i\n", width);
	ft_printf("MAP HEIGHT %i\n", height);
	game->data_mlx->connect = mlx_init();
	game->data_mlx->window = mlx_new_window(game->data_mlx->connect, height, width, "So Long");
	game_get_img(game);
	game_drawmap(game);
}

void	game_get_img(t_game *game)
{
	
	ft_alloc_img(game);
	game->map->img_murr = mlx_xpm_file_to_image(game->data_mlx->connect, MURR, &game->img_h, &game->img_w);
	game->map->img_wallbl = mlx_xpm_file_to_image(game->data_mlx->connect, WALL_BL, &game->img_h, &game->img_w);
	game->map->img_wallbr = mlx_xpm_file_to_image(game->data_mlx->connect, WALL_BR, &game->img_h, &game->img_w);
	game->map->img_wallc = mlx_xpm_file_to_image(game->data_mlx->connect, WALL_C, &game->img_h, &game->img_w);
	game->map->img_walll = mlx_xpm_file_to_image(game->data_mlx->connect, WALL_L, &game->img_h, &game->img_w);
	game->map->img_wallml = mlx_xpm_file_to_image(game->data_mlx->connect, WALL_ML, &game->img_h, &game->img_w);
	game->map->img_wallmr = mlx_xpm_file_to_image(game->data_mlx->connect, WALL_MR, &game->img_h, &game->img_w);
	game->map->img_wallr = mlx_xpm_file_to_image(game->data_mlx->connect, WALL_R, &game->img_h, &game->img_w);
	game->map->img_wallbc = mlx_xpm_file_to_image(game->data_mlx->connect, WALL_BC, &game->img_h, &game->img_w);

	//ft_printf("%s\n", WALL_L);
	if(game->map->img_wallr == NULL)
		ft_printf("IMAGE IS NULL!! AT GAME_GET_IMG\n");
	//ft_printf("Dont forget to clean this pointerss")
}