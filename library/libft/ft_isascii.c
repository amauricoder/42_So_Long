/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 16:53:35 by aconceic          #+#    #+#             */
/*   Updated: 2023/10/19 20:19:52 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	if (!(c >= 0 && c <= 127))
		return (0);
	else
		return (1);
}

/* 
//Function Description
//Verify if a character is ascii
//returns a positive number if true(1 in this case) and 0 if not
#include <stdio.h>

int	main(void)
{
	char	test = 'A';
	char	test1 = 'a';
	char	test2 = '@';
	char	test3 = '1';
	char	test4 = 128; //this returns error comp
	
	printf("%d\n", ft_isascii(test));
	printf("%d\n", ft_isascii(test1));
	printf("%d\n", ft_isascii(test2));
	printf("%d\n", ft_isascii(test3));
	printf("%d\n", ft_isascii(test4));
}

 */