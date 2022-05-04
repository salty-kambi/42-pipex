# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lsuau <lsuau@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/04 10:06:54 by lsuau             #+#    #+#              #
#    Updated: 2021/12/03 18:44:18 by lsuau            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAMEX = pipex

INC = pipex.h

SRC = main.c find_path.c error.c ft_split.c stock.c

GCC = gcc -Wall -Werror -Wextra

OBJS = ${SRC:.c=.o}

all : ${NAMEX}

%.o : %.c ${INC}
	${GCC} -c $< -o $@

${NAMEX}: ${OBJS} ${INC}
	${GCC} ${OBJS} -o ${NAMEX}

clean :
	rm -f ${OBJS}

fclean : clean
	rm  -f ${NAMEX}

re : fclean all

.PHONY: bonus all clean fclean re
