/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 12:37:50 by aconceic          #+#    #+#             */
/*   Updated: 2023/10/19 22:24:11 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	unsigned int	i;
	unsigned int	src_leng;

	i = 0;
	src_leng = 0;
	while (src[src_leng] != '\0')
		src_leng ++;
	if (size != 0)
	{
		while (src[i] != '\0' && i < (size - 1))
		{
			dst[i] = src[i];
			i ++;
		}
		dst[i] = '\0';
	}
	return (src_leng);
}
/* 
//ft_strlcpy copies the src string to dst with a maximum length of size. 
//It returns the length of src while ensuring null-termination in dst
#include "libft.h"
#include <stdio.h>

int main() {
    char destination[15]; // Ensure destination has enough space
    const char *source = "This is test!";
    size_t destination_size = sizeof(destination);

    size_t result = ft_strlcpy(destination, source, destination_size);

    printf("Copied string: %s\n", destination);
    printf("Resulting length: %zu\n", result);

    return 0;
} */
