/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 21:05:03 by amaurilisbo       #+#    #+#             */
/*   Updated: 2023/10/30 11:49:12 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	count_digits(long nbr_to_count)
{
	long	number_long;
	int		counter;

	number_long = (long)nbr_to_count;
	counter = 1;
	while (number_long >= 10)
	{
		counter ++;
		number_long = number_long / 10;
	}
	return (counter);
}

int	ft_putunbr(unsigned int nbr)
{
	int				digits_return;

	digits_return = count_digits(nbr);
	if (nbr >= 10)
		ft_putunbr(nbr / 10);
	nbr = (nbr % 10) + '0';
	write(1, &nbr, 1);
	return (digits_return);
}
/* 
# include <stdio.h>
int	main(void)
{
	printf("%u\n", ft_putunbr(-9));
	printf("%u\n", -9);
}
 */