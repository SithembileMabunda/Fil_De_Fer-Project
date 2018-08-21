# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smabunda <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/20 09:44:30 by smabunda          #+#    #+#              #
#    Updated: 2018/08/20 16:01:08 by smabunda         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

Name = FDF

Sources = libft/*.c \
		  *.c \

Objects = libft/*.c \
		  *.c \

Includes = fdf.h libft/libft.h

CC = gcc

CFLAGS = -Wall -Wexta -Werror -o

MLXFLAGS = -lmlx -framework OpenGL -framework AppKit

all : $(NAME)

$(NAME) :
		$(CC) $(NAME) $(CFLAGS) $(SOURCES) $(MLXFLAGS)

clean :
		/bin/rm -f $(OBJECTS)

fclean : clean
		/bin/rm -f $(NAME)

re : fclean all
