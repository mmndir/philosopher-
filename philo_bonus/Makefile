# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mndir <mndir@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/25 15:40:22 by mndir             #+#    #+#              #
#    Updated: 2023/03/25 15:40:22 by mndir            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo_bonus
SRC = philo.c philo_utils.c process.c initialize.c check_death.c action.c
OBJS = $(SRC:.c=.o)
CC = gcc -pthread -g3
CFLAGS = -Wall -Wextra -Werror

all: ${NAME}

${NAME}: ${OBJS}
	${CC} -pthread ${CFLAGS} ${OBJS} -o $@


clean:
	rm -f *.o

fclean: clean
	rm -f ${NAME}

re: fclean all