/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: murilo <murilo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 09:21:48 by aconceic          #+#    #+#             */
/*   Updated: 2024/03/02 20:19:25 by murilo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

//Check if the ARGV have the .ber at the end and if its a valid file.
//Return 1 if ok, 0 in case dont.
int	ft_check_extention(char *file_name)
{
	int	fd;

	fd = open(file_name, O_RDONLY);
	if (fd < 0)
	{
		close(fd);
		return (0);
	}
	if (ft_strncmp(file_name + ft_strlen(file_name) - 4, ".ber", 4) != 0)
		return (0);
	close(fd);
	return (1);
}

//Similar to ft_strlen()
//Counts the number of char in a string
//Until it reachs one \n or '\0'
//returns an INT with the number of char counted
int	ft_countchar(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
		i ++;
	return (i);
}

//For personalizated error messages
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
		write(2, "Error\nInvalid Map - invalid char on map.\n", 42);
	if (flag == 6)
		write(2, "Error\nMap not closed.\n", 23);
	if (flag == 7)
		write(2, "Error\nNo collectables.\n", 23);
	if (flag == 8)
		write(2, "Error\nOnly 1 Player/Exit.\n", 26);
	if (flag == 9)
		write(2, "Error\nInvalid Map Size\n", 24);
	if (flag == 10)
		write(2, "Error\nError importing map image\n", 33);
	if (flag == 11)
		write(2, "Error\nError Initializing Structs\n", 33);
}

//print the quantity of movements on the screen
void	ft_printmovs(t_game *game)
{
	char		*qt_movs;
	t_mlx_data	*conn;
	t_mlx_data	*wnd;

	qt_movs = ft_itoa(game->qt_mov);
	conn = game->data_mlx->connect;
	wnd = game->data_mlx->window;
	mlx_string_put(conn, wnd, 32, 16, 0xFFFFFF, "Movements");
	if (game->qt_mov >= 0)
	{
		render_elmt(game, game->map->img_wallc, 96, 0);
		mlx_string_put(conn, wnd, 96, 16, 0xFFFFFF, qt_movs);
	}
	free(qt_movs);
}
