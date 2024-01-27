/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 11:15:59 by aconceic          #+#    #+#             */
/*   Updated: 2023/10/19 22:10:36 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char )c)
			return ((char *)&s[i]);
		i++;
	}
	if ((char )c == '\0')
		return ((char *)&s[i]);
	return (NULL);
}

/* 
//function description
//ft_strchr searches for the first occurrence of character c in the string s, 
//returning a pointer to the character or NULL if not found.
#include <stdio.h>

int main(void)
{
	char *res;
	char *name;
	name = "amauri";
	res = ft_strchr(name, 'm');

	printf("%s", res);
} */