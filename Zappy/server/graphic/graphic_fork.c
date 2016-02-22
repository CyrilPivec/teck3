/*
** graphic_fork.c for graphic in /home/pivec_c/rendu/server_zap/server
** 
** Made by cyril pivec
** Login   <pivec_c@epitech.net>
** 
** Started on  Fri Jul  3 00:24:34 2015 cyril pivec
** Last update Sat Jul  4 19:23:27 2015 Florian Tousch
*/

#include <server.h>

void		pfk(t_server *server, int client)
{
  dprintf(server->sock_graph, "pfk %d\n", client);
}

void		pex(t_server *server, int client)
{
  dprintf(server->sock_graph, "pex %d\n", client);
}
