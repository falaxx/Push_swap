NAME = push_swap

NAME2 = checker

SRC_PATH = src

SRC2_PATH = src2

SRC_NAME = main.c swap.c push.c rotate.c rrotate.c algo.c brute_force.c check_fill.c apply_algo.c find_exit.c

SRC2_NAME = main.c check_fill.c push.c rotate.c rrotate.c swap.c sdl.c apply_color.c

CPPFLAGS = -I libft/includes/ -I /usr/local/include/ -MMD

LDFLAGS = -L libft/ -lft  -L /usr/local/include/

CC = gcc

CFLAGS = -Werror -Wall -Wextra -g 

OBJ_NAME = $(SRC_NAME:.c=.o)

OBJ_NAME2 = $(SRC2_NAME:.c=.o)

OBJ_PATH = obj

OBJ_PATH2 = obj2

SDLFLAGS =  $(SDLINCL) -L/Users/fmerding/.brew/Cellar/sdl2/2.0.9_1/lib -lSDL2

SDLINCL = -I /Users/fmerding/.brew/Cellar/sdl2/2.0.9_1/include/SDL2

HEADER_PATH = includes/

HEADER_NAME = push_swap.h

OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

OBJ2 = $(addprefix $(OBJ_PATH2)/,$(OBJ_NAME2))

SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))

HEADER = $(addprefix $(HEADER_PATH)/,$(HEADER_NAME))

all: $(NAME) $(NAME2)

$(NAME): $(OBJ)
	make -C libft/
	$(CC) $(CFLAGS) $(LDFLAGS) $(SDLFLAGS) $(LDLIBS) $^ -o $@

$(NAME2): $(OBJ2)
	make -C libft/
	$(CC) $(CFLAGS) $(LDFLAGS) $(SDLFLAGS) $(LDLIBS) $^ -o $@

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c | $(OBJ_PATH)
	$(CC) $(CFLAGS) $(CPPFLAGS) -I $(HEADER_PATH) $(SDLINCL)  -o $@ -c $<

$(OBJ_PATH2)/%.o: $(SRC2_PATH)/%.c | $(OBJ_PATH2)
	$(CC) $(CFLAGS) $(CPPFLAGS) -I $(HEADER_PATH) $(SDLINCL) -o $@ -c $<

$(OBJ_PATH):
	@mkdir $(OBJ_PATH) 2> /dev/null || true

$(OBJ_PATH2):
	@mkdir $(OBJ_PATH2) 2> /dev/null || true

clean:
	make clean -C libft/
	rm -f $(OBJ) $(OBJ:.o=.d)
	rm -f $(OBJ2) $(OBJ2:.o=.d)
	@rmdir $(OBJ_PATH2) 2> /dev/null || true
	@rmdir $(OBJ_PATH) 2> /dev/null || true


fclean: clean
	make fclean -C libft/
	rm -f $(NAME)
	rm -f $(NAME2)

re: fclean
	$(MAKE) all

norme:
	norminette $(SRC)
	norminette $(INCLUDES)

.PHONY: make clean fclean re

-include $(OBJ:.o=.d)
