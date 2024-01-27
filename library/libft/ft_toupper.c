/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 15:59:24 by aconceic          #+#    #+#             */
/*   Updated: 2023/10/19 22:43:37 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		c -= 32;
	return (c);
}

/*
//Function description
//converts a lowercase character to its corresponding uppercase character. 
//If the input is not a lowercase character, it remains unchanged.

#include <stdio.h>

int main() {
    int lowercase = 'a';
    int uppercase = ft_toupper(lowercase);

    printf("Lowercase: %c\n", lowercase);
    printf("Uppercase: %c\n", uppercase);

    return (0);
}
*/