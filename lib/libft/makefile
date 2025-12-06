# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aialonso <aialonso@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/29 12:33:05 by aialonso          #+#    #+#              #
#    Updated: 2025/12/06 11:31:22 by aialonso         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC_PATH = src
INC_PATH = inc

SOURCES =   $(addprefix $(SRC_PATH)/,\
			ft_isspace.c\
			ft_isdigit.c\
			ft_atoi.c\
			ft_atodbl.c\
			ft_memset.c\
			ft_strncmp.c\
			ft_printf/utils.c\
			ft_printf/ft_printf.c)

FLAGS = -Wall -Wextra -Werror -g -I $(INC_PATH)

CC = cc

LIB = lib

OBJECTS= $(SOURCES:.c=.o)


all: $(NAME)

$(NAME):$(OBJECTS)
	@ar rcs $(NAME) $(OBJECTS)
	
%.o: %.c
	@$(CC) $(FLAGS) -c $< -o $@

clean:
	@rm -f $(OBJECTS)

rclean:
	@rm -f $(OBJECTS)
	
fclean: clean
	@rm -f $(NAME)

re: fclean all rclean
