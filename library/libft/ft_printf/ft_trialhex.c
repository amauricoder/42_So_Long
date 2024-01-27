/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_trialhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 14:52:44 by aconceic          #+#    #+#             */
/*   Updated: 2023/10/31 19:37:47 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_strtoupper(char *str)
{
	int	i;

	i = 0;
	while (str[i] != 0)
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] -= 32;
		i ++;
	}
	return (str);
}

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

int	ft_trialhex(unsigned long nbr, int uppercase)
{
	int		nbr_digits;
	char	*nbr_char;

	nbr_digits = hex_count_digits(nbr);
	nbr_char = ft_putnbr_hex(nbr);
	if (uppercase)
	{
		nbr_char = ft_strtoupper(nbr_char);
		ft_putstr(nbr_char);
	}
	else
		ft_putstr(nbr_char);
	free(nbr_char);
	return (nbr_digits);
}

/* 
# include <stdio.h>
int	main(void)
{
	//ft_strtoupper test 
	//char test[] ="ft_strtoupper test";
	//printf("%s\n", ft_strtoupper(test));
	
	//ft_trialhex test
	int zero_test = 255;
	int one_test = 4096;
	int two_test = 12345;
	int three_test = 65535;
	int four_test = 42;
	
	printf(" => %d\n", ft_trialhex(zero_test, 1));
	printf(" => %d\n", ft_trialhex(one_test, 0));
	printf(" => %d\n", ft_trialhex(two_test, 0));
	printf(" => %d\n", ft_trialhex(three_test, 0));
	printf("  %d\n", ft_trialhex(four_test, 0));

} */