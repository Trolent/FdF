# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: trolland <trolland@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/24 16:23:19 by trolland          #+#    #+#              #
#    Updated: 2024/02/17 10:59:53 by trolland         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

LIBFT	= 	libft/libft.a
MLX_LINUX 	=	mlx_Linux/mlx_Linux.a 
MLX_MACOS = libmlx/libmlx.a

OS := $(shell uname)
ifeq ($(OS),Darwin)
    MLX_TARGET = $(MLX_MACOS)
    MLX_PATH = libmlx
    LD_FLAGS = -L$(MLX_PATH) -lmlx -framework OpenGL -framework AppKit
else
    MLX_TARGET = $(MLX_LINUX)
    MLX_PATH = mlx_Linux
    LD_FLAGS = -Lmlx_Linux -lmlx_Linux -lXext -lX11 -lm -lz
endif

SRC :=		fdf.c errors.c free_join.c ft_parse.c graphics.c map_utils.c \
			draw_utils.c key_input.c key_arrow.c key_letter0.c key_letter1.c \
			create_win_mlx.c close_mlx.c rotation.c key_angle.c bresenham.c
			
SRCS := 	$(addprefix src/, $(SRC))
OBJS := 	$(patsubst src/%.c, object/%.o, $(SRCS))
DEPS := 	$(OBJS:.o=.d)


CC := cc

CFLAGS := -MMD -MP -Iincludes -Ilibft -I$(MLX_PATH) -g

all: create_dirs $(NAME)

$(NAME): create_dirs $(OBJS) $(LIBFT) $(MLX_TARGET)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME) $(LD_FLAGS)

mlx: $(LIBFT) $(MLX_TARGET)
	$(CC) $(CFLAGS) minilibx.c $(LIBFT) -o mlx $(LD_FLAGS) 

$(MLX_TARGET):
	$(MAKE) -C $(MLX_PATH)

object/%.o: src/%.c
	@printf "\033[0;32m\tCompiling: $<\033[0m\n";
	@$(CC) $(CFLAGS) -c $< -o $@

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

re: fclean all

-include $(DEPS)

.PHONY: all create_dirs clean fclean
