#commands and flags
CFLAGS = -Wall -Werror -Wextra
CC = cc
RM = rm -rf

#names
NAME = libftprintf.a

#sources and objects
SRCS =	ft_printf.c	ft_putchar.c ft_putnbr.c ft_putstr.c \
		ft_print_format.c ft_putpointer.c ft_putunbr.c \
		ft_putnbr_hex.c ft_trialhex.c
OBJS = $(SRCS:.c=.o)

### MAKEFILE
all : $(NAME)

$(NAME) : $(OBJS)
#for creating a library
	@ar rc $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re : clean all