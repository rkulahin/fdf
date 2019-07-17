# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rkulahin <rkulahin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/07 14:08:19 by rkulahin          #+#    #+#              #
#    Updated: 2019/07/12 16:29:01 by rkulahin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
LIB = libftprintf.a
OBJ_DIR_FDF	= ./obj_fdf/
SRC_DIR_FDF = ./srcs/
SRC_FDF = main.c \
			map.c \
			debug.c \
			print.c \
			hook.c \
			rotate.c \
			normalize.c \
			color.c
INCL = includes
HDR_FDF	=	$(addprefix, $(INLC)/, fdf_header.h)
FLAGS =	-g -lmlx -framework OpenGL -framework AppKit

OBJ_FDF = $(addprefix $(OBJ_DIR_FDF), $(SRC_FDF:.c=.o))

all: $(NAME)
$(NAME):	$(OBJ_FDF) $(LIB)
	gcc -o $(NAME) $(FLAGS) $(OBJ_FDF) $(LIB)

$(OBJ_FDF):	$(HDR_FDF)	| $(OBJ_DIR_FDF) 

$(OBJ_DIR_FDF):
		@mkdir $(OBJ_DIR_FDF)

$(OBJ_DIR_FDF)%.o:	$(SRC_DIR_FDF)%.c 
		@gcc -c $< -o $@ $(FLAGS) -I$(INCL)
		@echo "ПЕРЕСОБИРАЮ $<"

$(LIB):
	$(MAKE) all -f ./libftprintf/Makefile

clean :
	@rm -rf $(OBJ_DIR_FDF)
	$(MAKE) clean -f ./libftprintf/Makefile

fclean : clean
	@rm -f $(NAME)
	$(MAKE) fclean -f ./libftprintf/Makefile

re : fclean all

.PHONY:all fclean clean re