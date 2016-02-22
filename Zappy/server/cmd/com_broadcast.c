/*
** com_broadcast.c for broadcast in /home/pivec_c/rendu/server_zap/server
** 
** Made by cyril pivec
** Login   <pivec_c@epitech.net>
** 
** Started on  Wed Jul  1 17:27:18 2015 cyril pivec
** Last update Sat Jul  4 19:13:40 2015 Florian Tousch
*/

#include <server.h>

int		get_direction(int i, int j)
{
  int		g_dir[8][4] =
    {
      {1, 5, 3, 7},
      {2, 6, 4, 8},
      {3, 7, 5, 1},
      {4, 8, 6, 2},
      {5, 1, 7, 3},
      {6, 2, 8, 4},
      {7, 3, 1, 5},
      {8, 4, 2, 6},
    };

  return (g_dir[i - 1][j - 1]);
}

int		get_direct(t_server *serv, t_client *clt, t_client *dest)
{
  int		x;
  int		y;

  x = my_min(clt->larg - dest->larg,
	     serv->map->larg - (clt->larg - dest->larg));
  y = my_min(clt->haut - dest->haut,
	     serv->map->haut - (clt->haut - dest->haut));
  if (((clt->haut + y) % serv->map->haut) == dest->haut)
    {
      if (((clt->larg + x) % serv->map->larg) == dest->larg)
	return (get_direction(2, get_orient(dest->orientation)));
      else
	return (get_direction(8, get_orient(dest->orientation)));
    }
  if (((clt->larg + x) % serv->map->larg) == dest->larg)
    return (get_direction(4, get_orient(dest->orientation)));
  else
    return (get_direction(6, get_orient(dest->orientation)));
}

int		get_dir(t_server *serv, t_client *clt, t_client *dest)
{
  int		x;
  int		y;

  x = my_min(clt->larg - dest->larg,
	     serv->map->larg - (clt->larg - dest->larg));
  y = my_min(clt->haut - dest->haut,
	     serv->map->haut - (clt->haut - dest->haut));
  if (!x && !y)
    return (0);
  if (!x)
    {
      if (((clt->haut + y) % serv->map->haut) == dest->haut)
	return (get_direction(1, get_orient(dest->orientation)));
      else
	return (get_direction(5, get_orient(dest->orientation)));
    }
  if (!y)
    {
      if (((clt->larg + x) % serv->map->larg) == dest->larg)
	return (get_direction(3, get_orient(dest->orientation)));
      else
	return (get_direction(7, get_orient(dest->orientation)));
    }
  return (get_direct(serv, clt, dest));
}

void		broadcast(t_server *serv, t_client *client, char *msg)
{
  t_client	*clt;
  char		str[1024];

  clt = serv->client;
  while (clt != NULL)
    {
      if (clt->sock != client->sock && clt->sock != serv->sock_graph
	  && clt->type == 1)
	{
	  snprintf(str, sizeof(str), "message %d,", get_dir(serv, client, clt));
	  msg = my_strcat(strdup(str), msg);
	  dprintf(clt->sock, "%s\n", msg);
	}
      bzero(str, 1024);
      clt = clt->next;
    }
}

//////////////////////// FCT 26 LIGNE /////////////////////////////

int		com_broadcast(t_server *server, char **tab, int sock)
{
  t_client	*client;
  char		*str;
  int		i;

  i = 0;
  str = malloc(sizeof(char) * 1);
  str[0] = '\0';
  while (tab[++i])
    {
      str = strcat(str, tab[i]);
      if (tab[i + 1])
  	str = strcat(str, " ");
    }
  client = server->client;
  while (client != NULL)
    {
      if (client->sock == sock && client->type == 1)
  	{
  	  broadcast(server, client, str);
  	  pbc(server, str, client->sock);
  	  return (return_ok(client->sock));
  	}
      client = client->next;
    }
  return (0);
}
