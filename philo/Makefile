# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akretov <akretov@student.42prague.com>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/06 19:21:32 by akretov           #+#    #+#              #
#    Updated: 2024/06/30 17:47:28 by akretov          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
FLAGS = -Wall -Wextra -Werror -g -pthread

CFILES =	srcs/check_arg.c	\
			srcs/struct_init.c	\
			srcs/utils_0.c		\
			srcs/utils_1.c		\
			srcs/threads_0.c	\
			srcs/threads_1.c	\
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
