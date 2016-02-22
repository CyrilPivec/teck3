/*
** com_connect_nbr.c for connect in /home/pivec_c/rendu/server_zap/server
** 
** Made by cyril pivec
** Login   <pivec_c@epitech.net>
** 
** Started on  Wed Jul  1 02:41:51 2015 cyril pivec
** Last update Sun Jul  5 00:03:34 2015 Florian Tousch
*/

#include <server.h>

void		connect_nbr(t_server *server, t_client *client)
{
  t_team	*ma;

  ma = server->team.begin;
  while (ma != NULL)
    {
      if (!strcmp(client->team, ma->name))
	{
	  dprintf(client->sock, "%d", ma->nb);
	}
      ma = ma->next;
    }
  ma = server->team.begin;
}

int		com_connect_nbr(t_server *server, char **tab, int sock)
{
  t_client	*client;

  UNUSED(tab);
  client = server->client;
  while (client != NULL)
    {
      if (client->sock == sock && client->type == 1)
	{
	  connect_nbr(server, client);
	  return (1);
	}
      client = client->next;
    }
  return (return_ko(sock));
}
