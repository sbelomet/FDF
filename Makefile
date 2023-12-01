# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sbelomet <sbelomet@42lausanne.ch>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/24 14:19:27 by sbelomet          #+#    #+#              #
#    Updated: 2023/12/01 10:49:37 by sbelomet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Variables

NAME		=	fdf
HEADERS		=	-I includes
SRC_DIR		=	srcs/
OBJ_DIR		=	objs/
LIBFTPRINTF	=	libs/ft_printf/libftprintf.a
MINILIBX	=	libs/minilibx_macos/libmlx.a
MINILIBXCC	=	-I mlx -L libs/minilibx_macos -lmlx
OPENGL		=	-framework OpenGL -framework AppKit
CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror

# Colors

RED 		=	\033[1;91m
YELLOW		=	\033[1;93m
GREEN		=	\033[1;92m
BLUE		=	\033[1;94m
PURPLE		=	\033[1;95m
DEF_COLOR	=	\033[0;39m
GRAY		=	\033[0;90m
MAGENTA		=	\033[0;95m
CYAN		=	\033[1;96m
WHITE		=	\033[0;97m
RAINBOW		=	$(RED)-$(YELLOW)-$(GREEN)-$(CYAN)-$(BLUE)-$(PURPLE)-

#Sources

FILES	=	main line_drawing palette_utils1 get_next_line get_next_line_utils drawing \
			coords_utils1
SRC		=	$(addprefix $(SRC_DIR), $(addsuffix .c, $(FILES)))
OBJ		=	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(FILES)))

#Commands

all:			$(OBJ_DIR) $(NAME)

makelibs:
				@echo "$(RAINBOW)$(RAINBOW)$(RAINBOW)$(DEF_COLOR)"
				@make -C libs/ft_printf
				@make -sC libs/minilibx_macos

$(NAME):		makelibs $(OBJ)
				@echo "$(RAINBOW)$(RAINBOW)$(RAINBOW)$(DEF_COLOR)"
				$(CC) $(CFLAGS) $(OBJ) $(HEADERS) $(LIBFTPRINTF) $(MINILIBXCC) $(OPENGL) -o $(NAME)
				@echo ""
				@echo "$(GREEN)$(NAME) est compilé !$(DEF_COLOR)🥶🥶🥶"
				@echo "$(RAINBOW)$(RAINBOW)$(RAINBOW)$(DEF_COLOR)"

$(OBJ_DIR)%.o:	$(SRC_DIR)%.c	
				@echo "$(YELLOW)$< est dans le four...$(DEF_COLOR)🥵🥵🥵"
				@$(CC) $(CFLAGS) $(HEADERS) -o $@ -c $<

$(OBJ_DIR):
				@mkdir -p $(OBJ_DIR)

clean:
				@make clean -C libs/ft_printf
				@make clean -sC libs/minilibx_macos
				@rm -rf $(OBJ_DIR)
				@echo "$(RAINBOW)$(RAINBOW)$(RAINBOW)$(DEF_COLOR)"
				@echo "$(BLUE)à la poubelle les .o$(DEF_COLOR)🤓🤓🤓"

fclean:			clean
				@make fclean -C libs/ft_printf
				@rm -rf libs/minilibx_macos/libmlx.a
				@rm -rf $(NAME)
				@echo "$(CYAN)à la poubelle l'exec$(DEF_COLOR)🤤🤤🤤"

re:				fclean all

.PHONY:			all clean fclean re