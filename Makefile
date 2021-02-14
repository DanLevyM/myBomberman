CC =		gcc

CFLAGS =	$(shell sdl2-config --cflags --libs)

RM =		rm -f

NAME =		prog

SRC =		main.c
OBJS =		$(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	@$(CC) -o $(NAME) $(OBJS) $(CFLAGS)
	@printf "[\033[0;36mbuilt\033[0m] %42s\n" $(NAME) | tr ' ' '.'

clean :
	@$(RM) $(OBJS)
	@printf "[\033[0;31mdeleted\033[0m] %40s\n" $(OBJS) | tr ' ' '.'

fclean : clean
	@$(RM) $(NAME) *.c~ *.o~
	@printf "[\033[0;31mdeleted\033[0m] %40s\n" $(NAME) | tr ' ' '.'

re : fclean all

.PHONY : all clean fclean re
