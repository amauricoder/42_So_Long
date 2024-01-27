/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 18:13:46 by aconceic          #+#    #+#             */
/*   Updated: 2023/10/19 22:26:09 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i ++;
	return (i);
}
/* 
//Function description
//ft_strlen counts the number of characters in a string s 
//until it reaches the null-terminating character. 

#include <stdio.h>
int main() {
    const char *text = "Count this motherfruiter!";
    size_t length = ft_strlen(text);

    printf("Length of the string: %zu\n", length);

    return (0);
} */