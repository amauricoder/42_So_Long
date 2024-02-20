/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 11:45:38 by aconceic          #+#    #+#             */
/*   Updated: 2024/02/20 11:47:34 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	free_exit_imgptr(t_game *game)
{
	t_mlx_data	*connect;
	int			i;

	i = 0;
	connect = game->data_mlx->connect;
	while (i <= 7)
		mlx_destroy_image(connect, game->exit->e_imgs[i++]);
}
