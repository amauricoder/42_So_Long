/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 21:05:03 by amaurilisbo       #+#    #+#             */
/*   Updated: 2024/03/20 15:57:58 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	hex_count_digits(unsigned long n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= 16;
		len++;
	}
	return (len);
}

char	*ft_putnbr_hex(unsigned long n)
{
	char	*str;
	int		i;
	int		temp;

	i = hex_count_digits(n);
	str = malloc(i + 1);
	if (!str)
		return (0);
	str[i--] = '\0';
	if (n == 0)
		str[i] = '0';
	while (n != 0)
	{
		temp = n % 16;
		if (temp < 10)
			str[i] = temp + '0';
		else
			str[i] = (temp - 10) + 'a';
		i--;
		n /= 16;
	}
	return (str);
}

/* 
# include <stdio.h>
int	main(void)
{
	int zero_test = 255;
	int one_test = 4096;
	int two_test = 12345;
	int three_test = 65535;
	int four_test = 42;
	
	//hex_count_digits tests => this function counter the hex digits
	printf("Hex count\n");
	printf("must return 2 because FF is 2 => %d\n", 
			hex_count_digits(zero_test));
	printf("must return 4 because FFFF is 4 => %d\n", 
			hex_count_digits(three_test));
	//hex conververtion
	printf("Hex convertion\n");
	printf("must return ff => %s\n", ft_putnbr_hex(zero_test));
	printf("must return 1000 => %s\n", ft_putnbr_hex(one_test));
	printf("must return 3039 => %s\n", ft_putnbr_hex(two_test));
	printf("must return ffff => %s\n", ft_putnbr_hex(three_test));
	printf("must return 2a => %s\n", ft_putnbr_hex(four_test));
	
} */