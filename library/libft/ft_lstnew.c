/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 15:15:59 by aconceic          #+#    #+#             */
/*   Updated: 2023/12/20 20:39:05 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}

/* 
//function description
//The ft_lstnew function creates a new linked list node 
//with the provided content, allocating memory for it and 
//setting its 'next' pointer to NULL.
#include <stdio.h>

int	main(void)
{
	char *str;
	t_list *element;
	
	str = (char *)malloc(sizeof(char) * 7);
	str = "amauri";
	
	element = ft_lstnew((void *)str);
	printf("%s\n", (char *)element->content);
	
} */