/*
** com_fork.c for fork in /home/pivec_c/rendu/server_zap/server
** 
** Made by cyril pivec
** Login   <pivec_c@epitech.net>
** 
** Started on  Thu Jul  2 04:37:23 2015 cyril pivec
<<<<<<< HEAD
** Last update Sat Jul  4 21:18:42 2015 cyril pivec
=======
** Last update Sun Jul  5 00:05:02 2015 Florian Tousch
>>>>>>> 688f607ee2429bcaee339644886f86fa8f28def8
*/

#include <server.h>

int		com_fork(t_server *server, char **tab, int sock)
{
  t_client	*client;

  UNUSED(tab);
  client = server->client;
  while (client != NULL)
    {
      if (client->sock == sock && client->type == 1)
	{
	  if (server->egg == NULL)
	    init_egg(server, client);
	  else
	    add_egg(server, client);
	  return (return_ok(sock));
	}
      client = client->next;
    }
  return (0);
}
