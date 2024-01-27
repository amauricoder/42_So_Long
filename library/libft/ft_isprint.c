/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 17:58:13 by aconceic          #+#    #+#             */
/*   Updated: 2023/10/19 20:53:14 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	if (c >= 32 && c < 127)
		return (16384);
	else
		return (0);
}

/* 
//Function Description
//Verify if a character is printable
//returns a positive number if true(16384 in this case) and 0 if not
#include <stdio.h>

int	main(void)
{
	char	test = 'A';
	char	test1 = 'a';
	char	test2 = '\r';
	
	printf("%d\n", ft_isprint(test));
	printf("%d\n", ft_isprint(test1));
	printf("%d\n", ft_isprint(test2));
}
 */