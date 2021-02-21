CC			= gcc
FLAGS		= -Wall -Wextra -Werror
LIBS		= -lpthread
NAME 		= philo_two
DIR_LIB		= libft
LIBFT		= $(DIR_LIB)/libft.a
OBJ_DIR 	= ./objs/

SRC_RT = main.c \
			action.c \
			display.c \
			init.c \
			launch.c \
			monitor.c \
			time.c \
			error.c \
			utils.c

OBJ_RT = $(addprefix $(OBJ_DIR),$(SRC_RT:%.c=%.o))
OBJ = $(OBJ_RT)

all : $(NAME)

$(NAME) : $(LIBFT) $(OBJ_DIR) $(OBJ_RT)
	$(CC) $(FLAGS) -L libft -lft $(LIBS) $(OBJ) -o $@

$(OBJ_DIR) :
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)%.o : $(SRC_RT_DIR)%.c
	$(CC) $(FLAGS) -o $@ -c $<

$(LIBFT):
	make bonus -C $(DIR_LIB)

clean :
	make clean -C $(DIR_LIB)
	rm -rf $(OBJ_DIR)

fclean : clean
	make fclean -C $(DIR_LIB)
	rm -f $(NAME)

re : fclean all

.PHONY: all clean fclean re run
