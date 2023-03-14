# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jlimones <jlimones@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/09 09:17:57 by jlimones          #+#    #+#              #
#    Updated: 2023/03/14 17:00:55 by jlimones         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
CC = gcc
FLAGS = -Wall -Werror -Wextra
SRC = 	src/main.c \
	 	src/parse_args.c \
	 	src/parse_utils.c \
	 	src/parse_utils2.c \

AUTHOR = jlimones
DATE = 11/03/2023

COM_COLOR   = \033[0;34m
OBJ_COLOR   = \033[0;36m
OK_COLOR    = \033[0;32m
ERROR_COLOR = \033[0;31m
WARN_COLOR  = \033[0;33m
NO_COLOR    = \033[m

OBJ = $(SRC:.c=.o)

all: header $(NAME)
	@rm -rf .files_changed

header:
	@printf "%b" "$(OK_COLOR)"
	@echo "        ___  _____ ___  ___      _        "
	@echo "       /   |/ __  \|  \/  |     | |       "
	@echo "      / /| |\`' / /'| .  . | __ _| | _____ "
	@echo "     / /_| |  / /  | |\/| |/ _\` | |/ / _ \\"
	@echo "     \___  |./ /___| |  | | (_| |   <  __/"
	@echo "         |_/\_____/\_|  |_/\__,_|_|\_\___| v2"
	@echo
ifneq ($(HASH),)
	@printf "%b" "$(OBJ_COLOR)Name:	$(WARN_COLOR)$(NAME)@$(HASH)\n"
else
	@printf "%b" "$(OBJ_COLOR)Name:	$(WARN_COLOR)$(NAME)\n"
endif
	@printf "%b" "$(OBJ_COLOR)Author:	$(WARN_COLOR)$(AUTHOR)\n"
	@printf "%b" "$(OBJ_COLOR)Date: 	$(WARN_COLOR)$(DATE)\n\033[m"
	@printf "%b" "$(OBJ_COLOR)CC: 	$(WARN_COLOR)$(CC)\n\033[m"
	@printf "%b" "$(OBJ_COLOR)Flags: 	$(WARN_COLOR)$(FLAGS)\n\033[m"

$(NAME): $(SRC) $(OBJ)
	@gcc -o $(NAME) $(FLAGS) $(SRC)
	@printf "%b" "$(OK_COLOR)" "philosopher compilado\n"

%.o: %.c $(HEAD)
	@gcc $(FLAGS) -c $< -o $@

skiperror:
	@$(CC) -o $(NAME) $(SRC)

clean: header
	@rm -f $(OBJ)

fclean: header clean
	@rm -f $(NAME)
	@printf "%b" "$(OK_COLOR)" "fclean ejecutado correctamente\n"
	

re: fclean all