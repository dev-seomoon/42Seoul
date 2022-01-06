
CC = gcc
FLAGS = -Wall -Wextra -Werror

INCLUDES = -I.

CK_NAME = checker

PS_NAME = push_swap

CK_SRCS = checker/main.c checker/run_commands.c
PS_SRCS = push_swap/main.c push_swap/median.c \
	     push_swap/sort_a.c push_swap/sort_b.c \
	     push_swap/solve.c
CO_SRCS = common/commands.c common/stack.c common/check_args.c \
		  utils/utils.c utils/gnl.c utils/gnl_utils.c

CK_OBJS = $(CO_SRCS:.c=.o) $(CK_SRCS:.c=.o)
PS_OBJS = $(CO_SRCS:.c=.o) $(PS_SRCS:.c=.o)

SRC_PATH = srcs
OBJ_PATH = objs

CK_SRC = $(addprefix $(SRC_PATH)/, $(CK_SRCS))
PS_SRC = $(addprefix $(SRC_PATH)/, $(PS_SRCS))
CO_SRC = $(addprefix $(SRC_PATH)/ $(CO_SRCS))

CK_OBJ = $(addprefix $(OBJ_PATH)/, $(CK_OBJS))
PS_OBJ = $(addprefix $(OBJ_PATH)/, $(PS_OBJS))


all : $(CK_NAME) $(PS_NAME)


$(CK_NAME) : $(CK_OBJ)
	gcc -o $@ $(CK_OBJ) $(INCLUDES)

$(PS_NAME) : $(PS_OBJ)
	gcc -o $@ $(PS_OBJ) $(INCLUDES)

$(OBJ_PATH)/%.o : $(SRC_PATH)/%.c
	@mkdir -p $(OBJ_PATH)
	@mkdir -p $(dir $(PS_OBJ))
	@mkdir -p $(dir $(CK_OBJ))
	gcc -o $@ -c $< $(INCLUDES) $(FLAGS)

clean :
	rm -rf $(OBJ_PATH)

fclean : clean
	rm $(CK_NAME) $(PS_NAME)

re : fclean all
