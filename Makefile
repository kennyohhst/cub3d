NAME := cub3d
NICKNAME := CUB3D

# Directories
HDR_DIR := include
SRC_DIR := src
OBJ_DIR := obj
LIB_DIR := libft

# Compiler flags
CC := cc
CFLAGS := -Wall -Werror -Wextra -g 
#CFLAGS +=	-fsanitize=address
# CFLAGS +=	-fsanitize=thread

# Includes
HDR_FILES :=	cub3d.h

# Libft
LIB				:= $(LIB_DIR)/libft.a


# Files
SRC_FILES :=	main.c parse.c test_parse_data.c

SRC := $(addprefix $(SRC_DIR)/, $(SRC_FILES))
OBJ := ${addprefix ${OBJ_DIR}/, ${SRC_FILES:.c=.o}}
HDR := $(addprefix $(HDR_DIR)/, $(HDR_FILES))

# Colours
GREEN	:= \033[32;1m
YELLOW	:= \033[33;1m
RED		:= \033[31;1m
BOLD	:= \033[1m
RESET	:= \033[0m

# Rules
all: ${NAME}

$(NAME): $(OBJ) $(LIB)
	@printf "%b%s%b" "$(YELLOW)$(BOLD)" "Compiling $(NICKNAME)..." "$(RESET)"
	@gcc $(CFLAGS) $(OBJ) $(LIB) -o $@ MLX42/build/libmlx42.a -ldl -lglfw -lm -pthread -I MLX42/include
	@printf "\t\t%b%s%b\n" "$(GREEN)$(BOLD)" "[OK]" "$(RESET)"
	# @gcc $(CFLAGS) $(OBJ) -o $(NAME) -lpthread

$(LIB):
	@ make -C $(LIB_DIR)

$(OBJ_DIR)/%.o: src/%.c $(HDR)
	@mkdir -p obj
	@gcc $(CFLAGS) -I $(HDR_DIR) -c $< -o $@

open: $(NAME)
	@./$(NAME)

norm:
	@norminette $(HDR_DIR) $(SRC)

clean:
	@echo "$(RED)$(BOLD)Cleaning $(NICKNAME)...$(RESET)"
	@rm -rf $(OBJ)
	@rm -rf $(OBJ_DIR)
	@ make $(MAKEFLAGS) clean -C $(LIB_DIR)


fclean:
	@echo "$(RED)$(BOLD)Fully cleaning $(NICKNAME)...$(RESET)"
	@rm -rf ${NAME}
	@rm -rf $(OBJ)
	@rm -rf $(OBJ_DIR)
	@ make $(MAKEFLAGS) fclean -C $(LIB_DIR)



re: fclean ${NAME}

.PHONY: all norminette clean fclean re