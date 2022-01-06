NAME = libftprintf.a
SRCS = ft_printf.c \
	   		ft_flag_precision.c \
			ft_flag_width.c \
			ft_parse_flags.c \
			ft_parse_type.c \
			ft_save_flags.c \
			ft_treat_char.c \
			ft_treat_hex.c \
			ft_treat_int.c \
			ft_treat_percent.c \
			ft_treat_pointer.c \
			ft_treat_string.c \
			ft_treat_unint.c \
			ft_put_result.c
SRC_DIR = srcs/
CFILE = $(SRCS:%=$(SRC_DIR)%)
OBJS = $(CFILE:.c=.o)
LIBFT = libft/libft.a

CC = gcc
FLAGS = -c -Wall -Wextra -Werror
INCLUDES = -I./includes

all : $(NAME)

$(NAME) : $(OBJS) $(LIBFT)
	cp $(LIBFT) ./$(NAME)
	ar -rcs $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(FLAGS) $(INCLUDES) -c $< -o $(<:.c=.o)

$(LIBFT) :
	$(MAKE) -C ./libft

clean :
	$(MAKE) clean -C libft
	rm -rf $(OBJS)

fclean : clean
	$(MAKE) fclean -C libft
	rm -rf $(NAME)

re : fclean all

.PHONY: all clean fclean re libft
