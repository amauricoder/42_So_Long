/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: murilo <murilo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 11:08:24 by aconceic          #+#    #+#             */
/*   Updated: 2024/02/08 11:46:40 by murilo           ###   ########.fr       */
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
/*              SPRITES               */
/* ********************************** */
# define GROUND "assets/sheets/tiles/ground.xpm"
# define MURR "assets/sheets/tiles/murr.xpm"
# define WALL_BL "assets/sheets/tiles/wall_bl.xpm"
# define WALL_BR "assets/sheets/tiles/wall_br.xpm"
# define WALL_C "assets/sheets/tiles/wall_c.xpm"
# define WALL_L "assets/sheets/tiles/wall_l.xpm"
# define WALL_ML "assets/sheets/tiles/wall_ml.xpm"
# define WALL_MR "assets/sheets/tiles/wall_mr.xpm"
# define WALL_R "assets/sheets/tiles/wall_r.xpm"
# define WALL_BC "assets/sheets/tiles/wall_bc.xpm"

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
	void	*img_murr;
	void	*img_wallbl;
	void	*img_wallbr;
	void	*img_wallc;
	void	*img_walll;
	void	*img_wallml;
	void	*img_wallmr;
	void	*img_wallr;
	void	*img_wallbc;
}   t_map;

//For Mlx
typedef struct s_mlx_data
{
	void    *connect;
	void    *window;
}   t_mlx_data;

//Game main structure
typedef struct s_game
{
	t_map *map;
	t_mlx_data *data_mlx;
	int	img_h;
	int img_w;
}	t_game;

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
t_game	*map_init(char *file_path);
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
void	ft_alloc_img(t_game *game);

/* ********************************** */
/*              GAME INIT             */
/*          source/game_init.c        */
/* ********************************** */
void	game_init(t_game *game);
void	game_get_img(t_game *game);

/* ********************************** */
/*              GAME UTILS            */
/*          source/game_utils.c       */
/* ********************************** */
void	game_close(t_game *game);

/* ********************************** */
/*             GAME RENDER            */
/*         source/game_render.c       */
/* ********************************** */
int game_drawmap(t_game *game);

/* ********************************** */
/*            GAME COMMANDS           */
/*        source/game_commands.c      */
/* ********************************** */
int		game_commands(t_game *game);
int		game_keypress(int keypressed, t_game *game);

/* ********************************** */
/*            FREE FUNCTIONS          */
/*           source/ft_free.c         */
/* ********************************** */
void	free_dp_char(char **dp_char);
void	free_game_struct(t_game *game);
#endif