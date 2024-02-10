# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: trolland <trolland@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/24 16:23:19 by trolland          #+#    #+#              #
#    Updated: 2024/02/10 13:00:32 by trolland         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

LIBFT	= 	libft/libft.a
MLX_LINUX 	=	mlx_Linux/mlx_Linux.a 
MLX_MACOS = libmlx/libmlx.a

SRC :=		fdf.c errors.c free_join.c ft_parse.c graphics.c map_utils.c
			
SRCS := 	$(addprefix src/, $(SRC))
OBJS := 	$(patsubst src/%.c, object/%.o, $(SRCS))
DEPS := 	$(OBJS:.o=.d)

OS := $(shell uname)

CC := cc

all: create_dirs $(NAME)

# ifeq (run, $(firstword $(MAKECMDGOALS)))
# 	runargs := $(wordlist 2, $(words $(MAKECMDGOALS)), $(MAKECMDGOALS))
# 	$(eval $(runargs):;@true)
# endif

ifeq ($(OS),Darwin)
    MLX_TARGET = $(MLX_MACOS)
    MLX_PATH = libmlx
	LD_FLAGS = -L$(MLX_PATH) -lmlx -framework OpenGL -framework AppKit
else
    MLX_TARGET = $(MLX_LINUX)
    MLX_PATH = mlx_Linux
    LD_FLAGS = -Lmlx_Linux -lmlx_Linux -lXext -lX11 -lm -lz
endif

CFLAGS := -MMD -MP -Iincludes -Ilibft -I$(MLX_PATH) -g -v

all: create_dirs $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(MLX_TARGET)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME) $(LD_FLAGS)

mlx: $(LIBFT) $(MLX_TARGET)
	$(CC) $(CFLAGS) minilibx.c $(LIBFT) -o mlx -L$(MLX_PATH) -l$(MLX_TARGET) $(LD_FLAGS)

$(MLX_TARGET):
	$(MAKE) -C $(MLX_PATH)



# $(NAME): $(OBJS) $(LIBFT) $(MLX_LINUX)
# 	@$(CC) $(CFLAGS) $(OBJS) -Lmlx_Linux -lmlx_Linux $(LIBFT) -Imlx_Linux -lXext -lX11 -lm -lz -o $(NAME)

# mlx:  $(LIBFT) $(MLX_LINUX) 
# 	@$(CC) $(CFLAGS) minilibx.c -Lmlx_Linux -lmlx_Linux $(LIBFT) -Imlx_Linux -lXext -lX11 -lm -lz -o mlx
# $(MLX_LINUX):
#	@$(MAKE) -C mlx_macos
		
object/%.o: src/%.c
	@printf "\033[0;32m\tCompiling: $<\033[0m\n";
	@$(CC) $(CFLAGS) -c $< -o $@

# run: $(NAME)
# 	@./fdf maps/test_maps/t1.fdf

create_dirs:
	@if [ ! -d "object" ]; then mkdir object; fi

$(LIBFT):
	@$(MAKE) -C libft

clean:
	@rm -rf object
	@$(MAKE) --no-print-directory clean -C libft
	@$(MAKE) --no-print-directory clean -C $(MLX_PATH)

fclean: clean
	@rm -f $(NAME) mlx
	@$(MAKE) --no-print-directory fclean -C libft

# clean:
# 	@if [ -d "object" ]; then rm -rf object && echo "\033[1;31mFdf .o files have been deleted\033[0m"; fi
# 	@$(MAKE) --no-print-directory clean -C libft
# 	@if [ "$(OS)" = "Darwin" ]; then \
# 		$(MAKE) --no-print-directory clean -C mlx_macos; \
# 	else \
# 		$(MAKE) --no-print-directory clean -C mlx_Linux; \
# 	fi

# fclean: clean
# 	@if [ -f "fdf" ]; then rm -rf fdf mlx && echo "\033[1;31mFdf executable has been deleted\033[0m"; fi
# 	@$(MAKE) --no-print-directory fclean -C libft

re: fclean all

-include $(DEPS)

.PHONY: all create_dirs clean fclean