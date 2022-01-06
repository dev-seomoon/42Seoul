#!/bin/bash
gcc -Wall -Werror -Wextra *.o main.c -I./includes -L. -lftprintf -o a.out
