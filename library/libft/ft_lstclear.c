/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 19:36:12 by aconceic          #+#    #+#             */
/*   Updated: 2023/10/20 14:26:06 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*current_node;
	t_list	*next_node;

	current_node = *lst;
	if (!lst)
		return ;
	while (current_node)
	{
		next_node = current_node->next;
		del (current_node->content);
		free (current_node);
		current_node = next_node;
	}
	*lst = NULL;
}

//Function Description
//The ft_lstclear function clears a linked list (lst) 
//by iteratively deleting each node and its associated 
//content using a provided deletion function (del). 
//It ensures proper memory cleanup by freeing both the 
//node and its content, then sets the list pointer to NULL 
//to indicate an empty list.
