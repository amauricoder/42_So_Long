/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: murilo <murilo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 09:21:48 by aconceic          #+#    #+#             */
/*   Updated: 2024/02/07 17:21:21 by murilo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

//Check if the ARGV have the .ber at the end.
//Return 1 if ok, 0 in case dont.
int	ft_check_extention(char *file_name)
{
	int	name_size;

	name_size = ft_strlen(file_name);
	if (name_size <= 4)
		return (0);
	if (ft_strncmp(file_name + ft_strlen(file_name) - 4, ".ber", 4) != 0)
		return (0);
	if (name_size == 5 && file_name[0] == '/')
		return (0);
	
	return (1);
}

//Similar to ft_strlen()
//Counts the number of char in a string
//Until it reachs one \n or '\0'
//returns an INT with the number of char counted
int	ft_countchar(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
		i ++;
	return (i);
}

void	ft_alloc_img(t_game *game)
{
	game->map->img_murr = malloc(sizeof(void *));
	game->map->img_wallbl = malloc(sizeof(void *));
	game->map->img_wallbr = malloc(sizeof(void *));
	game->map->img_wallc = malloc(sizeof(void *));
	game->map->img_walll = malloc(sizeof(void *));
	game->map->img_wallml = malloc(sizeof(void *));
	game->map->img_wallmr = malloc(sizeof(void *));
	game->map->img_wallr = malloc(sizeof(void *));
	game->map->img_wallbc = malloc(sizeof(void *));

	if (!game->map->img_murr || !game->map->img_wallbl || !game->map->img_wallbr
		|| !game->map->img_wallc || !game->map->img_walll || !game->map->img_wallml
		|| !game->map->img_wallmr  || !game->map->img_wallr || !game->map->img_wallbc)
	{
		error_message(10);
		return ;
	}
}