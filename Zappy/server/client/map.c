/*
** map.c for map in /home/pivec_c/rendu/server_zap
** 
** Made by cyril pivec
** Login   <pivec_c@epitech.net>
** 
** Started on  Tue Jun 16 16:42:29 2015 cyril pivec
** Last update Sat Jul  4 19:11:09 2015 Florian Tousch
*/

#include <server.h>

void		init_map(t_server *server)
{
  int		i;
  int		j;

  i = 0;
  j = 0;
  server->map->map = malloc(sizeof(t_list *) * (server->map->haut + 1));
  while (i < server->map->haut)
    {
      server->map->map[i] = malloc(sizeof(t_list) * (server->map->larg + 1));
      while (j < server->map->larg)
	{
	  server->map->map[i][j].linemate = 0;
	  server->map->map[i][j].deraumere = 0;
	  server->map->map[i][j].sibur = 0;
	  server->map->map[i][j].mendiane = 0;
	  server->map->map[i][j].phiras = 0;
	  server->map->map[i][j].thystame = 0;
	  server->map->map[i][j].food = 0;
	  j++;
	}
      j = 0;
      i++;
    }
  server->map->map[i] = NULL;
}

void		add_obj(t_map *list)
{
  int		type;
  int		h;
  int		l;

  type = rand() % 5 + 1;
  h = rand() % list->haut;
  l = rand() % list->larg;
  if (type == 1)
    list->map[h][l].linemate++;
  else if (type == 2)
    list->map[h][l].deraumere++;
  else if (type == 3)
    list->map[h][l].sibur++;
  else if (type == 4)
    list->map[h][l].mendiane++;
  else if (type == 5)
    list->map[h][l].phiras++;
  else if (type == 6)
    list->map[h][l].thystame++;
}

void		add_food(t_map *map)
{
  int		h;
  int		l;

  h = rand() % map->haut;
  l = rand() % map->larg;
  map->map[h][l].food++;
}

void		create_map(t_server *server, t_arg opt)
{
  int		nb;
  int		i;

  i = 0;
  server->map = malloc(sizeof(t_map));
  server->map->haut = opt.y;
  server->map->larg = opt.x;
  init_map(server);
  nb = ((server->map->haut * server->map->larg) * 50) / 100;
  while (i <= nb)
    {
      add_obj(server->map);
      i++;
    }
  nb = ((server->map->haut * server->map->larg) * 7) / 100;
  i = 0;
  while (i <= nb)
    {
      add_food(server->map);
      i++;
    }
}
