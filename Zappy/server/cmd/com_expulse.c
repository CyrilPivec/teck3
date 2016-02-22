/*
** com_expulse.c for expulse in /home/pivec_c/rendu/server_zap/server
** 
** Made by cyril pivec
** Login   <pivec_c@epitech.net>
** 
** Started on  Wed Jul  1 04:34:32 2015 cyril pivec
** Last update Sun Jul  5 01:01:14 2015 Florian Tousch
*/

#include <server.h>

int		get_deplacement(int i, int j)
{
  int		k[5][4] =
    {
      {5, 1, 7, 3},
      {1, 5, 3, 7},
      {3, 7, 5, 1},
      {7, 3, 1, 5},
    };
  return (k[i - 1][j - 1]);
}

int		get_orient(VUE orientation)
{
  if (orientation == HAUT)
    return (1);
  else if (orientation == BAS)
    return (2);
  else if (orientation == DROITE)
    return (3);
  else
    return (4);
}

void		do_expulse(t_server *server, t_client *client, VUE orientation)
{
  int		x;
  int		y;

  x = client->larg;
  y = client->haut;
  if (orientation == HAUT)
    (y = (!y) ? (server->map->haut - 1) : (y - 1));
  else if (orientation == BAS)
    (y = (y == server->map->haut - 1) ? (0) : (x + 1));
  else if (orientation == GAUCHE)
    (x = (!x) ? (server->map->larg - 1) : (x - 1));
  else if (orientation == DROITE)
    (x = (x == server->map->larg - 1) ? (0) : (x + 1));
  client->larg = x;
  client->haut = y;
  dprintf(client->sock, "deplacement: %d\n",
	  get_deplacement(get_orient(orientation),
			  get_orient(client->orientation)));
}

void		expulse(t_server *server, t_client *client)
{
  t_client	*clt;

  if (server->sock_graph > 0)
    pex(server, client->sock);
  clt = server->client;
  while (clt != NULL)
    {
      if (clt->haut == client->haut && clt->larg == clt->larg
	  && clt->sock != client->sock && clt->type == 1)
	{
	  do_expulse(server, clt, client->orientation);
	  if (server->sock_graph > 0)
	    send_position(clt, server->sock_graph);
	}
      clt = clt->next;
    }
}

int		com_expulse(t_server *server, char **tab, int sock)
{
  t_client	*client;

  UNUSED(tab);
  client = server->client;
  while (client != NULL)
    {
      if (client->sock == sock && client->type == 1)
	{
	  expulse(server, client);
	  return (1);
	}
      client = client->next;
    }
  return (0);
}
