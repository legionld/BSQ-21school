# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jschille <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/06 15:09:24 by jschille          #+#    #+#              #
#    Updated: 2018/11/07 19:43:19 by jschille         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = bsq

SRC = srcs/

LIB = includes/

all:
	gcc -Wall -Wextra -Werror -I $(LIB) -o $(NAME) $(SRC)create_map_na.c $(SRC)create_map.c $(SRC)create_point.c $(SRC)create_sqrt.c $(SRC)fill_map.c $(SRC)free_map.c $(SRC)main.c $(SRC)print_map.c $(SRC)read_map.c $(SRC)max_sqrt.c
clean:
	rm *.o
fclean:	clean
	rm -f $(NAME)
