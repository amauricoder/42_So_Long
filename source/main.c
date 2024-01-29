/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 11:08:21 by aconceic          #+#    #+#             */
/*   Updated: 2024/01/29 17:50:14 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int main(int argc, char **argv)
{
	//check input
	//if input is valid
		//run game
	//else
		//error and stop
	char **test;

	if (argc == 2 && ft_check_extention(argv[1]) == 1)
	{
		test = map_read(argv[1]);
		ft_free_dp_char(test);
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
}