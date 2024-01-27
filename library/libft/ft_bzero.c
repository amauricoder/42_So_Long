/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 10:49:03 by aconceic          #+#    #+#             */
/*   Updated: 2023/10/19 20:04:28 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*a;

	a = (unsigned char *)s;
	while (n--)
		*a ++ = 0;
}

//Function description
//Takes a specific number of bytes in memory and giver them 
//the value of 0
