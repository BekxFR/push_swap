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

.PHONY : all test5 test100 vtest5 vtest100 norm clean fclean re

NAME := push_swap.a
SOFT_NAME := push_swap

CC := gcc
FLAGS := -Wall -Wextra -Werror -I includes/
SRC_DIR := sources/
OBJ_DIR := objects/
AR := ar rc
RM := rm
VAL := valgrind --leak-check=full

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

all : ${FLIB} ${NAME} ${SOFT_NAME}

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

${SOFT_NAME} :
	@echo "${BLUE}###${NC}Creation du fichier ${SOFT_NAME}${BLUE}###${ORANGE}"
	${CC} ${FLAGS} -o ${SOFT_NAME} ${NAME}
	@echo "${NC}"

$(OBJF) :
	@mkdir -p ${OBJ_DIR}

test5 : $(NAME)	
		$(eval ARG = $(shell shuf -i 0-50 -n 5))
		./push_swap $(ARG)

vtest5 : $(NAME)	
		$(eval ARG = $(shell shuf -i 0-50 -n 5))
		${VAL} ./push_swap $(ARG)

test100 : $(NAME)	
		$(eval ARG = $(shell shuf -i 0-1000 -n 100))
		./push_swap $(ARG)

vtest100 : $(NAME)	
		$(eval ARG = $(shell shuf -i 0-1000 -n 100))
		${VAL} ./push_swap $(ARG)

clean : 
	${FCLIB}
	@echo "${RED}###${NC}Nettoyage des fichiers .o${RED}###"
	${RM} -rf ${OBJ_DIR}
	@echo "${GREEN}###${NC}Nettoyage OK${GREEN}###${NC}\n"

fclean : clean
	@echo "${RED}###${NC}Nettoyage de l'archive ${NAME}${RED}###"
	${RM} -f ${NAME}
	${RM} -f push_swap
	@echo "${GREEN}###${NC}Nettoyage OK${GREEN}###${NC}\n"

re : fclean all

norm :
	@norminette $(COTHERS) | grep -v OK! || true