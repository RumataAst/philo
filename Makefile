# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akretov <akretov@student.42prague.com>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/06 19:21:32 by akretov           #+#    #+#              #
#    Updated: 2024/07/08 18:53:28 by akretov          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
FLAGS = -Wall -Wextra -Werror -g -pthread

CFILES =	srcs/utils.c			\
			srcs/check_arg.c		\
			srcs/struct_init.c		\
			srcs/free.c				\
			srcs/TESTING.c			\
			srcs/one_pthread.c		\
			srcs/checker_thread.c	\
			srcs/philo_thread.c		\
			srcs/thread.c			\
			srcs/philo.c

OFILES = $(CFILES:.c=.o)

all: lib $(NAME)

$(NAME): $(OFILES)
	cc $(FLAGS) $^ -o $(NAME)

%.o: %.c 
	cc $(FLAGS) -c $< -o $@

clean:
	rm -f $(OFILES)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean all re lib
