# Program name
NAME = fractol

# Colors
GREEN = \033[32m
RED = \033[31m 
RESET = \033[0m

# Compile flags
CC = cc
CFLAGS = -Wall -Wextra -Werror
MLX_FLAGS = -lXext -lX11 -lm -lz

# Libft
LIBFT_DIR = libft/
LIBFT = $(LIBFT_DIR)libft.a

# MLX
MLX_DIR = minilibx-linux/
MLX = $(MLX_DIR)libmlx.a

# printf
PRINTF_DIR = ft_printf/
PRINTF = $(PRINTF_DIR)libftprintf.a

# Source files
SRCS_DIR = srcs/
SRCS = $(SRCS_DIR)fractol.c $(SRCS_DIR)fractals.c $(SRCS_DIR)events.c $(SRCS_DIR)parse.c $(SRCS_DIR)utils.c $(SRCS_DIR)args.c $(SRCS_DIR)init.c $(SRCS_DIR)color.c

# Object files
OBJS_DIR = build/
OBJS = $(SRCS:$(SRCS_DIR)%.c=$(OBJS_DIR)%.o)

# Include directories
INCLUDES = -I ./includes/ \
			-I ./libft/

# Targets
all: $(NAME)

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c
	@mkdir -p $(OBJS_DIR)
	@echo "Compiling $<..."
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(NAME): $(OBJS) $(LIBFT) $(MLX) $(PRINTF)
	@echo "Linking $@..."
	@$(CC) $(CFLAGS) -o $@ $(OBJS) $(LIBFT) $(PRINTF) $(MLX) $(MLX_FLAGS)
	@echo "$(GREEN)$@ ready!$(RESET)"

$(LIBFT):
	@echo "Making libft..."
	@make -C $(LIBFT_DIR)

$(MLX):
	@echo "Making MinilibX..."
	@make -C $(MLX_DIR)

$(PRINTF):
	@echo "Making ft_printf..."
	@make -C $(PRINTF_DIR)

clean:
	@echo "$(RED)Cleaning object files...$(RESET)"
	@rm -rf $(OBJS_DIR)
	@make clean -C $(LIBFT_DIR)
	@make clean -C $(MLX_DIR)
	@make clean -C $(PRINTF_DIR)

fclean: clean
	@echo "$(RED)Cleaning fractol, libft and printf...$(RESET)"
	@rm -f $(NAME)
	@make -C $(LIBFT_DIR) fclean
	@make fclean -C $(PRINTF_DIR)

re: fclean all