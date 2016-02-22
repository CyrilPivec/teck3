/*
** parser.h for zappy in /home/bekaou_r/rendu/zappy
** 
** Made by Rida Bekaouassa
** Login   <bekaou_r@epitech.net>
** 
** Started on  Wed Jun 17 15:08:51 2015 Rida Bekaouassa
** Last update Sat Jul  4 21:11:00 2015 Florian Tousch
*/

#ifndef _PARSER_H_
# define _PARSER_H_

#define MAXTIME 1000000

typedef struct	s_arg
{
  int		port;
  int		x;
  int		y;
  char		**team_name;
  int		client_nb;
  int		time;
}		t_arg;

/*
** check_args.c
*/

int	is_digit(char *, char);
int	good_port(int);
int	is_another(char *);
int	nb_teams(char **);
int	get_names(char **, t_arg *, int);

/*
** parser.c
*/

void	print_usage();
int	check_args(char **, char *);
int	get_options(char **, t_arg *);
int	parse_server(int, char **, t_arg *);

#endif
