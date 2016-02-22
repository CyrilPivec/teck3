/*
** eggs.c for eggs in /home/pivec_c/rendu/server_zap/server
** 
** Made by cyril pivec
** Login   <pivec_c@epitech.net>
** 
** Started on  Thu Jul  2 04:09:47 2015 cyril pivec
<<<<<<< HEAD
<<<<<<< HEAD
** Last update Sat Jul  4 21:10:06 2015 cyril pivec
=======
** Last update Sat Jul  4 21:23:46 2015 Florian Tousch
>>>>>>> f42c2c36a81afb8d5de3234a3853f78470eb113a
=======
** Last update Sun Jul  5 00:56:38 2015 Florian Tousch
>>>>>>> 688f607ee2429bcaee339644886f86fa8f28def8
*/

#include <server.h>

t_egg		*get_dispo_egg(t_server *server, char *team)
{
  t_egg		*egg;

  egg = server->egg;
  while (egg != NULL)
    {
      if (!strcmp(egg->team, team) && egg->type == 1)
	return (egg);
      egg = egg->next;
    }
  return (NULL);
}

void		egg_become_ia(t_server *server, t_client *client, char *name)
{
  t_egg		*egg;

  egg = get_dispo_egg(server, name);
  if (egg == NULL)
    return ;
  client->team = name;
  client->haut = egg->haut;
  client->larg = egg->larg;
  client->orientation = HAUT;
  dprintf(client->sock, "%d %d\n", server->map->larg, server->map->haut);
  printf("server say-> %d %d\n", server->map->larg, server->map->haut);
  egg->type = 2;
  if (server->sock_graph > 0)
    {
      ebo(server, egg);
      /* eht(server, egg->nb); */
      /* send_new_player(client, server->sock_graph); */
      /* send_inventaire(client, server->sock_graph); */
    }
}

void		egg_dead(t_egg *egg, t_server *server)
{
  egg->type = 0;
  if (server->sock_graph > 0)
    edi(server, egg->nb);
  return ;
}

void		add_egg(t_server *server, t_client *client)
{
  t_egg		*egg;
  t_egg		*tmp;
  int		i;

  i = 0;
  tmp = malloc(sizeof(t_egg));
  tmp->type = 1;
  tmp->haut = client->haut;
  tmp->larg = client->larg;
  tmp->team = client->team;
  tmp->time = 0;
  tmp->father = client->sock;
  egg = server->egg;
  while (egg->next != NULL)
    {
      egg = egg->next;
      i++;
    }
  tmp->nb = i + 1;
  egg->next = tmp;
  if (server->sock_graph > 0)
    enw(server, tmp);
}

void		init_egg(t_server *server, t_client *client)
{
  server->egg = malloc(sizeof(t_egg));
  server->egg->type = 1;
  server->egg->haut = client->haut;
  server->egg->larg = client->larg;
  server->egg->team = client->team;
  server->egg->nb = 1;
  server->egg->time = 0;
  server->egg->father = client->sock;
  if (server->sock_graph > 0)
    enw(server, server->egg);
}
