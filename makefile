# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aialonso <aialonso@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/03 18:56:10 by aialonso          #+#    #+#              #
#    Updated: 2025/12/05 02:40:26 by aialonso         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

SRC_PATH = src
LIB = lib


SOURCES =   $(addprefix $(SRC_PATH)/,\
			fract-ol.c)

INC_PUS = inc
INC_LIB = $(LIB)/libft/inc
INC_MIX = $(LIB)/minilibx

FLA_I = -I $(INC_PUS)
FLA_I_LIB = -I $(INC_LIB)
FLA_I_MIX = -I $(INC_MIX)

COM_LIB = $(LIB)/libft/libft.a
COM_MIX = $(LIB)/minilibx/libmlx.a
COM_MIX_L = $(LIB)/minilibx/libmlx_Linux.a

FLAGS = -Wall -Wextra -Werror -g

DFLAGS =  -L $(LIB)/libft -lft
MFLAGS =  -L $(LIB)/minilibx -lmlx -lXext -lX11 -lm

TFLAGS = $(DFLAGS) $(MFLAGS)

CC = cc

OBJECTS= $(SOURCES:.c=.o)

$(COM_LIB):
	make re -C $(LIB)/libft
	
$(COM_MIX):
	make -C $(LIB)/minilibx

all: $(NAME)

$(NAME): $(OBJECTS) $(COM_LIB) $(COM_MIX) $(COM_MIX_L)
	$(CC) $(FLAGS) $(FLA_I) $(FLA_I_LIB) $(FLA_I_MIX) $(OBJECTS) $(TFLAGS) -o $(NAME)
	
%.o: %.c
	@$(CC) $(FLAGS) $(FLA_I) $(FLA_I_MIX) $(FLA_I_LIB) -c $< -o $@

clean:
	make clean -C $(LIB)/libft
	rm -f $(OBJECTS)

rclean:
	rm -f $(OBJECTS)
	
fclean: clean
	make fclean -C $(LIB)/libft
	rm -f $(NAME)

re: fclean all rclean

.PHONY: all clean rclean fclean re

.DEFAULT_GOAL=all