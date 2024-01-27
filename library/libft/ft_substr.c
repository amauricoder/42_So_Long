/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 11:28:22 by aconceic          #+#    #+#             */
/*   Updated: 2023/10/19 22:41:55 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*result_str;
	size_t	i;

	i = 0;
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (len + start > ft_strlen(s))
		len = ft_strlen(&s[start]);
	result_str = malloc(len + 1);
	if (result_str == NULL)
		return (NULL);
	while (i < len)
	{
		result_str[i] = s[start + i];
		i ++;
	}
	result_str[i] = '\0';
	return (result_str);
}

/*
//function description
//extracts a substring from the string s starting at start with a length of len, 
//allocating memory for the result and ensuring proper handling of edge cases.

#include <stdio.h>

int main() {
    const char *source = "This is a test string";
    unsigned int start = 10;
    size_t length = 4;

    char *result = ft_substr(source, start, length);

    if (result != NULL) {
        printf("Original: %s\n", source);
        printf("Substring: %s\n", result);
        free(result); // Don't forget to free the allocated memory.
    } else {
        printf("Substr extraction failed.\n");
    }
    return (0);
}
 */