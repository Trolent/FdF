# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: trolland <trolland@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/24 16:23:19 by trolland          #+#    #+#              #
#    Updated: 2024/02/02 18:00:30 by trolland         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

LIBFT	= 	libft/libft.a
MLX 	=	mlx_Linux/mlx_Linux.a 

SRCS :=		fdf.c errors.c free_join.c ft_parse.c graphics.c map_utils.c
			
SRCS := 	$(addprefix src/, $(SRCS))
OBJS := 	$(patsubst src/%.c, object/%.o, $(SRCS))
DEPS := 	$(OBJS:.o=.d)


CC := cc
CFLAGS := -MMD -MP -Iincludes -Ilibft -Imlx_Linux -g

all: create_dirs $(NAME)

# ifeq (run, $(firstword $(MAKECMDGOALS)))
# 	runargs := $(wordlist 2, $(words $(MAKECMDGOALS)), $(MAKECMDGOALS))
# 	$(eval $(runargs):;@true)
# endif

$(NAME): $(OBJS) $(LIBFT) $(MLX)
	@$(CC) $(CFLAGS) $(OBJS) -Lmlx_Linux -lmlx_Linux $(LIBFT) -Imlx_Linux -lXext -lX11 -lm -lz -o $(NAME)

object/%.o: src/%.c
	@printf "\033[0;32%sm\tCompiling: $<\033[0m\n";
	@$(CC) $(CFLAGS) -c $< -o $@

# run: $(NAME)
# 	@./fdf maps/test_maps/t1.fdf

create_dirs:
	@if [ ! -d "object" ]; then mkdir object; fi

$(LIBFT):
	@$(MAKE) -C libft

$(MLX):
	@$(MAKE) -C mlx_Linux

# run: $(NAME)
# 	./fdf $(runargs)

clean:
	@if [ -d "object" ]; then rm -rf object && echo "\033[1;31mFdf .o files have been deleted\033[0m"; fi
	@$(MAKE) --no-print-directory clean -C libft
	@$(MAKE) --no-print-directory clean -C mlx_Linux

fclean: clean
	@if [ -f "fdf" ]; then rm -rf fdf && echo "\033[1;31mFdf executable has been deleted\033[0m"; fi
	@$(MAKE) --no-print-directory fclean -C libft

re: fclean all

-include $(DEPS)

.PHONY: all create_dirs clean fclean