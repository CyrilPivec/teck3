/*
** my_read.c for read in /home/pivec_c/rendu/PSU_2014_myirc/src_server
** 
** Made by cyril pivec
** Login   <pivec_c@epitech.net>
** 
** Started on  Sat Apr 11 17:13:12 2015 cyril pivec
** Last update Sun Jul  5 15:56:37 2015 cyril pivec
** Last update Sun Jul  5 01:48:14 2015 Florian Tousch
*/

#include <server.h>

void                    my_read_s(t_server *server, int sock)
{
  int                   cs;
  struct sockaddr_in    sin_client;
  socklen_t                   len;

  len = sizeof(sin_client);
  cs = accept(sock, (struct sockaddr *)&sin_client, &len);
  printf("*** Connexion client : %d ***\n", sock + 1);
  write(cs, "BIENVENUE\n", strlen("BIENVENUE\n"));
  add_client(&server->client, cs, 1, my_read_c);
}

t_client		*get_client(t_client *client, int sock)
{
  t_client		*tmp;

  tmp = client;
  while (tmp != NULL)
    {
      if (tmp->sock == sock && tmp->type == 1)
	return (tmp);
      tmp = tmp->next;
    }
  return (NULL);
}

void			my_deconnexion(t_server *server, int sock)
{
  t_client		*client;

  if (server->sock_graph > 0)
    pdi(server, sock);
  close(sock);
  client = server->client;
  while (client != NULL)
    {
      if (client->sock == sock)
	client->type = 0;
      client = client->next;
    }
}

void			send_msg_c(int check, char buffer[1024], t_server *server, int sock)
{
  if (check == 1)
    {
      printf("Client say: %s", buffer);
      do_commande(server, buffer, sock);
      bzero(buffer, 1024);
    }
  else
    {
      my_deconnexion(server, sock);
      printf("Deconnexion client: %d\n", sock);
    }
}

void			my_read_c(t_server *server, int sock)
{
  char                  buffer[1024];
  char                  tmp[1024];
  t_norme_pute		norme;
  int			c;

  norme.i = (norme.check = 0);
  c = -1;
    while (norme.check == 0)
      {
	if ((norme.len = read(sock, tmp, 1024)) > 0)
	  {
	    norme.a = 0;
	    tmp[norme.len] = '\0';
	    while (tmp[norme.a] != '\0')
	      buffer[norme.i++] = tmp[norme.a++];
	    bzero(tmp, 1024);
	    while (buffer[++c] != '\0')
	      if (buffer[c] == '\n')
		norme.check = 1;
	  }
	else
	  norme.check = 2;
      }
  send_msg_c(norme.check, buffer, server, sock);
}
