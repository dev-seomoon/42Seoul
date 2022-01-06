# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seomoon <seomoon@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/08 14:02:45 by seomoon           #+#    #+#              #
#    Updated: 2021/06/08 14:13:26 by seomoon          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
FLAGS = -Wall -Wextra -Werror

SRCS = pipex.c utils.c
OBJS = $(SRCS:.c=.o)

NAME = pipex

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(FLAGS) -c -I. $(SRCS)

clean: 
	rm -rf *.o

fclean: clean
	rm -rf $(NAME)

re: fclean all
