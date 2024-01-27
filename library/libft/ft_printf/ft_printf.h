/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 18:22:56 by aconceic          #+#    #+#             */
/*   Updated: 2023/10/30 11:48:38 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h> //for malloc, free
# include <unistd.h> //for write
# include <stdarg.h> // for va_start, va_arg, va_copy

/* main ft_printf && ft_print_format */
int		ft_printf(const char *format, ...);
int		ft_print_format(char specifier, va_list ap);
/* 'c' and 's' */
int		ft_putchar(int c);
int		ft_putstr(char *str);
/* 'p' */
int		ft_putpointer(unsigned long pointer);
/*  'd' and 'i' and 'u' */
int		ft_putnbr(int nbr);
int		ft_putunbr(unsigned int nbr);
/* 'x' and 'X' */
char	*ft_putnbr_hex(unsigned long n);
int		ft_trialhex(unsigned long nbr, int uppercase);

#endif