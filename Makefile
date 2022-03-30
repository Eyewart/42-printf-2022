# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hrifi-la <hrifi-la@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/17 18:02:46 by hrifi-la          #+#    #+#              #
#    Updated: 2022/03/30 17:22:57 by hrifi-la         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRC1 = actions.c ft_printf.c 

OBJ1 = ${SRC1:.c=.o}
NAME = libftprintf.a
LINK = ar rc
$(NAME):	$(OBJ1)
	$(LINK)	$(NAME)	$(OBJ1)
all:	$(NAME)

clean:
	rm	-f	$(OBJ1)
fclean:	clean
	rm	-f	$(NAME)
re:	fclean all
.PHONY: all clean fclean re