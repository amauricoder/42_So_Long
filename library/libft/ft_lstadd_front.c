/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 18:07:57 by aconceic          #+#    #+#             */
/*   Updated: 2023/10/20 14:25:59 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
}
/* 
//function description
//The function ft_lstadd_front adds a new 
//node to the front of a linked list (lst) by updating pointers.
#include <stdio.h>
int main(void)
{
	//declare nods
	t_list *elem;
	t_list *in_front;
	t_list *current;
	
	//create new node
	elem = ft_lstnew("first node");
	elem->next = ft_lstnew("second node");
	in_front = ft_lstnew("In Front");
	
	//use func to add in front
	ft_lstadd_front(&elem, in_front);
	
	//print alone to test
	//printf("This is the first => %s\n", (char *)elem->content);
	
	//print all in order
	current = elem;
	while (current != NULL)
	{
		printf("%s\n", (char *)current->content);
		current = current->next;
	}
} */
