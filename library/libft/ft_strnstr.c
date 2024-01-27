/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 18:37:01 by aconceic          #+#    #+#             */
/*   Updated: 2023/10/20 18:49:38 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (little[0] == '\0')
		return ((char *)big);
	while (big[i] != '\0')
	{
		j = 0;
		while ((little[j] == big[i + j])
			&& (big[i + j] != '\0') && (i + j < len))
			j++;
		if (little[j] == '\0')
			return ((char *)&big[i]);
		i++;
	}
	return (NULL);
}
/* 
//Function Description
//searches for the first occurrence of a substring little in a string big,
//up to a length len. It returns a pointer to the beginning of the match 
//or NULL if not found.

#include <stdio.h>

int     main(void)
{
        char    main_str[] = "Vamos encontrar a agulha no palheiro ";
        char    find[] = "amos";
        char  *ret;

        //ret = strnstr(main_str, find, 5);
        printf("The substring is: %s\n", ret);
        printf("--------------------------\n");
        printf("%s", ft_strnstr(main_str, find, 5));
}
 */