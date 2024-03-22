/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 15:03:48 by aconceic          #+#    #+#             */
/*   Updated: 2024/03/20 15:56:47 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int		signal;
	int		number;

	signal = 1;
	number = 0;
	while (*nptr == 32 || (*nptr >= 9 && *nptr <= 13))
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			signal = -1;
		nptr ++;
	}
	while (*nptr >= 48 && *nptr <= 57)
	{
		number *= 10;
		number += *nptr - 48;
		nptr ++;
	}
	number *= signal;
	return (number);
}

//Function Description
//Convert ascii to integer
/* # include <stdio.h>
int main(void)
{
	char	*test1 = "42";
	char	*test2 = "-42";
	char	*test3 = "-2147483647";

	printf("%d\n", ft_atoi(test1));
	printf("%d\n", ft_atoi(test2));
	printf("%d\n", ft_atoi(test3));
} */