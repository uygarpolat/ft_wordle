# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: upolat <upolat@student.hive.fi>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/04 15:29:19 by upolat            #+#    #+#              #
#    Updated: 2024/04/05 15:12:13 by upolat           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = wordle.out

SOURCES = ./ft_wordle.c \
				./check_word_in_file.c \
		  		./get_random_word.c \

OBJECTS = $(SOURCES:.c=.o)

CFLAGS = -Wall -Wextra -Werror

HEADER = ./ft_wordle.h

all: $(NAME)

$(NAME): $(OBJECTS)
	cc $(CFLAGS) -o $@ $^
	chmod +x $@

%.o: %.c
	cc $(CFLAGS) -I$(HEADER) -c $< -o $@

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
