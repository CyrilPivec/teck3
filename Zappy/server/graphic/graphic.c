/*
** graphic.c for graphix in /home/pivec_c/rendu/server_zap/server
** 
** Made by cyril pivec
** Login   <pivec_c@epitech.net>
** 
** Started on  Tue Jun 23 15:57:30 2015 cyril pivec
** Last update Sat Jul  4 19:23:14 2015 Florian Tousch
*/

#include <server.h>

int		set_client_graphic(t_client **tmp, int sock)
{
  t_client	*client;

  client = *tmp;
  while (client != NULL)
    {
      if (client->sock == sock)
	{
	  client->type = 2;
	  return (1);
	}
      client = client->next;
    }
  return (0);
}

void		send_init_map(t_server *server, int sock)
{
  dprintf(sock, "msz %d %d\n", server->map->larg, server->map->haut);
  dprintf(sock, "sgt %d\n", server->arg->client_nb);
}

void		send_map(t_server *server, int sock)
{
  int		h;
  int		l;

  h = 0;
  while (h < server->map->haut)
    {
      l = 0;
      while (l < server->map->larg)
	{
	  dprintf(sock, "bct %d %d %d %d %d %d %d %d %d\n", l, h,
		  server->map->map[h][l].food,
		  server->map->map[h][l].linemate,
		  server->map->map[h][l].deraumere,
		  server->map->map[h][l].sibur,
		  server->map->map[h][l].mendiane,
		  server->map->map[h][l].phiras,
		  server->map->map[h][l].thystame);
	  l++;
	}
      h++;
    }
}

void		send_team(t_server *server, int sock)
{
  t_team	*ma;

  ma = server->team.begin;
  while (ma != NULL)
    {
      dprintf(sock, "tna %s\n", ma->name);
      ma = ma->next;
    }
  ma = server->team.begin;
}

int		do_graphic(t_server *server, char *str, int sock)
{
  if (strcmp(str, "GRAPHIC") == 0)
    {
      if (set_client_graphic(&server->client, sock) == 0)
	return (0);
      server->sock_graph = sock;
      send_init_map(server, sock);
      send_map(server, sock);
      send_team(server, sock);
      return (1);
    }
  return (0);
}
