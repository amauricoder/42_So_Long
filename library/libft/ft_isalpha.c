/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 14:25:23 by aconceic          #+#    #+#             */
/*   Updated: 2023/10/19 20:13:56 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1024);
	else
		return (0);
}

/*
//Function Description
//Verify if a number is letter
//returns a positive number if true(1024 in this case) and 0 if not
#include <stdio.h>

int	main(void)
{
	char	test = 'A';
	char	test1 = 'a';
	char	test2 = '@';
	char	test3 = '1';
	char	test4 = 123;
	
	printf("%d\n", ft_isalpha(test));
	printf("%d\n", ft_isalpha(test1));
	printf("%d\n", ft_isalpha(test2));
	printf("%d\n", ft_isalpha(test3));
	printf("%d\n", ft_isalpha(test4));
} */
