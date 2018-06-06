# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rbarbazz <rbarbazz@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/19 10:38:52 by rbarbazz          #+#    #+#              #
#    Updated: 2018/05/04 13:43:44 by rbarbazz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_select

SRC_PATH = src

SRC_NAME =	main.c term_commands.c term_settings.c list_arg.c get_datas.c signal.c\
			print.c cursor_motion.c clear.c remove_param.c select.c

OBJ_PATH = obj

CPPFLAGS = -Iinclude -Ilibft/include

LDFLAGS = -Llibft

LDLIBS = -lft

LIB = libft/libft.a

CFLAGS = -Wall -Wextra -Werror

CC = clang

OBJ_NAME = $(SRC_NAME:.c=.o)

SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))

OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

all: $(NAME)

$(LIB):
	make -C libft

$(NAME): $(LIB) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LDFLAGS) $(LDLIBS) $(LIB) -ltermcap -o $@

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@mkdir -p obj/
	$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $<

norme:
	norminette $(SRC)
	norminette include/*.h
	norminette libft/src
	norminette libft/include

clean:
	make -C libft clean
	rm -rf $(OBJ_PATH)

fclean: clean
	make -C libft fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re
