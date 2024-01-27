/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 09:50:02 by aconceic          #+#    #+#             */
/*   Updated: 2023/11/21 09:11:28 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

//****************************************************************************//
//                                 Libraries                                  //
//****************************************************************************//
# include <stdlib.h> // for mallocs
# include <unistd.h> //for read()
//# include <fcntl.h> //for testing purposes, exclude to push
//# include <stdio.h> //for testing purposes, exclude to push

//****************************************************************************//
//                                 Functions                                  //
//****************************************************************************//
char	*get_next_line(int fd);
char	*ft_strchr(char *s, int c);
char	*ft_strjoin(char *s1, char *s2);
int		ft_strlen(char *s);
void	*ft_calloc(size_t nmemb, size_t size);

#endif