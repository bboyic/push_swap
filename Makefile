# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aconchit <aconchit@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/12 13:21:01 by aconchit          #+#    #+#              #
#    Updated: 2021/11/13 03:13:41 by aconchit         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
PREFIX = src/
C_DIR = main.c ft_split.c ft_atoi.c rules.c rules_2.c rules_3.c points_utils.c\
		push_swap_utils.c utils.c utils_2.c pars.c ft_strlen.c
INCLUDES = includes/
C_FILES = $(addprefix $(PREFIX), $(C_DIR))
CC = gcc -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(C_FILES) $(INCLUDES)*.h
	$(CC) $(C_FILES) -o $@ -I $(INCLUDES)

clean:
	rm -rf $(NAME)

fclean: clean

re: fclean all

.PHONY: all clean fclean re