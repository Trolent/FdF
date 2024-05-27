# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: trolland <trolland@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/24 16:23:19 by trolland          #+#    #+#              #
#    Updated: 2024/05/21 01:22:15 by trolland         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

LIBFT	= 	libft/libft.a
MLX_LINUX =	minilibx-linux/libmlx.a 
MLX_MACOS = minilibx-mac-osx/libmlx.a

OS := $(shell uname)
ifeq ($(OS),Darwin)
    MLX_TARGET = $(MLX_MACOS)
    MLX_PATH = minilibx-mac-osx
    LD_FLAGS = -L$(MLX_PATH) -lmlx -framework OpenGL -framework AppKit
else
    MLX_TARGET = $(MLX_LINUX)
    MLX_PATH = minilibx-linux
    LD_FLAGS = -Lminilibx-linux -lmlx -lXext -lX11 -lm -lz
endif

SRC :=		fdf.c errors.c free_join.c ft_parse.c ft_parse2.c graphics.c \
			graphics_utils.c map_utils.c draw_utils.c key_input.c key_range.c \
			key_arrow.c key_lines_spec.c key_views.c create_win_mlx.c \
			close_mlx.c rotation.c bresenham.c menu.c coordinates_utils.c\
			key_angle_x.c key_angle_y.c key_angle_z.c

SRC_PATH = ./src/
SRCS := 	$(addprefix $(SRC_PATH), $(SRC))
OBJS := 	$(patsubst $(SRC_PATH)%.c, object/%.o, $(SRCS))
DEPS := 	$(OBJS:.o=.d)

CC := cc

CFLAGS := -Wall -Werror -Wextra -MMD -MP -Iincludes -Ilibft -I$(MLX_PATH) 

all:	$(NAME)

$(NAME): $(OBJS) $(LIBFT) $(MLX_TARGET)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME) $(LD_FLAGS)

$(MLX_TARGET):
	$(MAKE) -C $(MLX_PATH)

object/%.o: src/%.c
	@if [ ! -d "object" ]; then mkdir object; fi
	@printf "\033[0;32m\tCompiling: $<\033[0m\n";
	@$(CC) $(CFLAGS) -c $< -o $@

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

norm:
	norminette -R CheckDefine includes/*.h
	norminette -R CheckForbiddenSourceHeader src/*.c


-include $(DEPS)

.PHONY: all create_dirs clean fclean re norm
