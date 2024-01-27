/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 14:57:06 by aconceic          #+#    #+#             */
/*   Updated: 2023/10/19 20:01:30 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	total_size;
	void	*ptr;

	total_size = nmemb * size;
	ptr = malloc(total_size);
	if (ptr == NULL)
		return (NULL);
	ft_bzero(ptr, total_size);
	return (ptr);
}

//Function Description
/*The function ft_calloc allocates a block of memory for an array with a 
specified number of elements (nmemb) of a certain size (size). 
It calculates the total memory size, allocates it using malloc, 
clears the memory using ft_bzero, and returns a pointer to the allocated 
memory or NULL if the allocation fails. */

/* #include <stdio.h>

int main(void)
{
	char	*test;
	char	*test_cpy;
	int		i;
	
	test = "test";
	test_cpy = ft_calloc(sizeof(char *), 5);
	i = 0;
	while(i < 5)
	{
		test_cpy[i] = test[i];
		i ++;
	}
	test_cpy[i] = '\0';
	printf("%s", test_cpy);
} */