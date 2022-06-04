# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: estrong <estrong@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/04 13:50:44 by estrong           #+#    #+#              #
#    Updated: 2022/06/04 14:54:01 by estrong          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	minishell

#NAME_B	= 

HEAD 	= hdrs/minishell.h

#HEAD_B	= 

LIST	=	main.c	envp_to_list.c	utils_envp.c	

#LIST_B	=	

OBJ = $(patsubst %.c,%.o,$(LIST))

#OBJ_B = $(patsubst %.c,%.o, $(LIST_B))

FLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(OBJ) $(HEAD)
	make -C ./libft
	cc -c ${FLAGS} ${LIST} -I libft/
# gcc -g -c ${LIST} -I libft/
	cc ${OBJ} libft/libft.a -o ${NAME} 

#bonus : $(OBJ_B) $(HEAD_B)
#	make -C ./libft
# gcc -c ${FLAGS} ${LIST_B} -I libft/
#	gcc ${OBJ_B} libft/libft.a -o ${NAME_B}
# @rm -f *.o

clean :
	rm -f $(OBJ)
	make clean -C ./libft

fclean : clean
	rm -f $(NAME)
	make fclean -C ./libft

re : fclean all