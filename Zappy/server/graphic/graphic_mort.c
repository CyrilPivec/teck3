/*
** graphic_mort.c for mort in /home/pivec_c/rendu/server_zap/server
** 
** Made by cyril pivec
** Login   <pivec_c@epitech.net>
** 
** Started on  Fri Jul  3 05:04:05 2015 cyril pivec
** Last update Sat Jul  4 19:23:43 2015 Florian Tousch
*/

#include <server.h>

void		pdi(t_server *server, int client)
{
  dprintf(server->sock_graph, "pdi %d\n", client);
}

void		seg(t_server *server, char *team)
{
  dprintf(server->sock_graph, "seg %s\n", team);
}

void		edi(t_server *server, int oeuf)
{
  dprintf(server->sock_graph, "edi %d\n", oeuf);
}
