/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: murilo <murilo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 19:30:48 by murilo            #+#    #+#             */
/*   Updated: 2024/02/27 16:20:02 by murilo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

int	coin_animation_bonus(t_gmbonus *bonus)
{
	t_game	*game;

	game = bonus->game_main; 
	if (game->coin->coin_loop < 1000)
	{
		game->coin->coin_loop++;
		return (0);
	}
	game->coin->coin_loop = 0;
	if (game->coin->coin_pos >= 6 || game->coin->coin_pos <= 0)
		game->coin->coin_pos = 0;
	draw_enemy_isoncoin(bonus);
	draw_mapcoins_bonus(bonus);
	game->coin->coin_pos++;
	return (0);
}

void	draw_mapcoins_bonus(t_gmbonus *bonus)
{
	t_game	*game;
	int		qt_chars;
	int		i;
	int		j;

	game = bonus->game_main;
	qt_chars = game->map->qt_chars_lines - 1;
	i = 0;
	while (game->map->map_skeleton[++i])
	{
		j = 0;
		while (game->map->map_skeleton[i][++j] != '\0'
			&& i < game->map->qt_lines - 1)
		{
			if (game->map->map_skeleton[i][j] == 'C' && j < qt_chars)
				render_coin(game, 32 * j, 32 * i);
		}
	}
}

void	draw_enemy_isoncoin(t_gmbonus *bonus)
{
	t_game	*game;

	game = bonus->game_main;
	if (game->map->map_skeleton[bonus->ht_y][bonus->ht_x] == 'C')
	{
		game->map->map_skeleton[bonus->ht_y][bonus->ht_x] = 'H';
		bonus->hpos_x = bonus->ht_x;
		bonus->hpos_y = bonus->ht_y;
		bonus->chprevious = 'C';
	}
	turnh_toc(bonus);
}

void	turnh_toc(t_gmbonus *bonus)
{
	char	**map;

	map = bonus->game_main->map->map_skeleton;
	if (map[bonus->ht_y][bonus->ht_x - 1] == 'H')
		map[bonus->ht_y][bonus->ht_x - 1] = 'C';
	if (map[bonus->ht_y][bonus->ht_x + 1] == 'H')
		map[bonus->ht_y][bonus->ht_x + 1] = 'C';
	if (map[bonus->ht_y - 1][bonus->ht_x] == 'H')
		map[bonus->ht_y - 1][bonus->ht_x] = 'C';
	if (map[bonus->ht_y + 1][bonus->ht_x] == 'H')
		map[bonus->ht_y + 1][bonus->ht_x] = 'C';
}
