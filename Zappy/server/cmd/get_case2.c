/*
** get_case2.c for get in /home/pivec_c/rendu/server_zap/server
** 
** Made by cyril pivec
** Login   <pivec_c@epitech.net>
** 
** Started on  Tue Jun 30 04:56:21 2015 cyril pivec
** Last update Sat Jul  4 23:35:56 2015 Florian Tousch
*/

#include <server.h>

char		*get_food_case(t_server *server, int larg, int haut, char *str)
{
  int		i;

  i = 0;
  while (i < server->map->map[haut][larg].food)
    {
      str = my_strcat(str, " nourriture");
      i++;
    }
  return (str);
}

char		*get_linemate_case(t_server *server, int larg, int haut, char *str)
{
  int		i;

  i = 0;
  while (i < server->map->map[haut][larg].linemate)
    {
      str = my_strcat(str, " linemate");
      i++;
    }
  return (str);
}

char		*get_deraumere_case(t_server *server, int larg, int haut, char *str)
{
  int		i;

  i = 0;
  while (i < server->map->map[haut][larg].deraumere)
    {
      str = my_strcat(str, " deraumere");
      i++;
    }
  return (str);
}

char		*get_sibur_case(t_server *server, int larg, int haut, char *str)
{
  int		i;

  i = 0;
  while (i < server->map->map[haut][larg].sibur)
    {
      str = my_strcat(str, " sibur");
      i++;
    }
  return (str);
}

char		*get_mendiane_case(t_server *server, int larg, int haut, char *str)
{
  int		i;

  i = 0;
  while (i < server->map->map[haut][larg].mendiane)
    {
      str = my_strcat(str, " mendiane");
      i++;
    }
  return (str);
}
