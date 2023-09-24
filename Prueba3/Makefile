# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amunoz-b <amunoz-b@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/22 12:17:09 by amunoz-b          #+#    #+#              #
#    Updated: 2023/09/22 12:26:18 by amunoz-b         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ft_puthex.c main_corregido.c

OBJS = ${SRCS:.c=.o}

NAME = libftprintf.a

CC = cc

RM = rm -f

FLAGS = -Wall -Wextra -Werror

.c.o:
	${CC} ${FLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			ar rc  ${NAME} ${OBJS}
			ranlib ${NAME}
all: ${NAME}

clean:
	${RM} ${OBJS}

fclean:	clean
	${RM} ${NAME}

re: fclean all
