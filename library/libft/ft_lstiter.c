/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 20:57:50 by aconceic          #+#    #+#             */
/*   Updated: 2023/10/20 14:26:20 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst || !f)
		return ;
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}

/* 
//Function Description
//The ft_lstiter function iterates through a linked list, applying a provided 
//function f to the content of each node, making it possible to perform 
//an operation on each element of the list.
#include <stdio.h>

void print_element(void *content) {
    printf("%s\n", (char *)content);
}

int main() {
    t_list *list = NULL;

    // Create a list with some elements
    ft_lstadd_back(&list, ft_lstnew("Element 1"));
    ft_lstadd_back(&list, ft_lstnew("Element 2"));
    ft_lstadd_back(&list, ft_lstnew("Element 3"));

    ft_lstiter(list, print_element);

    return (0);
} */