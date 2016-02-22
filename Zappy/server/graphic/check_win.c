/*
** check_win.c for win in /home/pivec_c/rendu/server_zap/server
** 
** Made by cyril pivec
** Login   <pivec_c@epitech.net>
** 
** Started on  Fri Jul  3 05:17:52 2015 cyril pivec
** Last update Sun Jul  5 01:33:03 2015 Florian Tousch
*/

#include <server.h>

int		nb_player_win(t_server *server, char *team)
{
  t_client	*client;
  int		i;

  i = 0;
  client = server->client;
  while (client != NULL)
    {
      if (client->type == 1 && !strcmp(client->team, team) && client->lvl == 8)
	i++;
      client = client->next;
    }
  return (i);
}

void		check_win(t_server *server)
{
  t_team	*ma;

  ma = server->team.begin;
  while (ma != NULL)
    {
      if (nb_player_win(server, ma->name) >= 6)
	{
	  if (server->sock_graph > 0)
	    seg(server, ma->name);
	  return ;
	}
      ma = ma->next;
    }
  ma = server->team.begin;
}
