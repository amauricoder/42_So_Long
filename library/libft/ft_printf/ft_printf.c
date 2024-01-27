/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 17:19:04 by aconceic          #+#    #+#             */
/*   Updated: 2023/12/13 21:55:44 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	int		return_value;
	va_list	argument_pointer;

	va_start(argument_pointer, format);
	return_value = 0;
	while (*format != '\0')
	{
		if (*format == '%')
			return_value += ft_print_format(*(++format), argument_pointer);
		else
			return_value += write(1, format, 1);
		++ format;
	}
	va_end(argument_pointer);
	return (return_value);
}
/* 
# include <stdio.h>
int main(void)
{
	char	strtest[] = "string variable";
	char	chtest = 'c';
	int		dtest_positive = 12345;
	int		dtest_negative = -12345;
	int		itest_positive = 12345;
	int		itest_negative = -12345;
	int		xlower = 255;
	int		xupper = 255;
	unsigned int utest = 123456789;
	int 	original_result;
	int		my_result;
	int		*ptr;
	

//test for %c
	original_result = printf("%c\n",  chtest);
		printf("Original Nbr of bytes %d\n", original_result);
	my_result = ft_printf("%c\n", chtest);
		printf("My Nbr of bytes %d\n", my_result);
		printf("\n");
//test for %s
	original_result = printf("%s\n", strtest);
		printf("Original Nbr of bytes %d\n", original_result);
	my_result = ft_printf("%s\n", strtest);
		printf("My Nbr of bytes %d\n", my_result);
		printf("\n");
//test for %d
	original_result = printf("%d\n", dtest_positive);
		printf("Original Nbr of bytes %d\n", original_result);
	my_result = ft_printf("%d\n", dtest_positive);
		printf("My Nbr of bytes %d\n", my_result);
		printf("\n");
	original_result = printf("%d\n", dtest_negative);
		printf("Original Nbr of bytes %d\n", original_result);
	my_result = ft_printf("%d\n", dtest_negative);
		printf("My Nbr of bytes %d\n", my_result);
		printf("\n");
//test for %i
	original_result = printf("%d\n", itest_positive);
		printf("Original Nbr of bytes %d\n", original_result);
	my_result = ft_printf("%d\n", itest_positive);
		printf("My Nbr of bytes %d\n", my_result);
		printf("\n");
	original_result = printf("%d\n", itest_negative);
		printf("Original Nbr of bytes %d\n", original_result);
	my_result = ft_printf("%d\n", itest_negative);
		printf("My Nbr of bytes %d\n", my_result);
//test for %u
		printf("\n");
	original_result = printf("%u\n", utest);
		printf("Original Nbr of bytes %d\n", original_result);
	my_result = ft_printf("%u\n", utest);
		printf("My Nbr of bytes %d\n", my_result);
//test for %x
		printf("\n");
	original_result = printf("%x\n", xlower);
		printf("Original Nbr of bytes %d\n", original_result);
	my_result = ft_printf("%x\n", xlower);
		printf("My Nbr of bytes %d\n", my_result);
//test for %X
		printf("\n");
	original_result = printf("%X\n", xupper);
		printf("Original Nbr of bytes %d\n", original_result);
	my_result = ft_printf("%X\n", xupper);
		printf("My Nbr of bytes %d\n", my_result);
// test for %%
	printf("\n");
	original_result = printf("%%\n");
		printf("Original Nbr of bytes %d\n", original_result);
	my_result = ft_printf("%%\n");
		printf("My Nbr of bytes %d\n", my_result);
// test for p
	printf("\n");
	original_result = printf("%p\n", (void *)ptr);
		printf("Original Nbr of bytes %d\n", original_result);
	return (0);
} */