# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: murilo <murilo@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/24 16:10:12 by aconceic          #+#    #+#              #
#    Updated: 2024/02/18 13:14:40 by murilo           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

##############################################
#                  COLORS                    #
##############################################
GREEN = \e[0;32m
BLUE = \e[1;034m
RED = \e[0;31m
MAGENTA = \033[1;35m
ORANGE = \033[1;38;5;208m
RESET = \e[0m
##############################################
#                  COMMANDS                  #
##############################################
MAKEC = make -C
MAKECLEANC = make clean -C
RM = rm -rf
##############################################
#                 MAIN SOURCES               #
##############################################
#Libraryes
LIBFT_DIR = library/libft/
LIBFT_LIB = $(LIBFT_DIR)libft.a
PRINTF_DIR = $(LIBFT_DIR)/ft_printf
GNL_DIR = $(LIBFT_DIR)get_next_line/
GNL_LIB = $(GNL_DIR)gnl.a

#Project
NAME = so_long
OBJ_DIR = ./objs/
OBJ = $(addprefix $(OBJ_DIR), $(SRC:.c=.o))
SRC_DIR = ./source/
SRC = 	map_validation.c ft_utils.c game_utils.c \
		game_init.c game_play.c ft_free.c map_init.c \
		game_render.c game_animation.c game_draw.c game_draw2.c\

##############################################
#                  MiniLibX                  #
##############################################
##DIR FOR MLX HAVING IN CONSIDERATION THE OS
MLX_DIR = library/minilibx-linux/
##FLAGS FOR MLX HAVING IN CONSIDERATION THE OS
MLXFLAGS = -L $(MLX_DIR) -lm -lmlx -Ilmlx -lXext -lX11
##############################################
#                COMPILATION                 #
##############################################
CC = cc
GCC = cc -g
CFLAGS = -Wall -Wextra -Werror
##############################################
#                                            #
#                   RULES                    #
#                MAIN PROJECT                #
##############################################
all : mlx_compile $(NAME)

mlx_compile :
	@echo "$(ORANGE)[!]$(RESET) Working on MiniLibX ..."
	$(MAKEC) $(MLX_DIR)

$(OBJ_DIR) :
	@echo "$(ORANGE)[!]$(RESET) Creating directory for objects ..."
	mkdir $@

$(NAME) : $(OBJ) $(LIBFT_LIB)
	@echo "$(ORANGE)[!]$(RESET) Working on project ... "
	$(CC) $(CFLAGS) $(OBJ) $(SRC_DIR)main.c $(LIBFT_LIB) $(GNL_LIB) $(MLXFLAGS) -o $(NAME)
	@echo "$(GREEN)[✔]$(RESET) $(BLUE)Ok!$(RESET) "

$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJ_DIR)
	@echo "$(ORANGE)[!]$(RESET) Creating objects ..."
	$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(GREEN)[✔]$(RESET) $(BLUE)Objects Ok!$(RESET) "

$(LIBFT_LIB) : $(LIBFT_DIR)
	@echo "$(ORANGE)[!]$(RESET) Working on LIBFT_LIB ..."
	$(MAKEC) $(LIBFT_DIR) bonus
	$(MAKEC) $(PRINTF_DIR)
	$(MAKEC) $(GNL_DIR)
	@echo "$(GREEN)[✔]$(RESET) $(BLUE)LIBFT Ok!$(RESET)"

clean :
	@echo "$(ORANGE)[!]$(RESET) Executing cleaning ..."
	$(RM) $(OBJ_DIR)
	$(MAKECLEANC) $(LIBFT_DIR)
	$(MAKECLEANC) $(MLX_DIR)
	@echo "$(GREEN)[✔]$(RESET) $(BLUE)Cleaning Ok!$(RESET) "

fclean :
	@echo "$(ORANGE)[!]$(RESET) Executing full cleaning..."
	$(RM) $(NAME) $(OBJ_DIR)
	make fclean -C $(LIBFT_DIR)
	$(MAKECLEANC) $(MLX_DIR)
	@echo "$(GREEN)[✔]$(RESET) $(BLUE)full cleaning!$(RESET) "

re : fclean all
	@echo "$(GREEN)[✔]$(RESET) $(MAGENTA)Refresh Ok!$(RESET) "

.SILENT:
.PHONY: all clean fclean re mlx_compile 
#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~#
#              NOTES AND REMINDERS           #
#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~#
#        $< represent the prerequisite       #
#        $@ represent the target             #
#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~#