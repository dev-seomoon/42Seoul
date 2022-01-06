# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seomoon <seomoon@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/09 02:50:39 by seomoon           #+#    #+#              #
#    Updated: 2021/04/09 05:25:01 by seomoon          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libasm.a

SRCS = ft_strlen.s ft_strcpy.s ft_strcmp.s \
	   ft_write.s ft_read.s ft_strdup.s

OBJS = $(SRCS:.s=.o)

LIB = -L. -lasm

%.o : %.s
	nasm -f macho64 $< -o $@

all : $(NAME)

$(NAME) : $(OBJS)
	ar rcs $(NAME) $(OBJS)

clean : 
	rm -rf $(OBJS)

fclean : clean
	rm -rf test $(NAME)

re : fclean all

test : re
	$(CC) $(LIB) main.c -o test

.PHONY: all clean fclean re test $(NAME)
