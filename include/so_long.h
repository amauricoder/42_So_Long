/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 11:08:24 by aconceic          #+#    #+#             */
/*   Updated: 2024/02/03 17:55:28 by aconceic         ###   ########.fr       */
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
	char 	**map_skeleton;
	int		qt_lines;
	int		qt_chars_lines;
	int		qt_player;
	int		qt_collect;
	int		qt_exit;
}   t_map;

//For Mlx
typedef struct s_mlx_data
{
	void    *connect;
	void    *window;
}   t_mlx_data;
/* ********************************** */
/*               MAIN                 */
/* ********************************** */
int		main(int argv, char **argc);
void	error_message(int flag);

/* ********************************** */
/*              MAP INIT              */
/*          source/map_init.c         */
/* ********************************** */
char	**map_read(char *file_path);
int		map_lines_counter(char *file_path);
t_map	*map_init(char *file_path);
int		map_char_counter(char *file_path);

/* ********************************** */
/*            MAP VALIDATION          */
/*         source/map_validation.c    */
/* ********************************** */
int		map_valid_allrequisites(t_map *map);
int		map_valid_characters(t_map *map);
int		map_valid_isclosed(t_map *map);
int		map_valid_mustchar(t_map *map);
int		map_valid_minsize(t_map *map);

/* ********************************** */
/*               FT UTILS             */
/*           source/ft_utils.c        */
/* ********************************** */
int 	ft_check_extention(char *file_name);
int		ft_countchar(char *str);

/* ********************************** */
/*              GAME INIT             */
/*          source/game_init.c        */
/* ********************************** */
t_mlx_data	*game_init(t_mlx_data *render, t_map *map);
/* ********************************** */
/*              GAME UTILS            */
/*          source/game_utils.c       */
/* ********************************** */
int	game_keypress(int keypressed, t_mlx_data *render);

/* ********************************** */
/*            FREE FUNCTIONS          */
/*           source/ft_free.c         */
/* ********************************** */
void	free_dp_char(char **dp_char);
void	free_map_struct(t_map *map_struct);
#endif