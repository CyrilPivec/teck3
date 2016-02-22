/*
** graphic_egg.c for egg in /home/pivec_c/rendu/server_zap/server
** 
** Made by cyril pivec
** Login   <pivec_c@epitech.net>
** 
** Started on  Thu Jul  2 18:59:29 2015 cyril pivec
** Last update Sat Jul  4 19:23:33 2015 Florian Tousch
*/

#include <server.h>

void            enw(t_server *server, t_egg *egg)
{
  dprintf(server->sock_graph, "enw %d %d %d %d\n",
          egg->nb, egg->father, egg->larg, egg->haut);
}

void		ebo(t_server *server, t_egg *egg)
{
  dprintf(server->sock_graph, "ebo %d\n", egg->nb);
}

void		eht(t_server *server, int nb)
{
  dprintf(server->sock_graph, "eht %d\n", nb);
}
