/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 13:00:58 by aconceic          #+#    #+#             */
/*   Updated: 2023/10/19 22:30:20 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while ((i < n && s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i]))
		i ++;
	if (n == i)
		return (0);
	else
		return ((int)(unsigned char)s1[i] - (int)(unsigned char)s2[i]);
}
/* 
//Function Description
//compares the first n characters of two strings s1 and s2. 
//It returns zero if they match up to n, or the difference 
//between the first differing characters.
#include <stdio.h>

int main() {
    const char *str1 = "Hello, World!";
    const char *str2 = "Hello, Universe!";
    size_t n = 6; // Compare the first 6 characters

    int result = ft_strncmp(str1, str2, n);

    if (result == 0) {
        printf("The strings are equal up to %zu characters.\n", n);
    } else {
        printf("The strings differ at character %zu.\n", n);
    }

    return (0);
}
 */