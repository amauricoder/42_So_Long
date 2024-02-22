/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: murilo <murilo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 09:21:48 by aconceic          #+#    #+#             */
/*   Updated: 2024/02/22 10:37:58 by murilo           ###   ########.fr       */
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
void	error_message(int flag)
{
	if (flag == 0)
		write(2, "Error\nInvalid Sintax\n", 22);
	if (flag == 1)
		write(2, "Error\nCouldn't open map file.\n", 30);
	if (flag == 2)
		write(2, "Invalid Map.\n", 14);
	if (flag == 3)
		write(2, "Error\nInvalid Map init.\n", 24);
	if (flag == 4)
		write(2, "Error\nInvalid Map line.\n", 24);
	if (flag == 5)
		write(2, "Error\nInvalid Map - invalid char on map.\n", 38);
	if (flag == 6)
		write(2, "Error\nMap not closed.\n", 23);
	if (flag == 7)
		write(2, "Error\nNo collectables.\n", 23);
	if (flag == 8)
		write(2, "Error\nOnly 1 Player/Exit.\n", 26);
	if (flag == 9)
		write(2, "Error\nInvalid Map Size\n", 18);
	if (flag == 10)
		write(2, "Error\nError importing map image\n", 33);
	if (flag == 11)
		write(2, "Error\nError Initializing Structs\n", 33);
}
