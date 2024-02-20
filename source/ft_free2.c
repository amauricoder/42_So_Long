/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: murilo <murilo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 11:45:38 by aconceic          #+#    #+#             */
/*   Updated: 2024/02/20 18:21:00 by murilo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	free_exit_imgptr(t_game *game)
{
	t_mlx_data	*connect;
	int			i;

	i = 0;
	connect = game->data_mlx->connect;
	while (i <= 9)
		mlx_destroy_image(connect, game->exit->e_imgs[i++]);
}
