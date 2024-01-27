/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 21:05:03 by amaurilisbo       #+#    #+#             */
/*   Updated: 2023/10/30 11:49:02 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	count_digits(long long nbr_to_count)
{
	long long	number_long;
	int			counter;

	number_long = (long long)nbr_to_count;
	counter = 1;
	if (number_long < 0)
	{
		counter ++;
		number_long = -nbr_to_count;
	}
	while (number_long >= 10)
	{
		counter ++;
		number_long = number_long / 10;
	}
	return (counter);
}

int	ft_putnbr(int nbr)
{
	long long	number_long;
	int			digits_return;

	digits_return = count_digits(nbr);
	number_long = (long long)nbr;
	if (nbr < 0)
	{
		ft_putchar('-');
		number_long = -number_long;
	}
	if (number_long >= 10)
		ft_putnbr(number_long / 10);
	number_long = (number_long % 10) + '0';
	write(1, &number_long, 1);
	return (digits_return);
}

/*  
# include <stdio.h>
#include <limits.h>
int	main(void)
{
	//count_digits tests => this function counter the digits
	
	int zero_test = 0;
	int negative_test = -2147483647;
	int positive_test = 2147483647;
	
	ft_printf("Must return 1 => %d\n", count_digits(zero_test));
	ft_printf("Must return 11 => %d\n", count_digits(negative_test));
	ft_printf("Must return 10 => %d\n", count_digits(positive_test));
	
	
	ft_printf("%i\n", INT_MIN);
	ft_printf("%d\n", INT_MIN);
	printf("%ld", LONG_MAX);
} */