# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smabunda <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/20 09:44:30 by smabunda          #+#    #+#              #
#    Updated: 2018/08/26 11:54:45 by smabunda         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

Sources = ft_fdf.c fdf.c ft_esc.c ft_drawer.c ft_reader.c

Objects = $(Sources:.c=.o)

Includes = fdf.h

CC = gcc

CFLAGS = -Wall -Wextra -Werror 

MLXFLAGS = -L /usr/local/include -lmlx -framework OpenGL -framework AppKit

Libft = -L ./libft -lft

Libft_ = libft/

all : $(NAME)

$(NAME) : $(Objects)
		@make -C $(Libft_)
		$(CC) -o $(NAME) $(Objects) -lm -L $(Libft_) -lft -lmlx -framework OpenGL -framework AppKit

clean :
		/bin/rm -f $(Objects)
		make -C $(Libft_) fclean

fclean : clean
		/bin/rm -f $(Name)
		make -C $(Libft_) fclean

re : fclean all
