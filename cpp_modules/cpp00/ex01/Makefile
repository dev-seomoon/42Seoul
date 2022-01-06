# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seomoon <seomoon@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/12 18:49:57 by seomoon           #+#    #+#              #
#    Updated: 2021/08/05 20:25:00 by seomoon          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CLANG = clang++ 
FLAGS = -Wall -Wextra -Werror

NAME = phonebook

SRCS = PhoneBook.cpp Contact.cpp main.cpp
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
