/*
** com_pose.c for pose in /home/pivec_c/rendu/server_zap/server
** 
** Made by cyril pivec
** Login   <pivec_c@epitech.net>
** 
** Started on  Wed Jul  1 01:45:01 2015 cyril pivec
** Last update Sat Jul  4 19:21:30 2015 Florian Tousch
*/

#include <server.h>

extern char	*g_inv[8];

int             get_nb_inv(t_client *client, int i)
{
  if (i == 0)
    return (client->inventaire->food);
  else if (i == 1)
    return (client->inventaire->linemate);
  else if (i == 2)
    return (client->inventaire->deraumere);
  else if (i == 3)
    return (client->inventaire->sibur);
  else if (i == 4)
    return (client->inventaire->mendiane);
  else if (i == 5)
    return (client->inventaire->phiras);
  else if (i == 6)
    return (client->inventaire->thystame);
  else
    return (0);
}

void            sup_inventaire(t_client *client, int i)
{
  if (i == 0)
    client->inventaire->food--;
  else if (i == 1)
    client->inventaire->linemate--;
  else if (i == 2)
    client->inventaire->deraumere--;
  else if (i == 3)
    client->inventaire->sibur--;
  else if (i == 4)
    client->inventaire->mendiane--;
  else if (i == 5)
    client->inventaire->phiras--;
  else
    client->inventaire->thystame--;
}

void            add_ressource(t_server *server, int i, int h, int l)
{
  if (i == 0)
    server->map->map[h][l].food++;
  else if (i == 1)
    server->map->map[h][l].linemate++;
  else if (i == 2)
    server->map->map[h][l].deraumere++;
  else if (i == 3)
    server->map->map[h][l].sibur++;
  else if (i == 4)
    server->map->map[h][l].mendiane++;
  else if (i == 5)
    server->map->map[h][l].phiras++;
  else
    server->map->map[h][l].thystame++;
}

int		pose(t_server *server, t_client *client, char **tab)
{
  int		i;

  if (tab[1])
    {
      i = -1;
      while (g_inv[++i])
        if (!strcmp(tab[1], g_inv[i]) && (get_nb_inv(client, i) > 0))
          {
            sup_inventaire(client, i);
            add_ressource(server, i, client->haut, client->larg);
	    if (server->sock_graph > 0)
	      {
		pdr(server, client->sock, i);
                send_inventaire(client, server->sock_graph);
                bct(server, client->haut, client->larg);
	      }
            return (return_ok(client->sock));
          }
    }
  return (return_ko(client->sock));
}

int		com_pose(t_server *server, char **tab, int sock)
{
  t_client	*client;

  client = server->client;
  while (client != NULL)
    {
      if (client->sock == sock && client->type == 1)
	{
	  pose(server, client, tab);
	  return (1);
	}
      client = client->next;
    }
  return (0);
}
