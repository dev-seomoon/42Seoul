# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seomoon <seomoon@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/12 18:49:57 by seomoon           #+#    #+#              #
#    Updated: 2021/07/12 19:11:50 by seomoon          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CLANG = clang++ 
FLAGS = -Wall -Wextra -Werror

NAME = megaphone

SRCS = megaphone.cpp
OBJS = $(SRCS:.cpp=.o)

%.o: %.cpp
	$(CLANG) $(FLAGS) -c $(SRCS) -o $(OBJS)

$(NAME): $(OBJS)
	$(CLANG) $(FLAGS) -o $(NAME) $(OBJS)

all: $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
