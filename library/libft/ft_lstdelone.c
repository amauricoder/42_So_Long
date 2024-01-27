/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 18:41:24 by aconceic          #+#    #+#             */
/*   Updated: 2023/10/20 18:54:01 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (!lst)
		return ;
	del (lst->content);
	free (lst);
}
/*
static void	free_node(void *node)
{
	unsigned char	*temp;

	temp = (unsigned char *) node;
	if (!temp)
		return ;
	free(temp);
}

//Function description
//The ft_lstdelone function deletes a single node in a linked list,
//freeing its content and memory, ensuring no memory leaks.
#include <stdio.h>

int main(void)
{
	t_list	*element;
	char	*str;
	
	str = (char *)malloc(sizeof(char) * 7);
	strcpy(str, "teste");
	element = ft_lstnew(str);
	printf("Before function => %s\n", (char *)element->content);
	ft_lstdelone(element, free_node);
	printf("After function => %s\n", (char *)element->content);
}
 */