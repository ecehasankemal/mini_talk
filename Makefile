# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hece  <hece@student.42kocaeli.com.tr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/09 22:11:00 by hece              #+#    #+#              #
#    Updated: 2022/10/09 22:11:01 by hece             ###   ########.tr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Werror -Wextra
CLIENT = @$(CC) $(CFLAGS) client.c mini_talk_utils.c -o $(NAME_CL)
SERVER = @$(CC) $(CFLAGS) server.c mini_talk_utils.c -o $(NAME_SV)
NAME_CL = client
NAME_SV = server

all: $(NAME_CL) $(NAME_SV)
$(NAME_CL):
	$(CLIENT)
	@echo "\n\033[92m $@ built 💼\033[0m\n"
$(NAME_SV):
	$(SERVER)
	@echo "\n\033[92m $@ built 🖥️\033[0m\n"
clean:
	@rm -rf client server
	@echo "\n\033[36m object files removed 👋\033[0m\n"
norm:
	norminette *.c *.h
run:
	@make
	./server
fclean: clean
	@echo "\n\033[36m executables removed 👋\033[0m\n"
re: clean all
.PHONY: all clean fclean re
