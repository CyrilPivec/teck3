/*
** init_server.c for server in /home/pivec_c/rendu/PSU_2014_myirc/src_server
** 
** Made by cyril pivec
** Login   <pivec_c@epitech.net>
** 
** Started on  Fri Apr 10 15:42:37 2015 cyril pivec
** Last update Sat Jul  4 19:24:35 2015 Florian Tousch
*/

#include <server.h>

int			init_proto_sock(int *sock, struct sockaddr_in *sin,
					struct protoent *pe, int port)
{
  if ((pe = getprotobyname("TCP")) == NULL)
    {
      printf("Erreur proto\n");
      return (0);
    }
  if ((*sock = socket(PF_INET, SOCK_STREAM, pe->p_proto)) == -1)
    {
      printf("Erreur socket\n");
      return (0);
    }
  sin->sin_family = AF_INET;
  sin->sin_port = htons(port);
  sin->sin_addr.s_addr = INADDR_ANY;
  return (1);
}

int			init_bind_listen(int sock, struct sockaddr_in sin)
{
  if (bind(sock, (const struct sockaddr *)&sin, sizeof(sin)) == -1)
    {
      printf("Erreur bind\n");
      close(sock);
      return (0);
    }
  if (listen(sock, 42) == -1)
    {
      printf("Erreur listen\n");
      close(sock);
      return (0);
    }
  return (1);
}

int			init_server(t_server *server)
{
  int			sock;
  struct protoent	pe;
  struct sockaddr_in	sin;

  if (init_proto_sock(&sock, &sin, &pe, server->port) == 0)
    return (0);
  if (init_bind_listen(sock, sin) == 0)
    return (0);
  add_client(&server->client, sock, 2, my_read_s);
  return (1);
}
