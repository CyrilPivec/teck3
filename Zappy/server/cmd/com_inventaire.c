/*
** com_inventaire.c for com in /home/pivec_c/rendu/server_zap/server
** 
** Made by cyril pivec
** Login   <pivec_c@epitech.net>
** 
** Started on  Tue Jun 30 20:19:17 2015 cyril pivec
** Last update Sun Jul  5 01:26:58 2015 Florian Tousch
*/

#include <server.h>

void		inventaire(t_client *client)
{
  dprintf(client->sock,
	  "{%s %d,%s %d,%s %d,%s %d,%s %d,%s %d,%s %d}\n",
	  "nourriture", client->inventaire->food,
	  "linemate", client->inventaire->linemate,
	  "deraumere", client->inventaire->deraumere,
	  "sibur", client->inventaire->sibur,
	  "mendiane", client->inventaire->mendiane,
	  "phiras", client->inventaire->phiras,
	  "thystame", client->inventaire->thystame);
}

int		com_inventaire(t_server *server, char **tab, int sock)
{
  t_client	*client;

  UNUSED(tab);
  client = server->client;
  while (client != NULL)
    {
      if (client->sock == sock && client->type == 1)
	{
	  inventaire(client);
	  return (1);
	}
      client = client->next;
    }
  return (return_ko(client->sock));
}
