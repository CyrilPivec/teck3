/*
** graphic2.c for graphic2 in /home/pivec_c/rendu/server_zap/server
** 
** Made by cyril pivec
** Login   <pivec_c@epitech.net>
** 
** Started on  Wed Jun 24 16:46:24 2015 cyril pivec
** Last update Sun Jul  5 01:33:14 2015 Florian Tousch
*/

#include <server.h>

int		get_orientation(VUE orient)
{
  if (orient == HAUT)
    return (1);
  else if (orient == BAS)
    return (3);
  else if (orient == DROITE)
    return (2);
  else if (orient == GAUCHE)
    return (4);
  else
    return (0);
}

void		send_new_player(t_client *client, int sock)
{
  dprintf(sock, "pnw %d %d %d %d %d %s\n", client->sock,
	  client->larg, client->haut, get_orientation(client->orientation),
	  client->lvl, client->team);
}

void		send_inventaire(t_client *client, int sock)
{
  dprintf(sock, "pin %d %d %d %d %d %d %d %d %d %d\n", client->sock,
	  client->larg, client->haut, client->inventaire->food,
	  client->inventaire->linemate,
	  client->inventaire->deraumere,
	  client->inventaire->sibur,
	  client->inventaire->mendiane,
	  client->inventaire->phiras,
	  client->inventaire->thystame);
}

void		send_position(t_client *client, int sock)
{
  dprintf(sock, "ppo %d %d %d %d\n", client->sock, client->larg,
	  client->haut, get_orientation(client->orientation));
}
