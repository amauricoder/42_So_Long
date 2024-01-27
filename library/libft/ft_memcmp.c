/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 15:30:11 by aconceic          #+#    #+#             */
/*   Updated: 2023/10/19 21:52:31 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*str_1;
	unsigned char	*str_2;
	size_t			i;

	str_1 = (unsigned char *)s1;
	str_2 = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (str_1[i] != str_2[i])
			return (str_1[i] - str_2[i]);
		i ++;
	}
	return (0);
}
/* 
//Function Descrition
//The ft_memcmp function compares two memory blocks 
//s1 and s2 of size n, returning zero if they are equal, 
//a negative value if s1 is less than s2, and a positive value if
//s1 is greater than s2.

#include <stdio.h>

int main() {
    char str_1[] = "123456";
    char str_2[] = "12345678!";
    size_t size = sizeof(str_1);

    int result = ft_memcmp(str_1, str_2, size);

    if (result < 0) {
        printf("str1 is less than str 2\n");
    } else if (result > 0) {
        printf("str 1 is greater than str 2\n");
    } else {
        printf("str 2 is equal to str 1\n");
    }

    return 0;
} */
