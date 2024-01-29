/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 11:58:59 by aconceic          #+#    #+#             */
/*   Updated: 2024/01/29 15:45:56 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	length;
	size_t	i;
	char	*cpy;

	length = ft_strlen(s);
	cpy = (char *)malloc(sizeof(char) * length + 1);
	i = 0;
	if (cpy == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		cpy[i] = s[i];
		i ++;
	}
	cpy[i] = '\0';
	return (cpy);
}
/* 
//Function description
//ft_strdup duplicates a given string s, allocating memory for the copy,
//and returns a pointer to the new string. Here's a sample test:
#include <stdio.h>

int main() {
    const char *original = "This is a beaultifusdsdsdasd test!";
    char *duplicate = ft_strdup(original);

    if (duplicate != NULL) {
        printf("Original: %s\n", original);
        printf("Duplicate: %s\n", duplicate);
        free(duplicate); // Don't forget to free the allocated memory.
    } else {
        printf("Duplication failed.\n");
    }

    return 0;
} */
