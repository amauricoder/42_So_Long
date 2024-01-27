/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 19:25:45 by aconceic          #+#    #+#             */
/*   Updated: 2023/10/20 14:25:43 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		i;

	i = 0;
	while (lst != NULL)
	{
		i ++;
		lst = lst->next;
	}
	return (i);
}
/* 
//Func description
//The ft_lstsize function calculates the size of a linked 
//list by iterating through it and counting the number of 
//nodes, returning the total count.
#include <stdio.h>

int	main(void)
{
	t_list *lists;
	t_list *last;
	//create lists
	lists = ft_lstnew("list 1");
	lists->next = ft_lstnew("list 2");
	lists->next->next = ft_lstnew("list 3");
	last = lists->next->next->next = ft_lstnew("list 4");
	
	//print first
	printf("The first => %s\n", (char *)lists->content);
	//print how mane i created
	printf("The total is : %d\n", ft_lstsize(lists));
	//put the last one on front
	ft_lstadd_front(&lists, last);
	//print the first one again
	printf("The first now is => %s\n", (char *)lists->content);
}  */
