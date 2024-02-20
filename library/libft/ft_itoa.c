/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebmarque <ebmarque@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 12:00:52 by aconceic          #+#    #+#             */
/*   Updated: 2024/02/20 11:27:36 by ebmarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	n_size(int n)
{
	int				i;
	unsigned int	nb;

	i = 1;
	nb = n;
	if (n < 0)
	{
		nb = -n;
		i ++;
	}
	while (nb >= 10)
	{
		nb /= 10;
		i ++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	int				qt_n;
	unsigned int	number;
	char			*res;

	qt_n = n_size(n);
	number = n;
	res = ft_calloc(sizeof(char), qt_n + 1);
	if (!res)
		return (NULL);
	res[qt_n] = '\0';
	if (n < 0)
	{
		res[0] = '-';
		number = -n;
	}
	while (qt_n > 0 && res[--qt_n] != '-')
	{
		res[qt_n] = (number % 10) + '0';
		number = number / 10;
	}
	return (res);
}
/* 
//Function description
//The function ft_itoa converts an integer n into a string, 
//allocating memory for the result and handling negative numbers.

#include <stdio.h>

int main(void)
{
	int positive = 42; 
	int negative = -42; 
	int max_negative = -2147483648; 
	
	char *res_test;
	res_test = ft_itoa(positive);
 	printf("%s\n", res_test);
	res_test = ft_itoa(negative);
 	printf("%s\n", res_test);
	res_test = ft_itoa(max_negative);
 	printf("%s\n", res_test);
	
 	//test of n_size
 	int test_nsize = 12345;
 	int res;
 	res = n_size(test_nsize);
 	printf("%d\n", res);
} */