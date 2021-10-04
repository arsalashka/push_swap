# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maearly <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/22 18:23:37 by maearly           #+#    #+#              #
#    Updated: 2021/09/22 18:23:38 by maearly          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	checker

LIST		=	main.c				../source/init.c		../source/error.c \
				gnl.c				../source/get_index.c	../source/checkers.c \
				../source/swap.c	../source/rotate.c		../source/push.c \
				chckr_actions.c		exec_instruction.c

LIST_B		=

OBJ			=	$(patsubst %.c,%.o,$(LIST))

OBJ_B		=	$(patsubst %.c,%.o,$(LIST_B))

OPTFLAGS	=	-O2

FLAGS		=	-Wall -Wextra -Werror

LIBFT_DIR	=	../libft

LIBFT_FLAGS	=	-L $(LIBFT_DIR) -lft

all		:	$(NAME)

$(NAME)	:	$(OBJ)
			make -C $(LIBFT_DIR) all
			gcc $(FLAGS) $(LIBFT_FLAGS) $(OPTFLAGS) $(OBJ) -o $(NAME)

bonus	:
			@make $(OBJ)="$(OBJ_B)" all

clean	:
			@make -C $(LIBFT_DIR) clean
			@rm -f $(OBJ) $(OBJ_B)

fclean	:	clean
			@make -C $(LIBFT_DIR) fclean
			@rm -f $(NAME)

re		:	fclean all

.PHONY	:	all clean fclean re bonus

