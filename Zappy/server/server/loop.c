/*
** loop.c for server in /home/pivec_c/rendu/PSU_2014_myirc/src_server
** 
** Made by cyril pivec
** Login   <pivec_c@epitech.net>
** 
** Started on  Sat Apr 11 17:02:38 2015 cyril pivec
** Last update Sat Jul  4 20:57:58 2015 cyril pivec
*/

#include <server.h>

void			check_event(t_server *s)
{
  struct timeval	actual;
  t_client		*c;

  c = s->client;
  while (c != NULL)
    {
      gettimeofday(&actual, NULL);
      if (c->cmd != NULL)
	if (c->cmd->time <= actual.tv_sec)
	  {
	    c->cmd->fptr(s, c->cmd->tab, c->cmd->sock);
	    printf("[COM:%s]: executé\n", c->cmd->tab[0]);
	    c->cmd->done = 1;
	    c->cmd = c->cmd->next;
	  }
      c = c->next;
    }
  return ;
}

void			del_food(t_server *s)
{
  t_client		*c;
  struct timeval	tv;

  c = s->client;
  gettimeofday(&tv, NULL);
  if (c->inventaire->time_food)
    if (c->inventaire->time_food <= tv.tv_sec)
      while (c != NULL)
	{
	  c->inventaire->food -= 1;
	  if (c->inventaire->food < 1)
	    my_deconnexion(s, c->sock);
	  c->inventaire->time_food += (1 * s->arg->time);
	  c = c->next;
	}
  // print message
  return ;
}

void			check_eggs(t_server *server)
{
  t_egg			*egg;
  struct timeval	tv;

  egg = server->egg;
  if (egg == NULL)
    return ;
  while (egg != NULL)
    {
      gettimeofday(&tv, NULL);
      if (egg->time == 0 && egg->type == 1)
	egg->time = tv.tv_sec + (200 * server->arg->time);
      else
	if (egg->time <= tv.tv_sec && egg->type == 1)
	  egg_dead(egg, server);
      egg = egg->next;
    }
}

int			do_select(t_server *server)
{
  if (select(server->fd_max + 1, &server->fd_read,
	     &server->fd_write, NULL, NULL) == -1)
    {
      printf("Erreur select\n");
      return (0);
    }
  check_event(server);
  del_food(server);
  check_eggs(server);
  return (1);
}

void			loop_end(t_server *server, t_client *client)
{
  while (client != NULL)
    {
      if (FD_ISSET(client->sock, &server->fd_read))
	client->fct_read(server, client->sock);
      client = client->next;
    }
}

int			loop(t_server *server)
{
  t_client		*client;

  FD_ZERO(&server->fd_read);
  FD_ZERO(&server->fd_write);
  server->fd_max = 0;
  client = server->client;
  while (client != NULL)
    {
      if (client->type != 0)
	{
	  FD_SET(client->sock, &server->fd_read);
	  FD_SET(client->sock, &server->fd_write);
	  server->fd_max = client->sock;
	}
      client = client->next;
    }
  if (do_select(server) == 0)
    return (0);
  client = server->client;
  loop_end(server, client);
  return (1);
}
