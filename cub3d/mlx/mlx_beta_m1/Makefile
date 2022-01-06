
SRC= interface.swift $(MODULE_SRC)
OBJ=$(SRC:.swift=.o)

NAME=libmlx.dylib

INC=-I.
#OPTI=-Ounchecked

all: $(NAME)

$(NAME): $(OBJ)
	swiftc $(OPTI) $(INC) -o $(NAME) -emit-library $(OBJ) -lz



%.o: %.swift
	swiftc $(OPTI) $(INC) -parse-as-library -c $< -o $@

%.swiftmodule: %.swift
	swiftc $(OPTI) $(INC) -parse-as-library -c $< -o $@ -emit-module -module-name $(patsubst %.swift,%,$<) -module-link-name $(patsubst %.swift,%,$<)

clean:
	rm -f $(NAME) $(OBJ)*.swiftdoc *~

