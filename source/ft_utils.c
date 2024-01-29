/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 09:21:48 by aconceic          #+#    #+#             */
/*   Updated: 2024/01/29 17:45:56 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	ft_check_extention(char *file_name)
{
	if (ft_strncmp(file_name + ft_strlen(file_name) - 4, ".ber", 4) != 0)
		return (-1);
	return (1);
}

void	ft_free_dp_char(char **dp_char)
{
	int	i;

	i = 0;
	if (!dp_char)
		return ;
	while (dp_char[i])
	{
		ft_printf("%s", dp_char[i]);
		free(dp_char[i]);
		i ++;
	}
	free(dp_char);
}
