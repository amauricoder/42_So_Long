/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 10:27:46 by aconceic          #+#    #+#             */
/*   Updated: 2024/02/04 13:44:02 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	game_keypress(int keypressed, t_mlx_data *render)
{
	if (keypressed == KB_ESC)
	{
		mlx_destroy_window(render->connect, render->window);
		mlx_destroy_display(render->connect);
		free(render);
		exit(0);
	}
	ft_printf("Key pressed number %i\n", keypressed);
	return (0);
}