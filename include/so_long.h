/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 11:08:24 by aconceic          #+#    #+#             */
/*   Updated: 2024/01/27 08:20:11 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

/* ********************************** */
/*               COLORS               */
/* ********************************** */
# define RESET   "\033[0m"
# define RED     "\033[31m"
# define GREEN   "\033[32m"
# define YELLOW  "\033[33m"
# define BLUE    "\033[34m"
# define MAGENTA "\033[35m"
# define CYAN    "\033[36m"
# define WHITE   "\033[37m"

/* ********************************** */
/*           EXTERNAL LIBS            */
/* ********************************** */
#include <stdlib.h> //malloc(), free(), exit()
#include <fcntl.h> //open()
#include <unistd.h> //read(), write()
#include <stdio.h> //perror()
#include <string.h> //strerror()
/* ********************************** */
/*           IMPORTED FILE            */
/* ********************************** */
# include "../library/libft/libft.h"

#ifdef LINUX
    # include "../library/minilibx-linux/mlx.h"
    # include "../library/minilibx-linux/mlx_int.h"
#else
    # include "../library/minilibx-opengl/mlx.h"
    # include "../library/minilibx-opengl/mlx_int.h"
    # include "../library/minilibx-opengl/mlx_new_window.h"
    # include "../library/minilibx-opengl/mlx_opengl.h"
    # include "../library/minilibx-opengl/mlx_png.h"
#endif
/* ********************************** */
/*               MAIN                 */
/* ********************************** */
int	main(int argc, char **argv);

#endif