/*
** graphic_broadcast.c for graph in /home/pivec_c/rendu/server_zap/server
** 
** Made by cyril pivec
** Login   <pivec_c@epitech.net>
** 
** Started on  Thu Jul  2 23:43:22 2015 cyril pivec
** Last update Sat Jul  4 19:23:13 2015 Florian Tousch
*/

#include <server.h>

void		pbc(t_server *server, char *msg, int client)
{
  dprintf(server->sock_graph, "pbc %d %s\n", client, msg);
}
