/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 16:19:11 by aconceic          #+#    #+#             */
/*   Updated: 2024/03/20 15:57:21 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_format(char specifier, va_list ap)
{
	int	count;

	count = 0;
	if (specifier == 'c')
		count += ft_putchar(va_arg(ap, int));
	else if (specifier == 's')
		count += ft_putstr(va_arg(ap, char *));
	else if (specifier == 'p')
		count += ft_putpointer(va_arg(ap, unsigned long));
	else if (specifier == 'i' || specifier == 'd')
		count += ft_putnbr(va_arg(ap, int));
	else if (specifier == 'u')
		count += ft_putunbr(va_arg(ap, unsigned int));
	else if (specifier == 'x')
		count += ft_trialhex(va_arg(ap, unsigned int), 0);
	else if (specifier == 'X')
		count += ft_trialhex(va_arg(ap, unsigned int), 1);
	else if (specifier == '%')
		count += ft_putchar('%');
	else
		count += write(1, &specifier, 1);
	va_end(ap);
	return (count);
}
