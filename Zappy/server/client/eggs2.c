/*
** eggs2.c for  in /home/tousch_f/rendu/PSU_2014_zappy/server/client
** 
** Made by Florian Tousch
** Login   <tousch_f@epitech.net>
** 
** Started on  Sun Jul  5 00:56:21 2015 Florian Tousch
** Last update Sun Jul  5 00:56:40 2015 Florian Tousch
*/

#include <server.h>

int		check_egg(t_server *server, char *team)
{
  t_egg		*egg;

  egg = server->egg;
  while (egg != NULL)
    {
      if (!strcmp(egg->team, team) && egg->type == 1)
	return (1);
      egg = egg->next;
    }
  return (0);
}
