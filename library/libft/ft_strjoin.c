/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 17:43:43 by aconceic          #+#    #+#             */
/*   Updated: 2023/10/19 22:16:06 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_str;
	size_t	s1_len;
	size_t	s2_len;
	size_t	i;
	size_t	j;

	i = 0;
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	new_str = (char *)malloc(s1_len + s2_len + 1);
	if (!new_str)
		return (NULL);
	while (s1[i] != '\0')
	{
		new_str[i] = s1[i];
		i ++;
	}
	j = 0;
	while (s2[j] != '\0')
	{
		new_str[i + j] = s2[j];
		j ++;
	}
	new_str[i + j] = '\0';
	return (new_str);
}
/* 
//Function description
//ft_strjoin combines two strings s1 and s2 into a new string, 
//allocating memory for the result, and returns a pointer to it.
#include <stdio.h>

int	main(void)
{
	char	*str_a;
	char	*str_b;
	char	*result;

	str_a = "biruleibe";
	str_b = " leibe";
	result = ft_strjoin(str_a, str_b);
	printf("%s", result);
} */