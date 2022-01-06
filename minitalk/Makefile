# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seomoon <seomoon@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/04 20:26:14 by seomoon           #+#    #+#              #
#    Updated: 2021/06/24 07:21:58 by seomoon          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
FLAGS = -Wall -Wextra -Werror
RM = rm -f

CLIENT_SRCS = client.c utils.c
SERVER_SRCS = server.c utils.c
CLIENT_OBJS = $(CLIENT_SRCS:.c=.o)
SERVER_OBJS = $(SERVER_SRCS:.c=.o)

CLIENT = client
SERVER = server

all: $(CLIENT) $(SERVER)

$(CLIENT): $(CLIENT_OBJS)
	$(CC) $(FLAGS) -o $(CLIENT) $(CLIENT_OBJS)

$(SERVER): $(SERVER_OBJS)
	$(CC) $(FLAGS) -o $(SERVER) $(SERVER_OBJS)

%.o: %.c
	$(CC) $(FLAGS) -o $@ -c $< -I.

clean:
	$(RM) *.o

fclean: clean
	$(RM) $(CLIENT) $(SERVER)

re: fclean all
