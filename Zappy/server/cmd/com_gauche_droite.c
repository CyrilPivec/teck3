/*
** com_gauche_droite.c for  in /home/tousch_f/zappy/server
** 
** Made by Florian Tousch
** Login   <tousch_f@epitech.net>
** 
** Started on  Tue Jun 23 17:07:00 2015 Florian Tousch
** Last update Sun Jul  5 01:01:36 2015 Florian Tousch
*/

#include <server.h>

void		droite(t_client *client)
{
  if (client->orientation == HAUT)
    client->orientation = DROITE;
  else if (client->orientation == DROITE)
    client->orientation = BAS;
  else if (client->orientation == BAS)
    client->orientation = GAUCHE;
  else if (client->orientation == GAUCHE)
    client->orientation = HAUT;
  return ;
}

void		gauche(t_client *client)
{
  if (client->orientation == HAUT)
    client->orientation = GAUCHE;
  else if (client->orientation == GAUCHE)
    client->orientation = BAS;
  else if (client->orientation == BAS)
    client->orientation = DROITE;
  else if (client->orientation == DROITE)
    client->orientation = HAUT;
  return ;
}

int		com_droite(t_server *serv, char **tab, int sock)
{
  t_client	*client;

  UNUSED(tab);
  client = serv->client;
  while (client != NULL)
    {
      if (client->sock == sock && client->type == 1)
	{
	  droite(client);
	  if (serv->sock_graph > 0)
	    send_position(client, serv->sock_graph);
	  return (return_ok(sock));
	}
      client = client->next;
    }
  return (0);
}

int		com_gauche(t_server *serv, char **tab, int sock)
{
  t_client	*client;

  UNUSED(tab);
  client = serv->client;
  while (client != NULL)
    {
      if (client->sock == sock)
	{
	  gauche(client);
	  if (serv->sock_graph > 0)
	    send_position(client, serv->sock_graph);
	  return (return_ok(sock));
	}
      client = client->next;
    }
  return (0);
}
