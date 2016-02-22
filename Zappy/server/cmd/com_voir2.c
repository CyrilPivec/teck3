/*
** com_voir2.c for  in /home/tousch_f/rendu/PSU_2014_zappy/server/cmd
** 
** Made by Florian Tousch
** Login   <tousch_f@epitech.net>
** 
** Started on  Sun Jul  5 01:30:41 2015 Florian Tousch
** Last update Sun Jul  5 01:30:55 2015 Florian Tousch
*/

#include <server.h>

void		voir_front(t_server *server, int *x, int *y, VUE orientation)
{
  if (orientation == HAUT)
    (*y = (!*y) ? (server->map->haut - 1) : (*y - 1));
  if (orientation == BAS)
    (*y = (*y == server->map->haut - 1) ? (0) : (*y + 1));
  if (orientation == DROITE)
    (*x = (*x == server->map->larg - 1) ? (0) : (*x + 1));
  if (orientation == GAUCHE)
    (*x = (!*x) ? (server->map->larg - 1) : (*x - 1));
}
