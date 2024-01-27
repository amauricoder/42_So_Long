/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 09:50:04 by aconceic          #+#    #+#             */
/*   Updated: 2023/11/20 15:51:18 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t		total_size;
	char		*ptr;
	size_t		i;

	total_size = nmemb * size;
	ptr = malloc(total_size);
	if (ptr == NULL)
		return (NULL);
	i = 0;
	while (total_size --)
	{
		ptr[i] = 0;
		i++;
	}
	return ((void *)ptr);
}

int	ft_strlen(char *s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i] != '\0')
		i ++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*new_str;
	size_t	i;
	size_t	j;

	if (!s1)
		s1 = ft_calloc(sizeof(char), 1);
	new_str = (char *)ft_calloc(sizeof(char),
			(ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!new_str)
	{
		free(s1);
		free(s2);
		return (NULL);
	}
	i = -1;
	while (s1[++i])
		new_str[i] = s1[i];
	j = 0;
	while (s2[j])
		new_str[i++] = s2[j++];
	free(s1);
	free(s2);
	return (new_str);
}

char	*ft_strchr(char *s, int c)
{
	size_t	i;

	i = 0;
	if (!s)
	{
		free(s);
		return (NULL);
	}
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
