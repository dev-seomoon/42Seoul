# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seomoon </var/mail/seomoon>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/10 03:50:38 by seomoon           #+#    #+#              #
#    Updated: 2020/07/25 18:18:24 by seomoon          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = libft.a
INC = .
SRC_DIR = ./srcs/
SRCS = ft_atoi.c	\
	   ft_bzero.c	\
	   ft_calloc.c	\
	   ft_isalnum.c	\
	   ft_isalpha.c	\
	   ft_isascii.c	\
	   ft_isdigit.c	\
	   ft_isprint.c	\
	   ft_memccpy.c	\
	   ft_memchr.c	\
	   ft_memcmp.c	\
	   ft_memcpy.c	\
	   ft_memmove.c	\
	   ft_memset.c	\
	   ft_strchr.c	\
	   ft_strdup.c	\
	   ft_strlcat.c	\
	   ft_strlcpy.c	\
	   ft_strlen.c	\
	   ft_strncmp.c	\
	   ft_strnstr.c	\
	   ft_strrchr.c	\
	   ft_tolower.c	\
	   ft_toupper.c	\
	   ft_substr.c		\
	   ft_strjoin.c		\
	   ft_strtrim.c		\
	   ft_split.c		\
	   ft_itoa.c		\
	   ft_strmapi.c		\
	   ft_putchar_fd.c	\
	   ft_putstr_fd.c	\
	   ft_putendl_fd.c	\
	   ft_putnbr_fd.c
BONUS_SRCS = ft_lstnew.c		\
			 ft_lstadd_front.c	\
			 ft_lstsize.c		\
			 ft_lstlast.c		\
			 ft_lstadd_back.c	\
			 ft_lstdelone.c		\
			 ft_lstclear.c		\
			 ft_lstiter.c		\
			 ft_lstmap.c
OBJ_DF = $(SRCS:.c=.o)
OBJ_BN = $(BONUS_SRCS:.c=.o)

AR = ar
ARFLAGS = rcs
RM = rm -f

.PHONY: all clean fclean re bonus

all : $(NAME)

%.o : %.c $(INC)
	$(CC) $(CFLAGS) -I$(INC) -c $< -o $@

$(NAME) : $(OBJ_DF)
	$(AR) $(ARFLAGS) $(NAME) $(OBJ_DF)

bonus : $(OBJ_DF) $(OBJ_BN)
	$(AR) $(ARFLAGS) $(NAME) $(OBJ_DF) $(OBJ_BN)

clean :
	$(RM) $(OBJ_DF) $(OBJ_BN)

fclean : clean
	$(RM) $(NAME)

re : fclean all
