/*
** com_incantation2.c for  in /home/tousch_f/rendu/PSU_2014_zappy/server/cmd
** 
** Made by Florian Tousch
** Login   <tousch_f@epitech.net>
** 
** Started on  Sun Jul  5 01:28:45 2015 Florian Tousch
** Last update Sun Jul  5 01:28:59 2015 Florian Tousch
*/

#include <server.h>

int		need_incant(int i, int j)
{
  int		inc[8][7] =
    {
      {1, 1, 0, 0, 0, 0, 0},
      {2, 1, 1, 1, 0, 0, 0},
      {2, 2, 0, 1, 0, 2, 0},
      {4, 1, 1, 2, 0, 1, 0},
      {4, 1, 2, 1, 3, 0, 0},
      {6, 1, 2, 3, 0, 1, 0},
      {6, 2, 2, 2, 2, 2, 1},
    };

  return (inc[i][j]);
}
