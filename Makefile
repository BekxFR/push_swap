# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chillion <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/24 13:40:15 by chillion          #+#    #+#              #
#    Updated: 2022/05/24 13:40:18 by chillion         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY : all norm clean fclean re

NAME := push_swap.a

CC := gcc
FLAGS := -Wall -Wextra -Werror -I includes/
SRC_DIR := sources/
OBJ_DIR := objects/
AR := ar rc
RM := rm

BLACK = \033[1;30m
REDBG = \033[30;41m
RED = \033[0;31m
GREEN = \033[0;32m
ORANGE = \033[0;33m
BLUE = \033[0;34m
MAGENTA = \033[0;35m
CYAN = \033[0;36m
NC = \033[0m

COTHERS = $(wildcard *.c)  ## A MODIF
FLIB := libft/libft.a
FCLIB := ${MAKE} fclean -C libft

OBJS = $(COTHERS:%.c=%.o)

OBJ = $(addprefix $(OBJ_DIR),$(OBJS))

OBJF := .cache_exists

all : ${FLIB} ${NAME}

${FLIB} :
	${MAKE} all -C libft
	cp ${FLIB} ${NAME}

${NAME} : ${OBJ}
	@echo "${BLUE}###${NC}Update de l'archive ${NAME}${BLUE}###${MAGENTA}"
	${AR} ${NAME} ${OBJ}
	@echo "${NC}"

${OBJ_DIR}%.o : %.c | $(OBJF)
	@echo "${BLUE}###${NC}Creation du fichier ${@:%.c=%.o}${BLUE}###${ORANGE}"
	${CC} ${FLAGS} -c $< -o $@
	@echo "${NC}"

$(OBJF) :
	@mkdir -p ${OBJ_DIR}

clean : 
	${FCLIB}
	@echo "${RED}###${NC}Nettoyage des fichiers .o${RED}###"
	${RM} -rf ${OBJ_DIR}
	@echo "${GREEN}###${NC}Nettoyage OK${GREEN}###${NC}\n"

fclean : clean
	@echo "${RED}###${NC}Nettoyage de l'archive ${NAME}${RED}###"
	${RM} -f ${NAME}
	@echo "${GREEN}###${NC}Nettoyage OK${GREEN}###${NC}\n"

re : fclean all

norm :
	@norminette $(COTHERS) | grep -v OK! || true