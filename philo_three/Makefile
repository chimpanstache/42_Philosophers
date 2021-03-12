# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ehafidi <ehafidi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/11 19:55:13 by ehafidi           #+#    #+#              #
#    Updated: 2021/03/12 13:36:32 by ehafidi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# gcc -g thread.c -o thread
# dsym because of -g flag

SRC = utils2.c philo_three.c timer.c output_message2.c parse_and_init.c main.c\

OBJ = $(SRC:.c=.o)

CC = gcc 
CCFLAGS = -g -Wall -Werror -Wextra -pthread 

NAME = philo_three
RM = rm -rf

all	: $(OBJ) $(NAME) 

$(NAME) :
	$(CC) $(CCFLAGS) $(SRC) -o $(NAME) 

%.o: %.c
		$(CC) $(CCFLAGS) -o $@ -c $<

clean :	
	$(RM) *.o *.dSYM

fclean: clean
	$(RM) $(NAME)

re: fclean all