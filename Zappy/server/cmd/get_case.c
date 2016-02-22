/*
** get_case.c for get in /home/pivec_c/rendu/server_zap/server
** 
** Made by cyril pivec
** Login   <pivec_c@epitech.net>
** 
** Started on  Tue Jun 30 15:58:08 2015 cyril pivec
** Last update Sat Jul  4 19:22:24 2015 Florian Tousch
*/

#include <server.h>

int		get_nb_player(t_server *server, int larg, int haut)
{
  t_client	*client;
  int		i;

  i = 0;
  client = server->client;
  while (client != NULL)
    {
      if (client->larg == larg && client->haut == haut
	  && client->type == 1)
	i++;
      client = client->next;
    }
  return (i);
}

char		*get_player_case(t_server *server, int larg, int haut, char *str)
{
  int		nb;

  nb = get_nb_player(server, larg, haut);
  while (nb != 0)
    {
      str = my_strcat(str, " joueur");
      nb--;
    }
  return (str);
}

int		get_eggs_nb(t_server *server, int l, int h)
{
  t_egg		*egg;
  int		i;

  i = 0;
  egg = server->egg;
  while (egg != NULL)
    {
      if (egg->larg == l && egg->haut == h && egg->type == 1)
	i++;
      egg = egg->next;
    }
  return (i);
}

char		*get_eggs_case(t_server *server, int l, int h, char *str)
{
  int		nb;

  nb = get_eggs_nb(server, l, h);
  while (nb != 0)
    {
      str = my_strcat(str, " oeuf");
      nb--;
    }
  return (str);
}

char		*get_case(t_server *server, int larg, int haut, char *str)
{

  if (str)
    str = my_strcat(str, ",");
  if (!str && !(str = strdup("{")))
    return (NULL);
  str = get_player_case(server, larg, haut, str);
  str = get_eggs_case(server, larg, haut, str);
  str = get_food_case(server, larg, haut, str);
  str = get_linemate_case(server, larg, haut, str);
  str = get_deraumere_case(server, larg, haut, str);
  str = get_sibur_case(server, larg, haut, str);
  str = get_mendiane_case(server, larg, haut, str);
  str = get_phiras_case(server, larg, haut, str);
  str = get_thystame_case(server, larg, haut, str);
  return (str);
}
