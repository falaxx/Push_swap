NAME = libft.a

SRC_PATH = src

SRC_NAME =  ft_memmove.c ft_strlcat.c ft_atoi.c ft_memset.c ft_strlen.c ft_bzero.c ft_putchar.c ft_strmap.c ft_display_file.c ft_putchar_fd.c ft_strmapi.c ft_is_prime.c ft_putendl.c ft_strncat.c ft_isalnum.c ft_putendl_fd.c ft_strncmp.c ft_isalpha.c ft_putnbr.c ft_strncpy.c ft_isascii.c ft_putnbr_fd.c ft_strnequ.c ft_isdigit.c ft_putstr.c ft_strnew.c ft_isprint.c ft_putstr_fd.c ft_strnstr.c ft_itoa.c  ft_sqrt.c ft_strrchr.c ft_lstadd.c ft_strcapitalize.c ft_strsplit.c ft_lstdel.c  ft_strcat.c ft_strstr.c ft_lstdelone.c ft_strchr.c ft_strsub.c ft_lstiter.c ft_memmove.c ft_strclr.c ft_strtrim.c ft_lstmap.c ft_strcmp.c ft_swap.c ft_lstnew.c ft_strcpy.c ft_tolower.c ft_memalloc.c ft_strdel.c ft_toupper.c ft_memccpy.c ft_strdup.c ft_memchr.c  ft_strequ.c ft_memcmp.c ft_striter.c ft_memcpy.c ft_striteri.c ft_memdel.c ft_strjoin.c get_next_line.c ft_getnbr_n.c ft_atol.c ft_strjoinfree.c

OBJ_NAME = $(SRC_NAME:.c=.o)

OBJ_PATH = obj

SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))

OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

HEADER_PATH = includes/

HEADER_NAME = libft.h

HEADER = $(addprefix $(HEADER_PATH)/,$(HEADER_NAME))

all: $(NAME)

$(NAME): $(OBJ)
	@ar rcs $@ $^

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c $(HEADER)
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@gcc  -Wall -Werror -Wextra -I $(HEADER_PATH)  -o $@ -c $<

clean:
	@rm -f $(OBJ)
	@rmdir $(OBJ_PATH) 2> /dev/null || true

fclean: clean
	@rm -f $(NAME)

re: fclean
	$(MAKE) all

.PHONY: make clean fclean re
