NAME 		=	philo
CC			=	gcc
CFLAGS		=	-I include/ -Wall -Werror -Wextra
SRC 		= 	$(addprefix src/, $(FILES))
HEADER 		=	$(addprefix include/, $(H_FILES))
OBJ 		=	$(SRC:.c=.o)
LIBS 		=	-lpthread
FILES 		=	main.c \
				utils.c \
				parsing.c \
				init.c \
				exit.c \
				log.c \
				forks.c \
				routine.c \
				ft_usleep.c \
				check_death.c
H_FILES 	= philo.h

RED			=	\033[0;31m
GREEN		=	\033[0;32m
WHITE		=	\033[0m

all: $(NAME)

$(NAME): $(OBJ) $(HEADER)
	@printf "[ $(NAME) ] Compiling...\r"
	@($(CC) -o $(NAME) $(SRC) $(LIBS) $(CFLAGS))

clean:
	@rm -f $(OBJ)
	@printf "Object files ${RED}removed\n${WHITE}"

fclean: clean
	@rm -f $(NAME)
	@printf "[ $(NAME) ] ${RED}removed\n${WHITE}"

re: fclean all

.PHONY: all clean fclean re