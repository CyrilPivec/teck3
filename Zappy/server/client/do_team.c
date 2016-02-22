/*
** do_team.c for do_commande in /home/pivec_c/rendu/server_zap/server
** 
** Made by cyril pivec
** Login   <pivec_c@epitech.net>
** 
** Started on  Fri Jun 19 17:27:13 2015 cyril pivec
<<<<<<< HEAD
<<<<<<< HEAD
** Last update Sat Jul  4 21:09:49 2015 cyril pivec
=======
** Last update Sun Jul  5 00:51:10 2015 Florian Tousch
>>>>>>> 688f607ee2429bcaee339644886f86fa8f28def8
=======
** Last update Sat Jul  4 21:01:25 2015 Florian Tousch
>>>>>>> 08e0be7b28d74e68a25d034a86e26a070a460e69
*/

#include <server.h>

void		check_position(t_server *server)
{
  t_client	*client;

  client = server->client;
  while (client != NULL)
    {
      printf("x-> %d, y-> %d\n", client->haut, client->larg);
      client = client->next;
    }
}

void		init_p_team(t_server *server, t_client *client, char *name)
{
  client->team = name;
  client->haut = rand() % server->map->haut;
  client->larg = rand() % server->map->larg;
  client->orientation = HAUT;
  dprintf(client->sock, "%d %d\n", server->map->larg, server->map->haut);
  printf("server say-> %d %d\n", server->map->larg, server->map->haut);
}

void		set_team(t_server *server, char *name, int sock)
{
  t_client	*client;

  client = server->client;
  while (client != NULL)
    {
      if (client->sock == sock && client->type == 1)
	{
	  if (check_egg(server, name) == 1)
	    egg_become_ia(server, client, name);
	  else
	    init_p_team(server, client, name);
	  if (server->sock_graph > 0)
	    {
	      //send_map(server, server->sock_graph);
	      send_new_player(client, server->sock_graph);
	      send_inventaire(client, server->sock_graph);
	    }
	}
      client = client->next;
    }
}

void		say_nb_team(int sock, int nb)
{
  dprintf(sock, "%d\n", nb);
  printf("server say-> %d\n", nb);
}

int		do_team(t_server *server, char *str, int sock, t_team *ma)
{
  while (ma != NULL)
    {
      if (strcmp(ma->name, str) == 0)
	{
	  if (ma->nb > 0)
	    {
	      ma->nb--;
	      say_nb_team(sock, ma->nb);
	      set_team(server, ma->name, sock);
	      ma = server->team.begin;
	    }
	  else
	    {
	      return_ko(sock);
	      my_deconnexion(server, sock);
	      ma = server->team.begin;
	    }
	  return (1);
	}
      ma = ma->next;
    }
  ma = server->team.begin;
  return (0);
}
