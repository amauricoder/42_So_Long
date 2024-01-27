/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 14:46:28 by aconceic          #+#    #+#             */
/*   Updated: 2023/10/19 22:14:34 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;

	i = 0;
	while (s[i] != '\0')
	{
		f(i, &s[i]);
		i ++;
	}
}
/* 
//Function description
//ft_striteri applies a function f to each character of a string s 
//along with its index, incrementing the index and iterating through the string.
#include <stdio.h>

static void	test_function(unsigned int index, char *str)
{
	while (index < ft_strlen(str))
	{	
		if (index % 2 != 0 && (str[index] >= 97 && str[index] <= 122))
			str[index] -= 32;
		if (index % 2 == 0 && (str[index] >= 65 && str[index] <= 90))
			str[index] += 32;
		index ++;	
	}
}

int main(void)
{
	//TEST WORKING
	char str_test[] = "This is a test and will be ok";
	ft_striteri(str_test, test_function); 
	printf("%s", str_test);
}
 */