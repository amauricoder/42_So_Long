/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 11:08:21 by aconceic          #+#    #+#             */
/*   Updated: 2024/08/19 10:54:34 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	main(int argc, char **argv)
{
	t_game	*game;

	if (argc == 2 && ft_check_extention(argv[1]) == 1)
	{
		game = map_init(argv[1]);
		if (map_valid_allrequisites(game->map, argv[1]))
		{
			game_init_master(game);
			game_play(game);
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
