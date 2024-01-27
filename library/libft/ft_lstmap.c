/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 21:04:54 by aconceic          #+#    #+#             */
/*   Updated: 2023/10/20 14:26:33 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	void	*content;
	t_list	*new_lst;
	t_list	*temp;

	if (!lst || !f || !del)
		return (NULL);
	new_lst = NULL;
	while (lst)
	{
		content = f(lst->content);
		temp = ft_lstnew(content);
		if (!temp)
		{
			del(content);
			ft_lstclear(&new_lst, del);
			return (NULL);
		}
		ft_lstadd_back(&new_lst, temp);
		lst = lst->next;
	}
	return (new_lst);
}

/*
#include <stdio.h>
//func description
//The ft_lstmap function applies a given function f to each 
//element of a linked list, creating a new list with the transformed 
//elements. It handles memory allocation and error conditions, 
//invoking a deletion function del when necessary.
// cc ft_lstmap.c ft_lstnew.c ft_lstadd_back.c 
ft_lstclear.c ft_lstiter.c ft_strlen.c

static void	printlst(void *val)
{
	printf("%s\n", (char *)val);
}
 
static void	*upperlist(void *str)
{
	char	*original;
	int		length;
	char	*result;

	original = (char *)str;
	length = ft_strlen(original);
	result = (char *)malloc(length + 1);
	if (result)
	{
		for (int i = 0; i < length; i++)
		{
			if (original[i] >= 'a' && original[i] <= 'z')
				result[i] = original[i] - 32;
			else
				result[i] = original[i];
		}
		result[length] = '\0';
	}
	return result;
}

int main(void)
{
	t_list	*list;
	t_list	*uppercase_list;
	
	list = ft_lstnew("list 1");
	ft_lstadd_back(&list, ft_lstnew("list 2"));
	ft_lstadd_back(&list, ft_lstnew("list 3"));
	ft_lstiter(list, printlst);
	//----------------------------------------//
	uppercase_list = ft_lstmap(list, upperlist, free);
	ft_lstiter(uppercase_list, printlst);	
	
	//test func uppercase
	char 	test[] = "this is a test"; 
	char	*result = upperlist(test);
	printf("%s", result);
	free(result);
	
    return (0);
}
 */