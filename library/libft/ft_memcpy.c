/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 14:54:52 by aconceic          #+#    #+#             */
/*   Updated: 2023/10/19 21:54:47 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;

	if (dest == src)
		return (dest);
	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	while (n --)
	{
		*d = *s;
		d++;
		s++;
	}
	return (dest);
}
/* 
//Function description
//The ft_memcpy function copies n bytes from source memory src to 
//destination memory dest and returns a pointer to dest. 
//If dest and src overlap, it ensures proper copying.

#include <stdio.h>

int main() {
    char source[] = "Source String";
    char destination[20]; // Make sure destination has enough space
    size_t num_bytes = sizeof(source);

    ft_memcpy(destination, source, num_bytes);

    printf("Source: %s\n", source);
    printf("Destination: %s\n", destination);

    return 0;
} */
