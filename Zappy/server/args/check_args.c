/*
** check_args.c for zappy in /home/bekaou_r/rendu/zappy
** 
** Made by Rida Bekaouassa
** Login   <bekaou_r@epitech.net>
** 
** Started on  Wed Jun 17 19:44:14 2015 Rida Bekaouassa
** Last update Sat Jul  4 19:10:23 2015 Florian Tousch
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <parser.h>

int	is_digit(char *str, char o)
{
  int	i;
  int	nb;

  i = 0;
  while (str[i])
    {
      if (str[i] < '0' || str[i] > '9' || atoi(str) == 0)
	{
	  if (o == 'x')
	    printf("Largeur invalide\n");
          if (o == 'y')
            printf("Hauteur invalide\n");
          if (o == 'c')
            printf("Nombre de clients invalide\n");
          if (o == 't')
            printf("Délai invalide\n");
	  return (0);
	}
      i++;
    }
  nb = atoi(str);
  if (o == 'p' && (nb = good_port(nb)) == 0)
    printf("Port invalide\n");
  return (nb);
}

int	good_port(int port)
{
  if (port < 1024 || port > 65535)
    return (0);
  return (port);
}

int	is_another(char *option)
{
  if (option == NULL || strcmp(option, "-p") == 0
      || strcmp(option, "-x") == 0
      || strcmp(option, "-y") == 0 || strcmp(option, "-c") == 0
      || strcmp(option, "-t") == 0)
    return (0);
  return (1);
}

int	nb_teams(char **av)
{
  int	i;
  int	nb;

  i = 0;
  nb = 0;
  while (av[i])
    {
      if (strcmp(av[i], "-n") == 0)
	{
	i++;
	while (is_another(av[i]) != 0)
	  {
	    i++;
	    nb++;
	  }
	}
      i++;
    }
  if (nb < 2)
    {
      printf("Minimum 2 équipes !\n");
      return (0);
    }
  return (nb);
}

int	get_names(char **av, t_arg *opt, int p)
{
  int	k;
  int	nb;

  nb = nb_teams(av);
  if (nb == 0)
    return (0);
  opt->team_name = malloc(sizeof(char *) * nb + 1);
  if (opt->team_name == NULL)
    return (0);
  k = 0;
  while (is_another(av[p]) != 0)
    {
      opt->team_name[k] = malloc(strlen(av[p]) * sizeof(char) + 1);
      if (opt->team_name[k] == NULL)
	return (0);
      strcpy(opt->team_name[k], av[p]);
      p++;
      k++;
    }
  return (1);
}
