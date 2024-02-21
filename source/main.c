/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: murilo <murilo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 11:08:21 by aconceic          #+#    #+#             */
/*   Updated: 2024/02/21 18:32:31 by murilo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	main(int argc, char **argv)
{
	t_game	*game;

	if (argc == 2 && ft_check_extention(argv[1]) == 1)
	{
		game = map_init(argv[1]);
		if (map_valid_allrequisites(game->map))
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

void	error_message(int flag)
{
	if (flag == 0)
		write(2, "Error\nInvalid Sintax\n", 22);
	if (flag == 1)
		write(2, "Error\nCouldn't open map file.\n", 30);
	if (flag == 2)
		write(2, "Error\nInvalid Map.\n", 19);
	if (flag == 3)
		write(2, "Error\nInvalid Map init.\n", 24);
	if (flag == 4)
		write(2, "Error\nInvalid Map line.\n", 24);
	if (flag == 5)
		write(2, "Error\nInvalid Map - invalid char on map.\n", 38);
	if (flag == 6)
		write(2, "Map not closed.\n", 17);
	if (flag == 7)
		write(2, "No collectables.\n", 18);
	if (flag == 8)
		write(2, "Only 1 Player/Exit.\n", 21);
	if (flag == 9)
		write(2, "Invalid Map Size\n", 18);
	if (flag == 10)
		write(2, "Error\nError importing map image\n", 33);
	if (flag == 11)
		write(2, "Error\nError Initializing Structs\n", 33);
}
