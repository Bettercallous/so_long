# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oubelhaj <oubelhaj@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/04 09:25:05 by oubelhaj          #+#    #+#              #
#    Updated: 2023/03/14 02:47:05 by oubelhaj         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = ft_printf.c ft_putchar.c ft_putnbr.c ft_putstr.c print_address.c \
		print_hex.c print_unsigned.c 

OBJS = ${SRCS:.c=.o}

CFLAGS = -Wall -Wextra -Werror

.c.o	:
	@$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

all : ${NAME}

${NAME}: ${OBJS}
	@ar rc ${NAME} ${OBJS}
	
clean:
	@rm -f ${OBJS}

fclean: clean
	@rm -rf ${NAME}

re: fclean all