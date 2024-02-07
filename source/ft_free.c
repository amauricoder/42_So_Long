/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: murilo <murilo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 08:52:12 by aconceic          #+#    #+#             */
/*   Updated: 2024/02/07 13:55:11 by murilo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"


void	free_dp_char(char **dp_char)
{
	int	i;

	i = 0;
	if (!dp_char)
		return ;
	while (dp_char[i])
	{
		free(dp_char[i]);
		i ++;
	}
	free(dp_char);
}

void	free_game_struct(t_game *game)
{
	free_dp_char(game->map->map_skeleton);
	free(game->map);
	free(game->data_mlx->connect);
	free(game->data_mlx->window);
	free(game->data_mlx);
	free(game);
}