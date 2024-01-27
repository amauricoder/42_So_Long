/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 16:37:54 by aconceic          #+#    #+#             */
/*   Updated: 2023/10/19 22:45:19 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		c += 32;
	return (c);
}
/* 
//Func description
//ft_tolower converts an uppercase character to its 
//corresponding lowercase character. 
//If the input is not uppercase, it remains unchanged.
#include <stdio.h>

int main() {
    int uppercase = 'Z';
    int lowercase = ft_tolower(uppercase);

    printf("Uppercase: %c\n", uppercase);
    printf("Lowercase: %c\n", lowercase);

    return 0;
}
*/