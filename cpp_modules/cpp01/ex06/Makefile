# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seomoon <seomoon@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/12 15:17:48 by seomoon           #+#    #+#              #
#    Updated: 2021/08/12 15:17:56 by seomoon          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CLANG = clang++ 
FLAGS = -Wall -Wextra -Werror

NAME = karenFilter

SRCS = main.cpp Karen.cpp
OBJS = $(SRCS:.cpp=.o)

%.o: %.cpp
	$(CLANG) $(FLAGS) -c $(SRCS) -I.

$(NAME): $(OBJS)
	$(CLANG) $(FLAGS) -o $(NAME) $(OBJS)

all: $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all