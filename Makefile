# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: estrong <estrong@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/04 13:50:44 by estrong           #+#    #+#              #
#    Updated: 2022/06/04 18:27:56 by estrong          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

HDRS	=	minishell.h

# LIB_NAME = /Users/estrong/.brew/Cellar/readline/8.1.2/lib/libreadline.a

# NAME_B = philo_bonus

CC = cc
# gcc -fsanitize=thread флаг для теста потока

CFLAGS = -Wall -Wextra -Werror -I$(HDRS)

RM = rm -f

FILES = main.c	envp_to_list.c	utils_envp.c

OBJS = $(FILES:%.c=%.o)

$(NAME): $(OBJS) $(HDRS)
	$(MAKE) -C ./Libft
	$(CC) $(CFLAGS) $(OBJS) -lreadline -ltermcap -g -L/Users/estrong/.brew/Cellar/readline/8.1.2/lib/ -I/Users/estrong/.brew/Cellar/readline/8.1.2/include Libft/libft.a -o $(NAME)
# printf()

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY:all clean fclean re