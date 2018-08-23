# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smabunda <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/20 09:44:30 by smabunda          #+#    #+#              #
#    Updated: 2018/08/23 10:35:02 by smabunda         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

Name = fdf

Sources = ft_fdf.c fdf.c ft_esc.c ft_drawer.c ft_reader.c

Objects = $(Sources:.c=.o)

Includes = fdf.h

CC = gcc

CFLAGS = -Wall -Wexta -Werror

MLXFLAGS = -L/usr/local/include -lmlx -framework OpenGL -framework AppKit

Libft = -L./libft -ft

Libft_ = .libft

all : $(NAME)

$(NAME) : $(Objects)
		@make -C $(Libft_)
		@$(CC) $(CFLAGS) -o $(Name) -I $(Include) $(MLXFLAGS) $(Libft)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean :
		/bin/rm -f $(Objects)
		make -C $(Libft_) fclean

fclean : clean
		/bin/rm -f $(Name)
		make -C $(Libft_) fclean

re : fclean all
