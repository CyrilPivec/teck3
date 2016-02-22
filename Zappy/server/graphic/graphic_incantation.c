/*
** graphic_incantation.c for incantation in /home/pivec_c/rendu/server_zap/server
** 
** Made by cyril pivec
** Login   <pivec_c@epitech.net>
** 
** Started on  Thu Jul  2 20:28:24 2015 cyril pivec
** Last update Sun Jul  5 15:50:08 2015 cyril pivec
*/

#include <server.h>

void		pic(t_server *server, int lvl, int h, int l)
{
  t_client	*client;
  char		*str;
  char		buf[1024];

  str = NULL;
  client = server->client;
  while (client != NULL)
    {
      if (client->lvl == lvl && client->haut == h && client->larg == l
	  && client->type == 1)
	{
	  snprintf(buf, sizeof(buf), " %d", client->sock);
	  str = my_strcat(str, buf);
	}
      client = client->next;
    }
  dprintf(server->sock_graph, "pic %d %d %d%s\n", l, h, lvl, str);
}

void		pie(t_server *server, int h, int l)
{
  dprintf(server->sock_graph, "pie %d %d 1\n", l, h);
}

void		plv(t_server *server, int lvl, int h, int l)
{
  t_client	*client;

  client = server->client;
  while (client != NULL)
    {
      if (client->type == 1 && client->haut == h && client->larg == l
	  && client->lvl == lvl)
	dprintf(server->sock_graph, "plv %d %d\n", client->sock, client->lvl);
      client = client->next;
    }
}
