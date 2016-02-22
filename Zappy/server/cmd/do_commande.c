/*
** do_commande.c for commande in /home/pivec_c/rendu/PSU_2014_myirc/src_server
** 
** Made by cyril pivec
** Login   <pivec_c@epitech.net>
** 
** Started on  Sat Apr 11 20:48:46 2015 cyril pivec
** Last update Sun Jul  5 15:54:36 2015 cyril pivec
** Last update Sun Jul  5 01:27:31 2015 Florian Tousch
*/

#include <server.h>

t_cmd_tab	g_tab[] =
  {
    {"avance", &com_avance, 7},
    {"droite", &com_droite, 7},
    {"gauche", &com_gauche, 7},
    {"voir", &com_voir, 7},
    {"inventaire", &com_inventaire, 1},
    {"prend", &com_prend, 7},
    {"pose", &com_pose, 7},
    {"expulse", &com_expulse, 7},
    {"broadcast", &com_broadcast, 7},
    {"incantation", &com_incantation, 600},
    {"fork", &com_fork, 42},
    {"connect_nbr", &com_connect_nbr, 0},
    {NULL, NULL, 0}
  };

t_cmd		*set_default_cmd(t_cmd *tmp, t_cmd_tab t, t_client *c, char **tab)
{
  tmp->fptr = t.fptr;
  tmp->time = 0;
  tmp->tab = tab;
  tmp->sock = c->sock;
  tmp->done = 0;
  tmp->next = NULL;
  tmp->prev = NULL;
  return (tmp);
}

void		add_cmd_time(t_server *s, t_cmd_tab t, t_client *c, char **tab)
{
  t_cmd		*tmp;
  struct	timeval	tv;

  tmp = malloc(sizeof(t_cmd));
  tmp = set_default_cmd(tmp, t, c, tab);
  if (c->cmd == NULL)
    {
      gettimeofday(&tv, NULL);
      tmp->time = tv.tv_sec + (t.time / s->arg->time);
      c->cmd = tmp;
    }
  else
    {
      while (c->cmd->next != NULL)
	c->cmd = c->cmd->next;
      tmp->time = c->cmd->time + (t.time / s->arg->time);
      tmp->prev = c->cmd;
      c->cmd->next = tmp;
      while (c->cmd->prev != NULL && c->cmd->done == 0)
	c->cmd = c->cmd->prev;
    }
}

int		do_commande(t_server *server, char *buffer, int sock)
{
  char		**tab;
  int		i;

  i = -1;
  if (buffer[0] == '\0')
    return (0);
  tab = my_str_to_wordtab(buffer, '\n');
  if (tab[0] == NULL)
    return (0);
  if (do_team(server, tab[0], sock, server->team.begin) == 1)
    return (1);
  if (do_graphic(server, tab[0], sock) == 1)
    return (1);
  while (g_tab[++i].cmd != NULL && strcmp(tab[0], g_tab[i].cmd));
  if (g_tab[i].cmd == NULL)
    return (return_ko(sock));
  if (!strcmp(tab[0], "fork") && server->sock_graph > 0)
  if (!strcmp(tab[0], "fork"))
    pfk(server, sock);
  add_cmd_time(server, g_tab[i], get_client2(server, sock), tab);
  return (1);
}
