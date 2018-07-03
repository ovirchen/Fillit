# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pprivalo <pprivalo@42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/25 12:45:37 by ovirchen          #+#    #+#              #
#    Updated: 2017/12/08 16:48:51 by pprivalo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRCS = main.c \
	check_tetriminos.c \
	ft_side_square.c \
	ft_make_matrix.c \
	figures_1_4.c \
	figures_5_9.c \
	figures_10_14.c \
	figures_15_19.c \
	mas_figures.c \
	ft_newlist.c \
	ft_solve.c \
	ft_print_square.c \
	ft_solve_helper.c \

OFILES = $(SRCS:%.c=%.o)

HEADERS = libfill.h

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OFILES)
	@gcc -o $(NAME) $(OFILES)

$(OFILES): $(SRCS)
	@gcc $(FLAGS) -c -I $(HEADERS) $(SRCS)

clean:
	@rm -f $(OFILES)

fclean: clean
	@rm -f $(NAME)

re: fclean all