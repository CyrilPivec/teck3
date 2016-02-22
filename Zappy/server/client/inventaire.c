/*
** inventaire.c for init_inventaire in /home/pivec_c/rendu/server_zap/server
** 
** Made by cyril pivec
** Login   <pivec_c@epitech.net>
** 
** Started on  Wed Jun 24 18:18:42 2015 cyril pivec
** Last update Sat Jul  4 19:11:15 2015 Florian Tousch
*/

#include <server.h>

void			init_inventaire(t_client *client)
{
  struct timeval	tv;

  client->inventaire = malloc(sizeof(t_list));
  client->inventaire->linemate = 0;
  client->inventaire->deraumere = 0;
  client->inventaire->sibur = 0;
  client->inventaire->mendiane = 0;
  client->inventaire->phiras = 0;
  client->inventaire->thystame = 0;
  client->inventaire->food = 11;
  gettimeofday(&tv, NULL);
  client->inventaire->time_food = tv.tv_sec;
}
