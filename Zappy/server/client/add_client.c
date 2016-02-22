/*
** add_fd.c for add_fd in /home/pivec_c/rendu/PSU_2014_myirc/src_server
** 
** Made by cyril pivec
** Login   <pivec_c@epitech.net>
** 
** Started on  Sun Apr 12 15:10:32 2015 cyril pivec
** Last update Sun Jul  5 01:47:01 2015 Florian Tousch
*/

#include <server.h>

int		check_client(t_client **client, int sock)
{
  t_client	*tmp;

  tmp = *client;
  while (tmp != NULL)
    {
      if (tmp->sock == sock)
	{
	  tmp->type = 1;
	  return (1);
	}
      tmp = tmp->next;
    }
  return (0);
}

void		add_client(t_client **client, int sock, int type, fct fct_read)
{
  t_client	*tmp;
  t_client	*tmp2;

  if (check_client(client, sock))
    return ;
  tmp = malloc(sizeof(*tmp));
  tmp->sock = sock;
  tmp->type = type;
  tmp->fct_read = fct_read;
  tmp->lvl = 1;
  tmp->next = NULL;
  tmp->cmd = NULL;
  init_inventaire(tmp);
  if (*client == NULL)
    *client = tmp;
  else
    {
      tmp2 = *client;
      while (tmp2->next != NULL)
	tmp2 = tmp2->next;
      tmp2->next = tmp;
    }
}
