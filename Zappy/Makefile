##
## Makefile for  in /home/tousch_f/rendu/ok
## 
## Made by Florian Tousch
## Login   <tousch_f@epitech.net>
## 
## Started on  Sat Jul  4 18:45:50 2015 Florian Tousch
## Last update Sun Jul  5 15:52:21 2015 cyril pivec
## Last update Sun Jul  5 01:32:16 2015 Florian Tousch
##

NAME=		zappy_server

SERV_DIR=	server/

ARGS_SDIR=	args/
CLIENT_SDIR=	client/
CMD_SDIR=	cmd/
GRAPHIC_SDIR=	graphic/
OTHER_SDIR=	other/
SERVER_SDIR=	server/

SRC=		$(SERV_DIR)$(ARGS_SDIR)check_args.c		\
		$(SERV_DIR)$(ARGS_SDIR)parser.c			\
		$(SERV_DIR)$(CLIENT_SDIR)add_client.c		\
		$(SERV_DIR)$(CLIENT_SDIR)do_team.c		\
		$(SERV_DIR)$(CLIENT_SDIR)eggs.c			\
		$(SERV_DIR)$(CLIENT_SDIR)eggs2.c		\
		$(SERV_DIR)$(CLIENT_SDIR)get_client.c		\
		$(SERV_DIR)$(CLIENT_SDIR)inventaire.c		\
		$(SERV_DIR)$(CLIENT_SDIR)map.c			\
		$(SERV_DIR)$(CLIENT_SDIR)team.c			\
		$(SERV_DIR)$(CMD_SDIR)com_avance.c		\
		$(SERV_DIR)$(CMD_SDIR)com_broadcast.c		\
		$(SERV_DIR)$(CMD_SDIR)com_connect_nbr.c		\
		$(SERV_DIR)$(CMD_SDIR)com_expulse.c		\
		$(SERV_DIR)$(CMD_SDIR)com_fork.c		\
		$(SERV_DIR)$(CMD_SDIR)com_gauche_droite.c	\
		$(SERV_DIR)$(CMD_SDIR)com_incantation.c		\
		$(SERV_DIR)$(CMD_SDIR)com_incantation2.c	\
		$(SERV_DIR)$(CMD_SDIR)com_inventaire.c		\
		$(SERV_DIR)$(CMD_SDIR)com_pose.c		\
		$(SERV_DIR)$(CMD_SDIR)com_prend.c		\
		$(SERV_DIR)$(CMD_SDIR)com_voir.c		\
		$(SERV_DIR)$(CMD_SDIR)com_voir2.c		\
		$(SERV_DIR)$(CMD_SDIR)do_commande.c		\
		$(SERV_DIR)$(CMD_SDIR)get_case.c		\
		$(SERV_DIR)$(CMD_SDIR)get_case2.c		\
		$(SERV_DIR)$(CMD_SDIR)get_case3.c		\
		$(SERV_DIR)$(CMD_SDIR)utils.c			\
		$(SERV_DIR)$(GRAPHIC_SDIR)check_win.c		\
		$(SERV_DIR)$(GRAPHIC_SDIR)graphic.c		\
		$(SERV_DIR)$(GRAPHIC_SDIR)graphic2.c		\
		$(SERV_DIR)$(GRAPHIC_SDIR)graphic_broadcast.c	\
		$(SERV_DIR)$(GRAPHIC_SDIR)graphic_egg.c		\
		$(SERV_DIR)$(GRAPHIC_SDIR)graphic_fork.c	\
		$(SERV_DIR)$(GRAPHIC_SDIR)graphic_incantation.c	\
		$(SERV_DIR)$(GRAPHIC_SDIR)graphic_mort.c	\
		$(SERV_DIR)$(GRAPHIC_SDIR)graphic_prend_pose.c	\
		$(SERV_DIR)$(OTHER_SDIR)my_str_to_wordtab.c	\
		$(SERV_DIR)$(OTHER_SDIR)return.c		\
		$(SERV_DIR)$(SERVER_SDIR)init_server.c		\
		$(SERV_DIR)$(SERVER_SDIR)loop.c			\
		$(SERV_DIR)$(SERVER_SDIR)my_read.c		\
		$(SERV_DIR)$(SERVER_SDIR)server.c		\


OBJ=		$(SRC:.c=.o)

OK=		@echo -e "\e[1;32m[OK]\e[1;37m"

CC=		gcc
RM=		rm -Rf
CFLAGS +=	-Iserver/include/
CFLAGS +=	-W -Wall -Werror -Wextra

all:		$(NAME)

$(NAME):	$(OBJ)
		@echo -e "\e[1;32m\n\nCompilation réussi:\n\e[1;37mLe binaire [\e[1;32mzappy_server\e[1;37m] est créé."
		@$(CC) -o $(NAME) $(OBJ) $(INC)

clean:
		@echo -e "\e[1;33mClean -> DONE!\e[1;37m"
		@$(RM) $(OBJ) *~ *# *.
		@$(RM) $(SERV_DIR)$(ARGS_SDIR)*~ $(RM) $(SERV_DIR)$(ARGS_SDIR)*# $(RM) $(SERV_DIR)$(ARGS_SDIR)*.
		@$(RM) $(SERV_DIR)$(CLIENT_SDIR)*~ $(SERV_DIR)$(CLIENT_SDIR)*# $(SERV_DIR)$(CLIENT_SDIR)*.
		@$(RM) $(SERV_DIR)$(CMD_SDIR)*~ $(SERV_DIR)$(CMD_SDIR)*# $(SERV_DIR)$(CMD_SDIR)*.
		@$(RM) $(SERV_DIR)$(GRAPHIC_SDIR)*~ $(SERV_DIR)$(GRAPHIC_SDIR)*# $(SERV_DIR)$(GRAPHIC_SDIR)*.
		@$(RM) $(SERV_DIR)$(OTHER_SDIR)*~ $(SERV_DIR)$(OTHER_SDIR)*# $(SERV_DIR)$(OTHER_SDIR)*.
		@$(RM) $(SERV_DIR)$(SERVER_SDIR)*~ $(SERV_DIR)$(SERVER_SDIR)*# $(SERV_DIR)$(SERVER_SDIR)*.

fclean:		clean
		@echo -e "\e[1;33mFclean -> DONE!\e[1;37m"
		@$(RM) $(NAME)

re:		fclean all

.PHONY:		all clean fclean re







