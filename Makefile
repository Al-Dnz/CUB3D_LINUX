SRCS =	main.c \
		main_util.c \
		draw_util.c \
		map_parser.c \
		map_array_generator.c \
		map_util.c \
		map_error.c \
		key_handler.c \
		game_process.c \
		move_handler.c \
		raycasting_init.c \
		raycasting_operation.c \
		graphic_engine.c \
		texture_handler.c \
		texture_util.c \
		texture_util2.c \
		sprite_handler.c \
		sprite_util.c \
		save_handler.c \
		hud_handler.c \
		exit_process.c \
		cub3d_util.c \
		main_initialisation.c \
		main_parser.c \
		set_parameters.c \
		set_map.c

NAME	=	cub3D
CC		=	clang
FLAGS	=	-O3 -Wall -Wextra -Werror
INC		=	inc
OBJ		=	obj
SRC		=	src
LIBFT	=	libft
LIBMLX	=	libmlx
INCS	=	$(addprefix $(INC)/, header.h)
OBJS	=	$(addprefix $(OBJ)/, $(SRCS:.c=.o))

all: init $(NAME)

init:
	mkdir -p $(OBJ)
	make -C $(LIBFT)
	make -C $(LIBMLX)

$(NAME): $(OBJS) $(INCS)
	$(CC) $(FLAGS) -I$(INC) -o $(NAME) $(OBJS) -Llibft -lft -Llibmlx -lmlx -lX11 -lbsd -lm -lXext
	@echo "\n------------------------------"
	@echo "| => $(NAME) well created ! <= |"
	@echo "------------------------------\n"

$(OBJ)/%.o: $(SRC)/%.c $(INCS)
	$(CC) $(FLAGS) -I$(INC) -c $< -o $@

clean:
	rm -rf $(OBJ)
	make -C $(LIBFT) clean
	make -C $(LIBMLX) clean
	@echo "obj deleted"

fclean: clean
	rm -rf $(NAME)
	make -C $(LIBFT) fclean
	@echo "\n=> [$(NAME)]: deleted <=\n"

re: fclean all
