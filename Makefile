# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chillion <chillion@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/01 12:07:22 by chillion          #+#    #+#              #
#    Updated: 2022/09/05 14:45:20 by chillion         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY : all test3 test5 test100 test500 vtest2 vtest3 vtest5 ctest500 vtest500 bonus norm clean fclean re

NAME := push_swap.a
NAME_BONUS := checker.a
SOFT_NAME := push_swap
SOFT_BONUS := checker

CC := gcc
FLAGS := -Wall -Wextra -Werror -I includes/
SRC_DIR := sources/
OBJ_DIR := objects/
AR := ar rc
RM := rm
VAL := valgrind --leak-check=full --track-origins=yes

BLACK = \033[1;30m
REDBG = \033[30;41m
RED = \033[0;31m
GREEN = \033[0;32m
ORANGE = \033[0;33m
BLUE = \033[0;34m
MAGENTA = \033[0;35m
CYAN = \033[0;36m
NC = \033[0m

SRCS = push_swap.c	\
	push_swap_tools_sp.c	\
	push_swap_tools_r.c	\
	push_swap_tools_rr.c	\
	push_swap_tools.c	\
	push_swap_check.c	\
	push_swap_pos.c	\
	push_swap_pull.c	\
	push_swap_switch.c	\
	push_swap_cost.c	\

BONUS = checker.c	\
	checker_tools.c	\
	checker_tools_do.c	\
	push_swap_tools_sp.c	\
	push_swap_tools_r.c	\
	push_swap_tools_rr.c	\
	push_swap_tools.c	\
	push_swap_check.c	\
	push_swap_pos.c	\
	push_swap_pull.c	\
	push_swap_switch.c	\
	push_swap_cost.c	\

FLIB := libft/libft.a
FCLIB := ${MAKE} fclean -C libft

OBJS = $(SRCS:%.c=%.o)
BOBJS = $(BONUS:%.c=%.o)

OBJ = $(addprefix $(OBJ_DIR),$(OBJS))
BOBJ = $(addprefix $(OBJ_DIR),$(BOBJS))

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

bonus : ${FLIB} ${BOBJ} ${NAME_BONUS} ${SOFT_BONUS}

${NAME_BONUS} : ${BOBJ}
	@echo "${BLUE}###${NC}Update de l'archive ${NAME_BONUS}${BLUE}###${MAGENTA}"
	${AR} ${NAME_BONUS} ${BOBJ}
	@echo "${NC}"

${SOFT_BONUS} :
	@echo "${BLUE}###${NC}Creation du fichier ${SOFT_BONUS}${BLUE}###${ORANGE}"
	${CC} ${FLAGS} -g3 -o ${SOFT_BONUS} ${NAME_BONUS} ${FLIB}
	@echo "${NC}"

vtest2 :
		$(eval ARG = $(shell shuf -i 0-50 -n 2))
		${VAL} ./push_swap $(ARG) | ${VAL} ./checker $(ARG)

vtest3 :
		$(eval ARG = $(shell shuf -i 0-50 -n 3))
		${VAL} ./push_swap $(ARG) | ${VAL} ./checker $(ARG)

vtest5 :
		$(eval ARG = $(shell shuf -i 0-50 -n 5))
		${VAL} ./push_swap $(ARG) | ${VAL} ./checker $(ARG)

ctest500 :
		$(eval ARG = $(shell shuf -i 0-2000 -n 500))
		${VAL} ./push_swap $(ARG)

vtest500 :
		$(eval ARG = $(shell shuf -i 0-2000 -n 500))
		${VAL} ./push_swap $(ARG) | ${VAL} ./checker $(ARG)

test3 :
		$(eval ARG = $(shell shuf -i 0-50 -n 3))
		./push_swap $(ARG) | ./checker_linux $(ARG)
		@echo -n "Instructions: "
		@./push_swap $(ARG) | wc -l

test5 :
		$(eval ARG = $(shell shuf -i 1-5 -n 5))
		./push_swap $(ARG) | ./checker_linux $(ARG)
		@echo -n "Instructions: "
		@./push_swap $(ARG) | wc -l

test100 :
		$(eval ARG = $(shell shuf -i 0-1000 -n 100))
		./push_swap $(ARG) | ./checker_linux $(ARG)
		@echo -n "Instructions: "
		@./push_swap $(ARG) | wc -l

test500 :
		$(eval ARG = $(shell shuf -i 0-555555 -n 500))
		./push_swap $(ARG) | ./checker_linux $(ARG)
		@echo -n "Instructions: "
		@./push_swap $(ARG) | wc -l

clean : 
	${FCLIB}
	@echo "${RED}###${NC}Nettoyage des fichiers .o${RED}###"
	${RM} -rf ${OBJ_DIR}
	@echo "${GREEN}###${NC}Nettoyage OK${GREEN}###${NC}\n"

fclean : clean
	@echo "${RED}###${NC}Nettoyage d'archives et de Softs${RED}###"
	${RM} -f ${NAME} ${NAME_BONUS} ${SOFT_NAME} ${SOFT_BONUS}
	@echo "${GREEN}###${NC}Nettoyage OK${GREEN}###${NC}\n"

re : fclean all

norm :
	${MAKE} norm -C libft
	@norminette $(SRCS) $(BONUS) | grep -v OK! || true
