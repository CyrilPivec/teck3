/*
** team.c for team in /home/pivec_c/rendu/server_zap/server
** 
** Made by cyril pivec
** Login   <pivec_c@epitech.net>
** 
** Started on  Thu Jun 18 18:06:44 2015 cyril pivec
** Last update Sun Jul  5 00:47:07 2015 Florian Tousch
*/

#include <server.h>
#include <parser.h>

void		init_team(t_server *server, int i)
{
  t_list_team	list;
  t_team	*ma;
  t_team	*tmp;

  list.begin = NULL;
  list.end = NULL;
  ma = NULL;
  while (server->arg->team_name[i] != 0)
    {
      ma = malloc(sizeof(t_team*));
      ma->name = strdup(server->arg->team_name[i]);
      ma->nb = server->arg->client_nb;
      if (i == 0)
	list.begin = ma;
      else
	tmp->next = ma;
      list.end = ma;
      i++;
      tmp = ma;
      ma = ma->next;
    }
  ma = list.begin;
  server->team = list;
  return ;
}

void		check_team(t_server *server)
{
  t_team	*ma;

  ma = server->team.begin;
  while (ma != NULL)
    {
      printf("equipe-> %s, nb %d\n", ma->name, ma->nb);
      ma = ma->next;
    }
  ma = server->team.begin;
}
