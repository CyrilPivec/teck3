/*
** get_case3.c for get in /home/pivec_c/rendu/server_zap/server
** 
** Made by cyril pivec
** Login   <pivec_c@epitech.net>
** 
** Started on  Tue Jun 30 15:47:34 2015 cyril pivec
** Last update Sat Jul  4 19:22:00 2015 Florian Tousch
*/

#include <server.h>

char		*get_phiras_case(t_server *server, int larg, int haut, char *str)
{
  int		i;

  i = 0;
  while (i < server->map->map[haut][larg].phiras)
    {
      str = my_strcat(str, " phiras");
      i++;
    }
  return (str);
}

char		*get_thystame_case(t_server *server, int larg, int haut, char *str)
{
  int		i;

  i = 0;
  while (i < server->map->map[haut][larg].thystame)
    {
      str = my_strcat(str, " thystame");
      i++;
    }
  return (str);
}

char		*my_strcat(char *dest, char *src)
{
  char		*str;

  if (!dest || !src)
    return (NULL);
  if (!(str = malloc(sizeof(char) * (strlen(dest) + strlen(src) + 1))))
    return (NULL);
  strcpy(str, dest);
  strcat(str, src);
  free(dest);
  return (str);
}
