/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 11:08:21 by aconceic          #+#    #+#             */
/*   Updated: 2024/01/31 17:41:56 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int main(int argc, char **argv)
{
	t_map 		*map;
	t_mlx_data 	*render;

	if (argc == 2 && ft_check_extention(argv[1]) == 1)
	{
		map = map_init(argv[1]);
		render = NULL;
		if (map_valid_allrequisites(map))
		{
			//Here I need to start and render the images as well
			render = game_init(render, map);
			//Here I need to hook.
			mlx_loop(render->connect);
			//ft_printf("dont forget to clean the render");
		}
		free_map_struct(map);
		free(render);
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
		write(2, "Error\nCouldn't open map file.\n", 29);
	if (flag == 2)
		write(2, "Error\nInvalid Map.\n", 19);
	if (flag == 3)
		write(2, "Error\nInvalid Map init.\n", 24);
	if (flag == 4)
		write(2, "Error\nInvalid Map line.\n", 24);
	if (flag == 5)
		write(2, "Error\nInvalid Map - invalid char on map.\n", 41);
	if (flag == 6)
		write(2, "Error\nInvalid Map - Map not closed.\n", 37);
	if (flag == 7)
		write(2, "Error\nInvalid Map - No collectables.\n", 37);
	if (flag == 8)
		write(2, "Error\nInvalid Map - Only 1 Player/Exit.\n", 41);
	if (flag == 9)
		write(2, "Error\nInvalid Map - Invalid Map Size\n", 41);
}
