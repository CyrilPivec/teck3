/*
** parser.c for zappy in /home/bekaou_r/rendu/zappy
** 
** Made by Rida Bekaouassa
** Login   <bekaou_r@epitech.net>
** 
** Started on  Wed Jun 17 15:09:18 2015 Rida Bekaouassa
** Last update Sun Jul  5 00:46:17 2015 Florian Tousch
*/

#include <stdio.h>
#include <string.h>
#include <parser.h>

void	print_usage()
{
  printf("Usage:./server\n\t-p [numero de port]\n\t-x [largeur du Monde]");
  printf("\n\t-y [hauteur du Monde]\n\t-n [nom_de_equipe_1 2 ...]");
  printf("\n\t-c [nombre de clients]\n\t-t [delai temporel]\n");
}

int	check_args(char **tab, char *args)
{
  int	i;
  int	j;
  int	nb;
  char	param[3];

  nb = 0;
  param[0] = '-';
  i = 1;
  while (tab[i])
    {
      j = 0;
      while (args[j])
	{
	  param[1] = args[j];
	  param[2] = '\0';
	  if (strcmp(tab[i], param) == 0)
	    nb++;
	  j++;
	}
      i++;
    }
  return (nb);
}

int	get_options(char **av, t_arg *opt)
{
  int	i;
  int	p;

  i = 1;
  while (av[i])
    {
      if (strcmp(av[i], "-p") == 0)
	opt->port = is_digit(av[i + 1], 'p');
      if (strcmp(av[i], "-x") == 0)
	opt->x = is_digit(av[i + 1], 'x');
      if (strcmp(av[i], "-y") == 0)
	opt->y = is_digit(av[i + 1], 'y');
      if (strcmp(av[i], "-c") == 0)
	opt->client_nb = is_digit(av[i + 1], 'c');
      if (strcmp(av[i], "-t") == 0)
	opt->time = is_digit(av[i + 1], 't');
      if (strcmp(av[i], "-n") == 0)
	p = i + 1;
      i++;
    }
  if (opt->port == 0 || opt->x == 0 || opt->y == 0 || opt->client_nb == 0
      || opt->time == 0 || opt->time > MAXTIME || get_names(av, opt, p) == 0)
    return (0);
  return (1);
}

int	parse_server(int ac, char **av, t_arg *opt)
{
  if (ac < 13)
    {
      print_usage();
      return (0);
    }
  if (check_args(av, "pxynct") != 6)
    {
      print_usage();
      return (0);
    }
  if (get_options(av, opt) == 0)
    return (0);
  return (1);
}
