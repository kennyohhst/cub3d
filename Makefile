NAME := cub3d
NICKNAME := CUB3D

# Directories
HDR_DIR := include
SRC_DIR := src
OBJ_DIR := obj
LIB_DIR := libft
MLX_DIR := lib/mlx42

# Compiler flags
CC := cc
CFLAGS := -Wall -Werror -Wextra -Ofast -Wunused-result
IFLAGS := -I lib/mlx42/include

# linkers
ifeq ($(shell uname), Darwin)
    ifeq ($(shell uname -m), x86_64)
        LFLAGS = -L/usr/local/lib -lglfw -framework IOKit -framework Cocoa
    else
        LFLAGS = -L/opt/homebrew/lib -lglfw -framework IOKit -framework Cocoa
    endif
else ifeq ($(shell uname), Linux)
    LFLAGS = -ldl -lglfw -pthread -lm
endif

ifeq ($(DEBUG), 1)
    CFLAGS += -g -fsanitize=address
endif

# Includes
HDR_FILES :=	cub3d.h structs.h game_settings.h

MLX42 := $(MLX_DIR)/build/libmlx42.a

# Libft
LIB				:= $(LIB_DIR)/libft.a

# Files
SRC_FILES :=	render/render_main.c \
				render/init.c \
				render/calc_distance.c \
				render/dist_utils.c \
				render/calc_pixels.c \
				render/key_hooks.c \
				render/utils.c\
				parser/main.c \
				parser/parse.c \
				parser/test_parse_data.c \
				parser/search_correct_type.c \
				parser/free_all.c \
				parser/check_game_data.c \
				parser/check_file_extension.c \
				parser/flood_fill.c \
				parser/ft_free_s.c \
				parser/textures_to_pointer.c 

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
all: $(MLX42) ${NAME}

$(NAME): $(OBJ) $(LIB)
	@printf "%b%s%b" "$(YELLOW)$(BOLD)" "Compiling $(NICKNAME)..." "$(RESET)"
	@$(CC) $(CFLAGS) $(OBJ) $(LIB) -o $@ lib/mlx42/build/libmlx42.a $(LFLAGS) $(IFLAGS)
	@printf "\t\t%b%s%b\n" "$(GREEN)$(BOLD)" "[OK]" "$(RESET)"

$(LIB):
	@ make -C $(LIB_DIR)

$(MLX42):
	git submodule update --init
	@cmake $(MLX_DIR) -B $(MLX_DIR)/build
	$(MAKE) -C $(MLX_DIR)/build -j4 --quiet

$(OBJ_DIR)/%.o: src/%.c $(HDR)
	@mkdir -p obj $(@D)
	@$(CC) $(CFLAGS) -I $(HDR_DIR) -c $< -o $@

run: all
	@printf "$(GREEN)--------------\n RUN $(NAME) \n--------------\n$(RESET)"
	@./$(NAME) maps/test_map.cub

debug:
	@$(MAKE) DEBUG=1 all

open: $(NAME)
	@./$(NAME)

norm:
	@norminette $(HDR_DIR) $(SRC)

clean:
	@echo "$(RED)$(BOLD)Cleaning $(NICKNAME)...$(RESET)"
	@rm -rf $(OBJ)
	@rm -rf $(OBJ_DIR)
	@ make $(MAKEFLAGS) clean -C $(LIB_DIR)
	@$(MAKE) clean -C $(MLX_DIR)/build -j4 --quiet

fclean:
	@echo "$(RED)$(BOLD)Fully cleaning $(NICKNAME)...$(RESET)"
	@rm -rf ${NAME}
	@rm -rf $(OBJ)
	@rm -rf $(OBJ_DIR)
	$(MAKE) clean/fast -C $(MLX_DIR)/build -j4 --quiet
	@ make $(MAKEFLAGS) fclean -C $(LIB_DIR)

re: fclean all

.PHONY: all norminette run debug open clean fclean re