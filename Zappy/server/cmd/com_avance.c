/*
** com_avance.c for  in /home/tousch_f/zappy/server
** 
** Made by Florian Tousch
** Login   <tousch_f@epitech.net>
** 
** Started on  Tue Jun 23 16:47:38 2015 Florian Tousch
** Last update Sun Jul  5 01:01:00 2015 Florian Tousch
*/

#include <server.h>

void		avance(t_server *s, t_client *c)
{
  if (c->orientation == HAUT)
    c->haut = (!c->haut) ? (s->map->haut - 1) : (c->haut - 1);
  if (c->orientation == BAS)
    c->haut = (c->haut == s->map->haut - 1) ? (0) : (c->haut + 1);
  if (c->orientation == GAUCHE)
    c->larg = (!c->larg) ? (s->map->larg - 1) : (c->larg - 1);
  if (c->orientation == DROITE)
    c->larg = (c->larg == s->map->larg - 1) ? (0) : (c->larg + 1);
}

int		com_avance(t_server *s, char **tab, int sock)
{
  t_client	*client;

  UNUSED(tab);
  client = s->client;
  while (client != NULL)
    {
      if (client->sock == sock && client->type == 1)
	{
	  avance(s, client);
	  if (s->sock_graph > 0)
	    send_position(client, s->sock_graph);
	  return (return_ok(sock));
	}
      client = client->next;
    }
  return (0);
}
