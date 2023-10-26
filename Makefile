# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amunoz-b <amunoz-b@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/22 12:17:09 by amunoz-b          #+#    #+#              #
#    Updated: 2023/09/27 16:11:57 by amunoz-b         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ft_puthex.c ft_putbasics.c main.c

OBJS = ${SRCS:.c=.o}

NAME = libftprintf.a

CC = cc

RM = rm -f

FLAGS = -Wall -Wextra -Werror

INCLUDES = ft_printf.h

%.o:%.c Makefile ft_printf.h
	${CC} ${FLAGS} -c $< -o $@ -I ${INCLUDES}

${NAME}:	${OBJS}
			ar rc  ${NAME} ${OBJS}
			ranlib ${NAME}
all: ${NAME}

clean:
	${RM} ${OBJS}

fclean:	clean
	${RM} ${NAME}

re: fclean all
