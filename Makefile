# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akretov <akretov@student.42prague.com>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/06 19:21:32 by akretov           #+#    #+#              #
#    Updated: 2024/07/14 20:59:08 by akretov          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = philo

# Default flags for normal build
FLAGS = -Wall -Wextra -Werror -g -pthread

# Flags for sanitizer build
SANITIZE_FLAGS = $(FLAGS) -fsanitize=thread

# Source files
CFILES =	srcs/utils.c \
			srcs/check_arg.c \
			srcs/struct_init.c \
			srcs/free.c \
			srcs/one_pthread.c \
			srcs/checker_thread.c \
			srcs/philo_thread.c \
			srcs/eating.c \
			srcs/eating_1.c \
			srcs/thread_0.c \
			srcs/thread_1.c \
			srcs/philo.c

# Object files
OFILES = $(CFILES:.c=.o)

# Default target: build with normal FLAGS
all: lib $(NAME)

$(NAME): $(OFILES)
	cc $(FLAGS) $^ -o $(NAME)

# Rule for building with sanitizer flags
sanitize: $(OFILES)
	cc $(SANITIZE_FLAGS) $^ -o $(NAME)

# Generic rule to build object files
%.o: %.c
	cc $(FLAGS) -c $< -o $@

# Clean commands
clean:
	rm -f $(OFILES)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean all re lib sanitize
