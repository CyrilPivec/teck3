/*
** get_client.c for  in /home/tousch_f/zappy/server
** 
** Made by Florian Tousch
** Login   <tousch_f@epitech.net>
** 
** Started on  Fri Jul  3 17:52:31 2015 Florian Tousch
** Last update Sat Jul  4 19:10:54 2015 Florian Tousch
*/

#include <server.h>

t_client	*get_client2(t_server *serv, int sock)
{
  t_client	*client;

  client = serv->client;
  while (client != NULL)
    {
      if (sock == client->sock && client->type == 1)
	return (client);
      client = client->next;
    }
  return (NULL);
}
