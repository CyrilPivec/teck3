/*
** com_incantation.c for incantation in /home/pivec_c/rendu/server_zap/server
** 
** Made by cyril pivec
** Login   <pivec_c@epitech.net>
** 
** Started on  Thu Jul  2 00:45:05 2015 cyril pivec
** Last update Sun Jul  5 01:29:01 2015 Florian Tousch
*/

#include <server.h>

int		nb_clt_case(t_server *server, t_client *client, int h, int l)
{
  t_client	*clt;
  int		i;
  int		j;

  clt = server->client;
  while (clt != NULL)
    {
      if (clt->sock != client->sock && clt->lvl == client->lvl
	  && clt->haut == h && clt->larg == l && clt->type == 1)
	i++;
      if (clt->sock != client->sock && clt->lvl != client->lvl
	  && clt->haut == h && clt->larg == l && clt->type == 1)
	j++;
      clt = clt->next;
    }
  if (j > 0)
    return (0);
  else
    return (i);
}

int		incantation(t_server *server, t_client *client, int h, int l)
{
  if (nb_clt_case(server, client, h, l) != need_incant(client->lvl - 1, 0))
    return (0);
  if (server->map->map[h][l].linemate < need_incant(client->lvl - 1, 1))
    return (0);
  if (server->map->map[h][l].deraumere < need_incant(client->lvl - 1, 2))
    return (0);
  if (server->map->map[h][l].sibur < need_incant(client->lvl - 1, 3))
    return (0);
  if (server->map->map[h][l].mendiane < need_incant(client->lvl - 1, 4))
    return (0);
  if (server->map->map[h][l].phiras < need_incant(client->lvl - 1, 5))
    return (0);
  if (server->map->map[h][l].thystame < need_incant(client->lvl - 1, 3))
    return (0);
  return (1);
}

void		send_incantation(t_server *server, t_client *t, int h, int l)
{
  t_client	*c;

  c = server->client;
  while (c != NULL)
    {
      if (c->lvl == t->lvl && c->haut == h && c->larg == l && c->type == 1)
	dprintf(c->sock, "elevation en cours\n");
      c = c->next;
    }
  if (server->sock_graph > 0)
    pic(server, t->lvl, h, l);
}

void		do_incantation(t_server *server, t_client *client, int h, int l)
{
  t_client	*c;
  int		i;

  c = server->client;
  while (c != NULL)
    {
      if (c->lvl == client->lvl && c->haut == h && c->larg == l && c->type == 1)
	{
	  i = c->lvl++;
	  dprintf(c->sock, "niveau actuel : %d\n", c->lvl);
	}
    }
  if (server->sock_graph > 0)
    {
      pie(server, h, l);
      plv(server, i, h, l);
      send_map(server, server->sock_graph);
    }
  check_win(server);
}

int		com_incantation(t_server *server, char **tab, int sock)
{
  t_client	*client;

  UNUSED(tab);
  while (client != NULL)
    {
      if (client->sock == sock && client->type == 1)
	{
	  if (incantation(server, client, client->haut, client->larg) == 1)
	    {
	      send_incantation(server, client, client->haut, client->larg);
	      do_incantation(server, client, client->haut, client->larg);
	    }
	  else
	    return (return_ko(sock));
	  return (1);
	}
      client = client->next;
    }
  return (0);
}
