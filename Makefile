# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tchiba <tchiba@student.42tokyo.jp>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/20 20:51:04 by tchiba            #+#    #+#              #
#    Updated: 2020/12/02 13:25:39 by tchiba           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_mini_ls

CC = gcc

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

SRCNAME =
SRCNAME += ft_mini_ls.c
SRCNAME += ft_mini_ls_utils.c

SRCS = ${addprefix ${SRCDIR}, ${SRCNAME}}

OBJS = ${SRCS:%c=%o}

${NAME}: ${OBJS}
				${CC} ${CFLAGS} -o ${NAME} ${OBJS}

all: ${NAME}

clean:
		${RM} ${OBJS}

fclean:	clean
		${RM} ${NAME}

re: fclean all

.PHONY: clean fclean re all
