/*
** return.c for  in /home/tousch_f/zappy/server
** 
** Made by Florian Tousch
** Login   <tousch_f@epitech.net>
** 
** Started on  Tue Jun 23 16:50:40 2015 Florian Tousch
** Last update Sat Jul  4 19:24:10 2015 Florian Tousch
*/

#include <server.h>

int	return_ok(int sock)
{
  dprintf(sock, "ok\n");
  return (1);
}

int	return_ko(int sock)
{
  dprintf(sock, "ko\n");
  return (0);
}
