/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: murilo <murilo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 10:29:11 by murilo            #+#    #+#             */
/*   Updated: 2024/03/02 20:06:48 by murilo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "../include/so_long.h"
# include <stdio.h>

/* ********************************** */
/*            SPRITES BONUS           */
/* ********************************** */
# define H_SFRONT "assets/sheets/enemy/sfront.xpm"
# define H_WFRONT "assets/sheets/enemy/wfront.xpm"
# define H_WFRONT2 "assets/sheets/enemy/wfront2.xpm"
# define H_WBACK "assets/sheets/enemy/wback.xpm"
# define H_WBACK2 "assets/sheets/enemy/wback2.xpm"
# define H_WLEFT "assets/sheets/enemy/wleft.xpm"
# define H_WLEFT2 "assets/sheets/enemy/wleft2.xpm"
# define H_WRIGHT "assets/sheets/enemy/wright.xpm"
# define H_WRIGHT2 "assets/sheets/enemy/wright2.xpm"

/* ********************************** */
/*             STRUCT BONUS           */
/* ********************************** */
//for enemy **ht is for HOSTILE
typedef struct s_bonus
{
	void	*ht_img[9];
	int		ht_y;
	int		ht_x;
	int		ht_loop;
	int		pl2_lstep;
	int		ht_isoncoin;
	int		hpos_x;
	int		hpos_y;
	char	chprevious;
	t_game	*game_main;
}			t_gmbonus;

/* ********************************** */
/*             MAIN BONUS             */
/* ********************************** */
int			main(int argv, char **argc);

/* ********************************** */
/*            GAME INIT BONUS         */
/*         bonus/game_init_bonus.c    */
/* ********************************** */
t_gmbonus	*game_init_bonus(t_game *game);
t_gmbonus	*bonus_init_enemystruct(t_game *game);

/* ********************************** */
/*            GAME DRAW BONUS         */
/*         bonus/game_draw_bonus.c    */
/* ********************************** */
int			game_drawmap_bonus(t_game *game);
int			game_draw_fenemy(t_gmbonus *bonus);

/* ********************************** */
/*            GET IMG BONUS           */
/*         bonus/get_img_bonus.c.c    */
/* ********************************** */
void		get_enemyimg(t_gmbonus *h, t_game *game);

/* ********************************** */
/*            GAME PLAY BONUS         */
/*         bonus/game_play_bonus.c    */
/* ********************************** */
int			game_play_bonus(t_gmbonus *bonus);
int			game_keypressed_bonus(int keypressed, t_gmbonus *bonus);
int			p1_keypressed(t_gmbonus *bonus, int keypressed);
int			p2_keypressed(t_gmbonus *bonus, int keypressed);
void		render_message(t_gmbonus *bonus, int flag);

/* ********************************** */
/*            GAME PLAY2 BONUS         */
/*         bonus/game_play2_bonus.c    */
/* ********************************** */
void		p2key_up_pressed(t_gmbonus *bn, t_game *game, char **map_sk);
void		p2key_down_pressed(t_gmbonus *bn, t_game *game, char **map_sk);
void		p2key_left_pressed(t_gmbonus *bn, t_game *game, char **map_sk);
void		p2key_right_pressed(t_gmbonus *bn, t_game *game, char **map_sk);

/* ********************************** */
/*              FREE BONUS            */
/*          bonus/free_bonus.c        */
/* ********************************** */
int			game_close_bonus(t_gmbonus *bonus);
void		free_enemy_imgptr(t_gmbonus *bonus);

/* ********************************** */
/*           ANIMATION BONUS          */
/*       bonus/animation_bonus.c      */
/* ********************************** */
int			coin_animation_bonus(t_gmbonus *bonus);
void		draw_mapcoins_bonus(t_gmbonus *bonus);
void		draw_enemy_isoncoin(t_gmbonus *bonus);
void		turnh_toc(t_gmbonus *bonus);

#endif