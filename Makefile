NAME = fdf

HEADER = fdf.h

SOURCES = display.c map_parsing.c img_utils.c math_utils.c points_utils.c angle_utils.c free_utils.c

OBJECTS = $(SOURCES:.c=.o)

LIB = libft.a

GCC_FLAGS = -Wall -Wextra -Werror -g -O3 -flto -ffast-math -march=native

CC = cc

all: $(NAME)

$(NAME): $(OBJECTS) $(LIB)
	@make display
	@echo "Compiling $(NAME)..."
	@$(CC) $(GCC_FLAGS) $(OBJECTS) $(LIB) -Lmlx -lmlx -lm -framework OpenGL -framework AppKit -o $(NAME)
	@echo "\033[0;32m"
	@echo " _____ ____  _____   ____  _____    _    ______   __"
	@echo "|  ___|  _ \|  ___| |  _ \| ____|  / \  |  _ \ \ / /"
	@echo "| |_  | | | | |_    | |_) |  _|   / _ \ | | | \ V / "
	@echo "|  _| | |_| |  _|   |  _ <| |___ / ___ \| |_| || |  "
	@echo "|_|   |____/|_|     |_| \_\_____/_/   \_\____/ |_| \n"
	@echo "\033[0m"
	@make usage

$(OBJECTS): $(SOURCES) $(HEADER)
	@$(CC) $(GCC_FLAGS) -c -Imlx -I $(HEADER) ${@:.o=.c} -o $@

$(LIB):
	@echo "Compiling Libft..."
	@make -C libft
	@cp libft/libft.a libft.a

clean:
	@echo "Temp files cleaning..."
	@rm -f $(OBJECTS)
	@echo "Temp files cleaning done !\n"

fclean:
	@echo "Cleaning all..."
	@rm -f $(NAME) $(OBJECTS) $(LIB)
	@echo "Cleaning done !\n"

display:
	@echo "^V^V^V^V^V^V^V^V^V^V^V^V^V^V^V^V^V^V^V^V^V^V^V^V^V^V^V^V^V^V^\n"

usage:
	@echo "Usage: ./fdf <map>\n"

re: fclean all

.PHONY: all clean fclean re display
