/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 16:54:28 by aconceic          #+#    #+#             */
/*   Updated: 2023/10/19 22:04:18 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	number;

	number = (long)n;
	if (n < 0)
	{
		write ((unsigned int)fd, "-", 1);
		number = -number;
	}
	if (number >= 10)
		ft_putnbr_fd(number / 10, fd);
	number = (number % 10) + '0';
	write((unsigned int)fd, &number, 1);
}

/* #include <stdio.h>

//function descrition
//ft_putnbr_fd writes an integer n to a specified file descriptor fd. 
//It converts the integer to a string and outputs it.
int	main(void)
{
	int int_min = -2147483648;
	ft_putnbr_fd(int_min, 1);
	write(1, "\n", 1);
	int int_max = 2147483647;
	ft_putnbr_fd(int_min, 1);
} */