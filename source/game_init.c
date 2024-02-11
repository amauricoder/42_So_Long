/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: murilo <murilo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 15:27:56 by aconceic          #+#    #+#             */
/*   Updated: 2024/02/11 16:01:51 by murilo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	game_init(t_game *game)
{
	int window_height;
	int window_width;

	window_height = (game->map->qt_lines) * 32;
	window_width = (game->map->qt_chars_lines) * 32;
	game = game_structs_init(game);
	game->data_mlx->connect = mlx_init();
	game->data_mlx->window = mlx_new_window(game->data_mlx->connect, window_width, window_height, "So Long");
	game_get_mapimg(game);
	game_drawmap(game);
}
//Initialize the structures for the game
//except for the main struct and the map struct.
//Return the main struct with the structures inside initialized
t_game	*game_structs_init(t_game *game)
{
	t_mlx_data *data_mlx;

	data_mlx = malloc(sizeof(t_mlx_data));
	if (!data_mlx)
	{
		error_message(11);
		return (NULL);
	}
	game->data_mlx = data_mlx;
	return (game);
}
void	game_get_mapimg(t_game *game)
{
	game->map->img_floor = mlx_xpm_file_to_image(game->data_mlx->connect, FLOOR, &game->img_h, &game->img_w);
	game->map->img_murr = mlx_xpm_file_to_image(game->data_mlx->connect, MURR, &game->img_h, &game->img_w);
	game->map->img_wallbl = mlx_xpm_file_to_image(game->data_mlx->connect, WALL_BL, &game->img_h, &game->img_w);
	game->map->img_wallbr = mlx_xpm_file_to_image(game->data_mlx->connect, WALL_BR, &game->img_h, &game->img_w);
	game->map->img_wallc = mlx_xpm_file_to_image(game->data_mlx->connect, WALL_C, &game->img_h, &game->img_w);
	game->map->img_walll = mlx_xpm_file_to_image(game->data_mlx->connect, WALL_L, &game->img_h, &game->img_w);
	game->map->img_wallml = mlx_xpm_file_to_image(game->data_mlx->connect, WALL_ML, &game->img_h, &game->img_w);
	game->map->img_wallmr = mlx_xpm_file_to_image(game->data_mlx->connect, WALL_MR, &game->img_h, &game->img_w);
	game->map->img_wallr = mlx_xpm_file_to_image(game->data_mlx->connect, WALL_R, &game->img_h, &game->img_w);
	game->map->img_wallbc = mlx_xpm_file_to_image(game->data_mlx->connect, WALL_BC, &game->img_h, &game->img_w);
	if(game->map->img_floor == NULL || game->map->img_murr == NULL || game->map->img_wallbl == NULL ||
		game->map->img_wallbr == NULL || game->map->img_wallc == NULL || game->map->img_walll == NULL ||
		game->map->img_wallml == NULL || game->map->img_wallmr == NULL || game->map->img_wallr == NULL
		|| game->map->img_wallbc == NULL)
		ft_printf("ERROR IN SOME IMAGE!!! SOME IMAGE IS NULL!! AT GAME_GET_IMG\n");
}