/*
** graphic_prend_pose.c for graph in /home/pivec_c/rendu/server_zap/server
** 
** Made by cyril pivec
** Login   <pivec_c@epitech.net>
** 
** Started on  Fri Jul  3 00:47:26 2015 cyril pivec
** Last update Sat Jul  4 19:23:54 2015 Florian Tousch
*/

#include <server.h>

void		pgt(t_server *server, int client, int i)
{
  dprintf(server->sock_graph, "pgt %d %d\n", client, i);
}

void		pdr(t_server *server, int client, int i)
{
  dprintf(server->sock_graph, "pdr %d %d\n", client, i);
}

void		bct(t_server *server, int h, int l)
{
  dprintf(server->sock_graph, "bct %d %d %d %d %d %d %d %d %d\n",
	  l, h, server->map->map[h][l].food,
	  server->map->map[h][l].linemate,
	  server->map->map[h][l].deraumere,
	  server->map->map[h][l].sibur,
	  server->map->map[h][l].mendiane,
	  server->map->map[h][l].phiras,
	  server->map->map[h][l].thystame);
}
