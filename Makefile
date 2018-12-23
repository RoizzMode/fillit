# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lschambe <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/19 15:13:27 by lschambe          #+#    #+#              #
#    Updated: 2018/12/21 19:38:45 by lschambe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
FLAG = -Wall -Werror -Wextra
FILES = fillit.c \
		valid.c \
		solut.c \
		libft/ft_strlen.c

$(NAME) :
	gcc $(FLAG) -o $(NAME) $(FILES)

all : $(NAME)

clean :

fclean : clean
	rm -rf $(NAME)

re : fclean all
