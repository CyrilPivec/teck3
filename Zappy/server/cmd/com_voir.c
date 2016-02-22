/*
** com_voir.c for voir in /home/pivec_c/rendu/server_zap/server
** 
** Made by cyril pivec
** Login   <pivec_c@epitech.net>
** 
** Started on  Mon Jun 29 19:19:55 2015 cyril pivec
** Last update Sun Jul  5 01:30:56 2015 Florian Tousch
*/

#include <server.h>

void		voir_left(t_server *server, int *x, int *y, VUE orientation)
{
  if (orientation == HAUT)
    (*x = (!*x) ? (server->map->larg - 1) : (*x - 1));
  if (orientation == BAS)
    (*x = (*x == server->map->larg - 1) ? (0) : (*x + 1));
  if (orientation == DROITE)
    (*y = (!*y) ? (server->map->haut - 1) : (*y - 1));
  if (orientation == GAUCHE)
    (*y = (*y == server->map->haut - 1) ? (0) : (*y + 1));
}

void		voir_line(t_server *server, int *x, int *y, VUE orientation)
{
  if (orientation == HAUT)
    (*x = (*x == server->map->larg - 1) ? (0) : (*x + 1));
  if (orientation == BAS)
    (*x = (!*x) ? (server->map->larg - 1) : (*x - 1));
  if (orientation == DROITE)
    (*y = (*y == server->map->haut - 1) ? (0) : (*y + 1));
  if (orientation == GAUCHE)
    (*y = (!*y) ? (server->map->haut - 1) : (*y - 1));
}

char		*do_voir(t_server *server, t_client *client, char *str, int size)
{
  int		x;
  int		y;
  int		i;

  x = client->larg;
  y = client->haut;
  i = -1;
  while (++i < size)
    voir_front(server, &x, &y, client->orientation);
  i = -1;
  while (++i < size)
    voir_left(server, &x, &y, client->orientation);
  i = -1;
  while (++i < 2 * size + 1 && (str = get_case(server, x, y, str)))
    voir_line(server, &x, &y, client->orientation);
  return (str);
}

void		fct_voir(t_server *server, t_client *client)
{
  int		i;
  char		*str;

  str = NULL;
  i = -1;
  while (++i < (client->lvl + 1))
    str = do_voir(server, client, str, i);
  str = my_strcat(str, "}");
  dprintf(client->sock, "%s\n", str);
  free(str);
}

int		com_voir(t_server *server, char **tab, int sock)
{
  t_client	*client;

  UNUSED(tab);
  client = server->client;
  while (client != NULL)
    {
      if (client->sock == sock && client->type == 1)
	{
	  fct_voir(server, client);
	  return (1);
	}
      client = client->next;
    }
  return (return_ko(sock));
}
