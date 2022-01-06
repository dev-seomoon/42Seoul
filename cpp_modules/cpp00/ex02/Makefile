# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seomoon <seomoon@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/07 18:36:44 by seomoon           #+#    #+#              #
#    Updated: 2021/08/07 18:39:16 by seomoon          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CLANG = clang++
FLAGS = -Wall -Wextra -Werror

NAME = account

SRCS = Account.cpp tests.cpp
OBJS = $(SRCS:.cpp=.o)

%.o: %.cpp
	$(CLANG) $(FLAGS) -c $(SRCS) -I.

$(NAME): $(OBJS)
	$(CLANG) $(FLAGS) -o $(NAME) $(OBJS)

all: $(NAME)

clean:
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re: fclean all