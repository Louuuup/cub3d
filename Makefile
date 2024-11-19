# **************************************************************************** #
#			                                                                     #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ycyr-roy <ycyr-roy@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/14 15:09:39 by yakary            #+#    #+#              #
#    Updated: 2023/07/13 22:16:59 by ycyr-roy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d
MUTE = @
#==============================================================================#
CC = gcc
# CFLAGS = -Wall -Werror -Wextra -Wun reachable-code -Ofast
CFLAGS = 
SRC = \
    main.c error_handler.c garbage_handler.c garbage_tools.c init.c parsing.c \
	utils_test.c utils.c hooks.c minimap.c movements.c textures.c \
	texture_utils.c raycasting.c reload.c print3d.c
#==============================================================================#
SRCS = $(addprefix $(SRC_DIR)/, $(SRC))
OBJS = $(addprefix $(BIN_DIR)/, $(SRC:.c=.o))
#==============================================================================#
MLX_REPO = $(if $(wildcard $(MLX_DIR)),,mlx_install)
#==============================================================================#
SRC_DIR     = src
BIN_DIR     = bin
INC_DIR     = include
MLX_DIR     = lib/MLX42
MLX42       = $(MLX_DIR)/build/libmlx42.a
LIBFT_DIR   = lib/libft
LIBFT       = $(LIBFT_DIR)/libft.a
#Shell cmd
MKDIRP = mkdir -p
RM = rm -f
RM_DIR = rm -rf
#==============================================================================#
# headers to include
INCLUDES = -I$(LIBFT_DIR) -I$(INC_DIR) -I$(MLX_DIR)/$(INC_DIR)
# things to link
LFLAGS = -L$(GLFW_DIR) $(MLX42) $(LIBFT)
# more things to link (OS check)
ifeq ($(shell uname),Linux)
    LFLAGS += -lglfw -ldl -pthread -lm
else
    LFLAGS += -framework Cocoa -framework OpenGL -framework IOKit -lglfw
    CFLAGS += -Wall -Werror -Wextra
endif
# finding glfw (test commented shell command under this)
ifeq ($(shell uname),Linux)
    GLFW_DIR = /usr/lib
else ifeq ($(shell uname),Darwin)
    GLFW_DIR = /Users/$(USER)/.brew/lib
else
    $(error Unsupported operating system: $(shell uname))
endif
#   GLFW_DIR = $(shell brew --prefix glfw)/lib
# (to try instead of GLFW_DIR = /Users/$(USER)/.brew/lib)
#==============================================================================#
all: mlx42 libft $(NAME)
$(BIN_DIR)/%.o: $(SRC_DIR)/%.c
	@echo "$(BLUE)$(BOLD)✅Compiling $(YELLOW)cub3d $(BLUE)→ $(RESET)$(CYAN)$(notdir $<)                    $(RESET)"
	@$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)
	@printf	$(UP)$(CUT)
$(NAME): $(BIN_DIR) $(OBJS)
	@$(CC) $(CFLAGS) -o $@ $(OBJS) $(LFLAGS)
	@echo "$(GREEN)$(BOLD)✅ Successfully compiled $(YELLOW)cub3d                         $ (RESET)"
$(BIN_DIR):
	@$(MKDIRP) $(BIN_DIR)
libft:
	@$(MAKE) -C $(LIBFT_DIR)
mlx_install:
	@echo "$(YELLOW)$(BOLD)🚧 Installing $(PURPLE)MLX42$(YELLOW)🚧$(RESET)"
	@cd lib && git clone https://github.com/codam-coding-college/MLX42.git
	@echo "$(GREEN)$(BOLD)✅ Successfully installed $(PURPLE)MLX42$(RESET)"
	@printf $(UP)$(CUT)
mlx_compile: 
	@cd lib/MLX42 && cmake -B build
	@cd lib/MLX42 && cmake --build build -j4
	@echo "$(GREEN)$(BOLD)✅ Successfully compiled $(PURPLE)MLX42$(RESET)"
	@printf $(UP)$(CUT)
mlx42: $(MLX_REPO) mlx_compile
	@cmake -S $(MLX_DIR) -B $(MLX_DIR)/build && make -C $(MLX_DIR)/build -j4
	@echo "$(GREEN)$(BOLD)✅ Successfully compiled $(PURPLE)MLX42$(RESET)"
	@printf $(UP)$(CUT)
bonus: all
	@echo "\n🤯YOO THEY ASKED FOR BONUS OMG🤯\n"
clean:
	@$(RM) $(OBJS)
	@$(RM_DIR) $(BIN_DIR)
	@$(MAKE) -C $(LIBFT_DIR) clean
	@echo "$(GREEN)$(BOLD)✅ Cleaned $(YELLOW)cub3d$(RESET)"
fclean: clean
	@$(RM) $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@echo "$(GREEN)$(BOLD)✅ Fully cleaned $(YELLOW)cub3d$(RESET)"
mlx_clean:
	@$(RM_DIR) $(MLX_DIR)
ffclean: fclean rclean
	@echo "$(GREEN)$(BOLD)✅ Fully Fully cleaned $(YELLOW)cub3d$(RESET)"
norm:
	@norminette $(SRC_DIR) $(INC_DIR)
run: all
	@./$(NAME) maps/big.cub

re: fclean all
#====================================MAN==========================================#
help man:
	$(MUTE)echo "$(BOLD)$(GREEN)---------------------------------------------------------------$(RESET)"
	$(MUTE)echo "$(BOLD)$(YELLOW)                       Welcome to $(PURPLE)$(BOLD)Cub3D                         $(RESET)"
	$(MUTE)echo "$(BOLD)$(GREEN)---------------------------------------------------------------$(RESET)"
	$(MUTE)echo ""
	$(MUTE)echo "$(BOLD)$(CYAN) Available Options:$(RESET)"
	$(MUTE)echo ""
	$(MUTE)echo "$(BOLD)  make (all)$(RESET)     - Compile the main program and dependencies"
	$(MUTE)echo "$(BOLD)  make run$(RESET)       - Compiles and runs the ./minishel program"
	$(MUTE)echo "$(BOLD)  make clean$(RESET)     - Remove compiled object files"
	$(MUTE)echo "$(BOLD)  make fclean$(RESET)    - Remove compiled files and executable"
	$(MUTE)echo "$(BOLD)  make mlx_clean$(RESET) - Remove the MLX42 library"
	$(MUTE)echo "$(BOLD)  make mlx42$(RESET)     - Install and compile the MLX42 library"
	$(MUTE)echo "$(BOLD)  make re$(RESET)        - Remove all compiled files and recompile"
	$(MUTE)echo "$(BOLD)  make norm$(RESET)      - Run norminette for coding style"
	$(MUTE)echo ""
	$(MUTE)echo "$(BOLD)$(CYAN) Debug Options:$(RESET)"
	$(MUTE)echo ""
	$(MUTE)echo "$(BOLD)  make libft$(RESET)    - Compile only the library"
	$(MUTE)echo ""
	$(MUTE)echo "$(BOLD)$(GREEN)---------------------------------------------------------------$(RESET)"

.PHONY: all clean fclean re libft mlx42 bonus
#=====================================COLORS=====================================#
# Colors
BLACK		=\033[30m
RED			=\033[31m
GREEN       =\033[32m
YELLOW      =\033[33m
BLUE        =\033[34m
PURPLE      =\033[35m
CYAN        =\033[36m
WHITE       =\033[37m
# Text
ERASE       =\033[2K
RESET       =\033[0m
BOLD        =\033[1m
FAINT       =\033[2m
ITALIC      =\033[3m
UNDERLINE   =\033[4m
INVERT      =\033[7m
STRIKE      =\033[9m
# Background
BG_BLACK    =\033[40m
BG_RED      =\033[41m
BG_GREEN    =\033[42m
BG_YELLOW   =\033[43m
BG_BLUE     =\033[44m
BG_PURPLE   =\033[45m
BG_CYAN     =\033[46m
BG_WHITE    =\033[47m
# Others
UP    ="\033[A" # cursor up
CUT   ="\033[K" # cut line
#==============================================================================#
