/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 10:31:56 by aconceic          #+#    #+#             */
/*   Updated: 2024/01/29 17:47:28 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	render_window(void)
{
	t_mlx_data	mlx_data;

	mlx_data.mlx_connection = mlx_init();
	mlx_data.mlx_window = mlx_new_window(mlx_data.mlx_connection, 
			500, 500, "Window");
	mlx_loop(mlx_data.mlx_connection);
}
