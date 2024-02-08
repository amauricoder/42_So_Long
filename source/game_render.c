/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_render.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: murilo <murilo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 09:43:32 by murilo            #+#    #+#             */
/*   Updated: 2024/02/08 14:16:07 by murilo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int game_drawmap(t_game *game)
{
    ft_printf("Entrou em game_drawmap\n");
    //int x;
    //int y;
    //charlines = width
    //lines = heig
    
    char **map_skeleton;
    int render_width;
    int render_height;
    int qt_tiles_height;
    int qt_tiles_width;
    
    render_height = (game->map->qt_lines - 2) * 32;
    render_width = (game->map->qt_chars_lines - 2) * 32;
    qt_tiles_height = game->map->qt_lines - 1;
    qt_tiles_width = game->map->qt_chars_lines - 1;
    
    ft_printf("VALOR RENDER HEIGHT %i \n", render_height);
    ft_printf("VALOR RENDER WIDTH %i \n", render_width);
    ft_printf("QT TILES HEIGHT %i\n", qt_tiles_height);
    ft_printf("QT TILES WIDTH %i\n", qt_tiles_width);
    
    map_skeleton = game->map->map_skeleton;
    //ft_printf("VALOR QT_TILES %i\n", qt_tiles);
    if(map_skeleton[0][0] == '1')
        mlx_put_image_to_window(game->data_mlx->connect, game->data_mlx->window, game->map->img_walll, 0, 0);
    if (map_skeleton[0][qt_tiles_width] == '1')
        mlx_put_image_to_window(game->data_mlx->connect, game->data_mlx->window, game->map->img_wallr, render_width, 0);   
    if (map_skeleton[qt_tiles_height][0] == '1')
       mlx_put_image_to_window(game->data_mlx->connect, game->data_mlx->window, game->map->img_wallbl, 0, render_height);
    if (map_skeleton[qt_tiles_height][qt_tiles_width] == '1')
       mlx_put_image_to_window(game->data_mlx->connect, game->data_mlx->window, game->map->img_wallbr, render_width, render_height);
    return (0);
}