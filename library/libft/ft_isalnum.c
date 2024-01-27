/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 15:25:57 by aconceic          #+#    #+#             */
/*   Updated: 2023/10/19 20:11:27 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if ((c >= '0' && c <= '9') || (c >= 'a' && c <= 'z')
		|| (c >= 'A' && c <= 'Z'))
		return (8);
	else
		return (0);
}

/*
//Function Description
//Verify if a number is alphanumerical
//returns a positive number if true(8 in this case) and 0 if not
#include <stdio.h>

int	main(void)
{
	char	test = 'A';
	char	test1 = 'a';
	char	test2 = '@';
	char	test3 = '1';
	char	test4 = '-';
	
	printf("%d\n",ft_isalnum(test));
	printf("%d\n",ft_isalnum(test1));
	printf("%d\n",ft_isalnum(test2));
	printf("%d\n",ft_isalnum(test3));
	printf("%d\n",ft_isalnum(test4));
}
*/