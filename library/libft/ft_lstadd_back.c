/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 15:43:36 by aconceic          #+#    #+#             */
/*   Updated: 2023/10/20 14:25:54 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*node;

	node = *lst;
	if (!new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	else
	{
		while (node->next != NULL)
			node = node->next;
		node->next = new;
	}
}
/* 
//function description
//The function ft_lstadd_back appends a new node 
//to the end of a linked list (lst) if new is not null, 
//handling cases where the list is empty or not.
#include <stdio.h>

int main(void)
{
	t_list *list;
	t_list *current;
	t_list *new;
	
	list = ft_lstnew("list1");
	list->next = ft_lstnew("list2");
	list->next->next = ft_lstnew("list3");
	list->next->next->next = ft_lstnew("list4");

	new = ft_lstnew("newlist");
	ft_lstadd_back(&list, new);
	current = list;
	while(current != NULL)
	{
		printf("%s\n", (char *)current->content);
		current = current->next;
	}
}  */