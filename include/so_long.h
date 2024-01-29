/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 11:08:24 by aconceic          #+#    #+#             */
/*   Updated: 2024/01/29 15:53:48 by aconceic         ###   ########.fr       */
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
/*            KEYBOARD CODES          */
/* ********************************** */
# define KB_W 119
# define KB_S 115
# define KB_A 97
# define KB_D 100
# define KB_ESC 65307
# define KB_AUP 65362
# define KB_ADOWN 65364
# define KB_ALEFT 65361
# define KB_ARIGHT 65363

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
# include "../library/minilibx-linux/mlx.h"
# include "../library/minilibx-linux/mlx_int.h"

/* ********************************** */
/*              STRUCTS               */
/* ********************************** */
//For Map
typedef struct s_map
{
	char 	**map;
	int		map_lines;

}   t_map;
//For Mlx
typedef struct s_mlx_data
{
	void    *mlx_connection;
	void    *mlx_window;
}   t_mlx_data;
/* ********************************** */
/*               MAIN                 */
/* ********************************** */
int		main(int argv, char **argc);
void	error_message(int flag);
/* ********************************** */
/*                MAP                 */
/*         source/map_validation.c    */
/* ********************************** */
char    **map_read(char *file_path);
int		map_lines_counter(char *file_path);
/* ********************************** */
/*               FT UTILS             */
/*           source/ft_utils.c        */
/* ********************************** */
int 	ft_check_extention(char *file_name);
void	ft_free_dp_char(char **dp_char);
/* ********************************** */
/*              GAME UTILS            */
/*          source/game_utils.c       */
/* ********************************** */

/* ********************************** */
/*            RENDER UTILS            */
/*         source/render_utils.c      */
/* ********************************** */
void    render_window(void);
#endif