# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jjerde <jjerde@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/02 14:17:14 by jjerde            #+#    #+#              #
#    Updated: 2019/04/24 20:05:10 by jjerde           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = get_next_line

all: one

one:
	gcc -Wall -Wextra -Werror -L libft/ -lft -I libft/ -o $(NAME) get_next_line.c main.c
fclean:
	/bin/rm -f $(NAME)
re: fclean all
