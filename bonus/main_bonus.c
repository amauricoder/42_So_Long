/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: murilo <murilo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 10:09:42 by murilo            #+#    #+#             */
/*   Updated: 2024/02/24 12:13:30 by murilo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

int	main(int argc, char **argv)
{
    ft_printf("ESTAMOS NO BONUS!\n");
	t_game	*game;
	t_enemy *bonus;
	
	if (argc == 2 && ft_check_extention(argv[1]) == 1)
	{
		game = map_init(argv[1]);
		if (map_valid_allrequisites(game->map, argv[1]))
		{
			bonus = game_init_bonus(game);
			game_play_bonus(bonus);
			mlx_loop(game->data_mlx->connect);
		}
		free_dp_char(game->map->map_skeleton);
		free(game->map);
		free(game);
	}
	else
		error_message(1);
	return (0);
}
