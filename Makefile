# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bben-aou <bben-aou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/02 18:35:51 by bben-aou          #+#    #+#              #
#    Updated: 2022/01/07 06:45:32 by bben-aou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

CFLAGS = -Wall -Wextra -Werror

src = pipex.c \
	  errors.c \
	  child1.c \
	  child2.c \

src_b = ./bonus/pipex_bonus.c \
		./bonus/check_syntax.c \
		./bonus/utils.c \
		./bonus/free.c \
		./bonus/process.c \
		./bonus/here_doc.c \
		./get_next_line/get_next_line.c\
		./get_next_line/get_next_line_utils.c\

libft = ./libft/libft.a

HDRS = ./pipex.h

OBJ = $(src:.c=.o)
OBJB = $(src_b:.c=.o)

all : $(NAME)

$(NAME): $(OBJ)
	@make -sC libft
	@gcc $(CFLAGS) $^ $(libft) -o $@
	@echo "\033[1;32m##########COMPILED SUCCESSFULY##########\033[0m"

bonus : $(OBJB)
	@make -sC libft
	@gcc $(CFLAGS) $(OBJB) $(libft) -o $(NAME)
	@echo "\033[1;32m##########BONUS COMPILED SUCCESSFULY##########\033[0m"

%.o: %.c $(HDRS)
	@gcc $(CFLAGS) -c $< -o $@ 

clean:
	@rm -f $(OBJ)
	@rm -f $(OBJB)
	@make -sC libft clean

fclean: clean
	@rm -f $(NAME)
	@make -sC libft fclean
	@echo "\033[1;32m##########CLEANED SUCCESSFULY##########\033[0m"

re: fclean all