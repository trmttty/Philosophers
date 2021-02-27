CC			= gcc
FLAGS		= -Wall -Wextra -Werror
LIBS		= -lpthread
NAME 		= philo_three
OBJ_DIR 	= ./objs/

SRC_RT = main.c \
			action.c \
			display.c \
			init.c \
			launch.c \
			monitor.c \
			time.c \
			exit.c \
			clear.c \
			utils_1.c \
			utils_2.c

OBJ_RT = $(addprefix $(OBJ_DIR),$(SRC_RT:%.c=%.o))
OBJ = $(OBJ_RT)

all : $(NAME)

$(NAME) : $(OBJ_DIR) $(OBJ_RT)
	$(CC) $(FLAGS) $(LIBS) $(OBJ) -o $@

$(OBJ_DIR) :
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)%.o : $(SRC_RT_DIR)%.c
	$(CC) $(FLAGS) -o $@ -c $<

clean :
	rm -rf $(OBJ_DIR)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY: all clean fclean re
