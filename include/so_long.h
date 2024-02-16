/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: murilo <murilo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 11:08:24 by aconceic          #+#    #+#             */
/*   Updated: 2024/02/16 20:21:05 by murilo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

/* ********************************** */
/*            KEYBOARD CODES          */
/* ********************************** */
# define KB_W 119
# define KB_S 115
# define KB_A 97
# define KB_D 100
# define KB_ESC 65307
# define KB_UP 65362
# define KB_DOWN 65364
# define KB_LEFT 65361
# define KB_RIGHT 65363

/* ********************************** */
/*              SPRITES               */
/* ********************************** */
//walls
# define FLOOR "assets/sheets/tiles/ground2.xpm"
# define MURR "assets/sheets/tiles/murr.xpm"
# define WALL_BL "assets/sheets/tiles/wall_bl.xpm"
# define WALL_BR "assets/sheets/tiles/wall_br.xpm"
# define WALL_C "assets/sheets/tiles/wall_c.xpm"
# define WALL_L "assets/sheets/tiles/wall_l.xpm"
# define WALL_ML "assets/sheets/tiles/wall_ml.xpm"
# define WALL_MR "assets/sheets/tiles/wall_mr.xpm"
# define WALL_R "assets/sheets/tiles/wall_r.xpm"
# define WALL_BC "assets/sheets/tiles/wall_bc.xpm"
//Player
# define SFRONT "assets/sheets/bilu/stop_front.xpm"
# define SBACK "assets/sheets/bilu/stop_back.xpm"
# define SLEFT "assets/sheets/bilu/stop_left.xpm"
# define SRIGHT "assets/sheets/bilu/stop_right.xpm"
# define WBACK "assets/sheets/bilu/walking_back.xpm"
# define WBACK2 "assets/sheets/bilu/walking_back2.xpm"
# define WFRONT "assets/sheets/bilu/walking_front.xpm"
# define WFRONT2 "assets/sheets/bilu/walking_front2.xpm"
# define WLEFT "assets/sheets/bilu/walking_left.xpm"
# define WLEFT2 "assets/sheets/bilu/walking_left2.xpm"
# define WRIGHT "assets/sheets/bilu/walking_right.xpm"
# define WRIGHT2 "assets/sheets/bilu/walking_right2.xpm"
//Collectable (coin)
# define COIN1 "assets/sheets/coin/c1.xpm"
# define COIN2 "assets/sheets/coin/c2.xpm"
# define COIN3 "assets/sheets/coin/c3.xpm"
# define COIN4 "assets/sheets/coin/c4.xpm"
# define COIN5 "assets/sheets/coin/c5.xpm"
# define COIN6 "assets/sheets/coin/c6.xpm"

/* ********************************** */
/*           EXTERNAL LIBS            */
/* ********************************** */
#include <stdlib.h> //malloc(), free(), exit()
#include <fcntl.h> //open()
#include <unistd.h> //read(), write()
#include <stdio.h> //perror()
#include <string.h> //strerror()

/* ********************************** */
/*           IMPORTED FILES           */
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
	void	*img_floor;
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

//For Player
typedef struct s_player
{
	void	*img_sfront;
	void	*img_sback;
	void	*img_sleft;
	void	*img_sright;
	void	*img_wback;
	void	*img_wback2;
	void	*img_wfront;
	void	*img_wfront2;
	void	*img_wleft;
	void	*img_wleft2;
	void	*img_wright;
	void	*img_wright2;
	int		pl_x;
	int		pl_y;
}	t_player;

//For Collectable (Coin)
typedef struct s_coin
{
	void	*c_imgs[6];
	int		coin_pos;
	int		coin_loop;
}	t_coin;

//For Mlx
typedef struct s_mlx_data
{
	void    *connect;
	void    *window;
}   t_mlx_data;

//Game main structure
typedef struct s_game
{
	t_map		*map;
	t_mlx_data	*data_mlx;
	t_player	*player;
	t_coin		*coin;
	int			img_h;
	int			img_w;
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

/* ********************************** */
/*              GAME INIT             */
/*          source/game_init.c        */
/* ********************************** */
void	game_init(t_game *game);
t_game	*game_structs_init(t_game *game);
void	game_get_mapimg(t_game *game);
void	game_get_playerimg(t_game *game);
void	game_get_coinimg(t_game *game);
void	check_nullvalues_pc(t_game *game, char pointers);
void	check_nullvalues_m(t_game *game, char pointers);

/* ********************************** */
/*              GAME UTILS            */
/*          source/game_utils.c       */
/* ********************************** */
int		game_close(t_game *game);

/* ********************************** */
/*             GAME RENDER            */
/*         source/game_render.c       */
/* ********************************** */
int 	game_drawmap(t_game *game);
void 	draw_mapcorners(t_game *game);
void 	draw_mapwallup(t_game *game);
void 	draw_mapwallbottom(t_game *game);
void	draw_mapwall_left(t_game *game);
void	draw_mapwall_right(t_game *game);
void	draw_mapcenter(t_game *game);
void	render_elmt(t_game *game, void *img, int width, int height);
void	render_coin(t_game *game, int width, int height);
void	draw_mapcoins(t_game *game);

/* ********************************** */
/*            GAME COMMANDS           */
/*        source/game_commands.c      */
/* ********************************** */
int		game_commands(t_game *game);
int		game_keypressed(int keypressed, t_game *game);
void	key_up_pressed(t_game *game);
void	key_down_pressed(t_game *game);
void	key_left_pressed(t_game *game);
void	key_right_pressed(t_game *game);
/* ********************************** */
/*            GAME COMMANDS           */
/*        source/game_commands.c      */
/* ********************************** */
int		coin_animation(t_game *game);

/* ********************************** */
/*            FREE FUNCTIONS          */
/*           source/ft_free.c         */
/* ********************************** */
void	free_dp_char(char **dp_char);
void	free_game_struct(t_game *game);
void	free_map_imgptr(t_game *game);
void	free_player_imgptr(t_game *game);
void	free_coin_imgptr(t_game *game);

#endif