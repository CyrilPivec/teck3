/*
** serveur.c for serveur in /home/pivec_c/rendu/PSU_2014_myirc/src_server
** 
** Made by cyril pivec
** Login   <pivec_c@epitech.net>
** 
** Started on  Fri Apr 10 15:28:46 2015 cyril pivec
** Last update Sat Jul  4 19:24:56 2015 Florian Tousch
*/

#include <server.h>
#include <parser.h>

int	main(int ac, char **av)
{
  t_server	server;
  t_arg		opt;

  srand(time(NULL));
  server.egg = NULL;
  server.client = NULL;
  server.sock_graph = 0;
  if (parse_server(ac, av, &opt) == 0)
    return (0);
  create_map(&server, opt);
  server.port = opt.port;
  server.arg = &opt;
  init_team(&server, 0);
  //  check_team(&server);
  if (init_server(&server) == 0)
    return (0);
  while (42)
    loop(&server);
  return (1);
}
