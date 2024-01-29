##### Compilation #####
CC = cc
CFLAGS = -Wall -Werror -Wextra

##### Commands #####
RM = rm -rf

###### Files #####
SRCS = 	get_next_line.c \
		get_next_line_utils.c \

OBJS = $(SRCS:.c=.o)

NAME = gnl.a

all: $(NAME)

$(NAME) : $(OBJS)
#	$(CC) $(CFLAGS) main.c $(OBJS) -o $(NAME)
	@ar rc $(NAME) $(OBJS)

clean : 
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.SILENT :