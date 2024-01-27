/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 10:50:16 by aconceic          #+#    #+#             */
/*   Updated: 2023/10/20 18:51:09 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	int		res_size;
	int		leng;

	leng = ft_strlen(s1);
	start = 0;
	end = leng - 1;
	if (s1 == NULL || set == NULL)
		return (NULL);
	while (s1[start] && ft_strchr(set, s1[start]))
		start ++;
	if (start >= leng)
		return (ft_strdup(""));
	else
	{
		while (end >= 0 && ft_strchr(set, s1[end]))
			end --;
	}
	res_size = end - start + 1;
	return (ft_substr(s1, start, res_size));
}
/* 
//Function description
//removes leading and trailing characters in set from the string s1, 
//returning a new string. It handles null pointers and empty results.
#include <stdio.h>

int	main(void)
{
	char	*name = "!!--!!amauri!@@--!";
	char	*set = "!";
	char	*result = ft_strtrim(name, set);
	
	printf("%s", result);
	return (0);
} */