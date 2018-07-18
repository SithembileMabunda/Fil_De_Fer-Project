# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smabunda <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/18 14:37:18 by smabunda          #+#    #+#              #
#    Updated: 2018/07/18 14:42:43 by smabunda         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf.a

SOURCES = \

OBJECTS =  \

INCLUDES = -I 

CC = gcc

CFLAGS = -o mlx main.c -lmlx -framework OpenGL -framework AppKit

all : $(NAME)

$(NAME) :
	$(CC) $(CFLAGS) $(SOURCES) $(INCLUDES)
	ar rc $(NAME) $(OBJECTS)
	ranlib $(NAME)

clean :
	/bin/rm -f $(OBJECTS)

fclean : clean
	/bin/rm -f $(NAME)

re : fclean all
