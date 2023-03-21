# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oubelhaj <oubelhaj@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/23 18:32:55 by oubelhaj          #+#    #+#              #
#    Updated: 2023/02/23 18:32:55 by oubelhaj         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRC =   ./Mandatory/main.c ./Mandatory/map_parsing.c ./Mandatory/utils.c ./Mandatory/get_next_line.c \
		./Mandatory/get_next_line_utils.c ./Mandatory/ft_split.c ./Mandatory/check_path.c \
		./Mandatory/set_assets.c ./Mandatory/moves.c ./Mandatory/utils2.c \

B_SRC = ./Bonus/main_bonus.c ./Bonus/map_parsing_bonus.c ./Bonus/utils_bonus.c \
		./Bonus/get_next_line_bonus.c ./Bonus/get_next_line_utils_bonus.c ./Bonus/ft_split_bonus.c \
		./Bonus/check_path_bonus.c ./Bonus/set_assets_bonus.c ./Bonus/moves_bonus.c \
		./Bonus/ft_itoa_bonus.c ./Bonus/utils2_bonus.c \

OBJS = ${SRC:.c=.o}

B_OBJS = ${B_SRC:.c=.o}

CC = cc

CFLAGS = -Wall -Wextra -Werror -Imlx

MFLAGS = -lmlx -framework OpenGL -framework Appkit

BONUS = so_long_bonus

.c.o	:
	@$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	@make -s -C ft_printf
	@$(CC) $(CFLAGS) $(MFLAGS) $(OBJS) ft_printf/libftprintf.a -o $(NAME)
	@echo "\033[1;32m- So_long Game Created!\033[0m"

$(BONUS) : $(B_OBJS)
	@make -s -C ft_printf
	@$(CC) $(CFLAGS) $(MFLAGS) $(B_OBJS) ft_printf/libftprintf.a -o $(BONUS)
	@echo "\033[1;32m- So_long Game Created with bonus!\033[0m"

bonus : $(BONUS)

clean :
	@rm -rf ./Mandatory/*.o
	@rm -rf ./ft_printf/*.o
	@rm -rf ./Bonus/*.o
	@echo "\033[1;33m- Object files removed!\033[0m"

fclean : clean
	@rm -rf $(NAME) $(BONUS)
	@rm -rf ./ft_printf/libftprintf.a
	@echo "\033[1;31m- So_long Game Deleted!\033[0m"

re : fclean all