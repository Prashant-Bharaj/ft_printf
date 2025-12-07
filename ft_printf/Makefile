# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: prasingh <prasingh@student.42berlin.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/07 18:41:17 by prasingh          #+#    #+#              #
#    Updated: 2025/12/07 20:51:57 by prasingh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME        = libftprintf.a

SRC_DIR     = src/

SRC         = $(SRC_DIR)ft_printf.c 

OBJ         = $(SRC:.c=.o)

CC          = cc
CFLAGS      = -Wall -Wextra -Werror
AR          = ar
ARFLAGS     = rcs
RM          = rm -f
INCLUDE     = -I.

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(ARFLAGS) $@ $^

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

clean:
	$(RM) $(OBJ) 

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
