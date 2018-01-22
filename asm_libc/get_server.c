/*
** serving.c for irc in /home/paute_a/PSU_2016_myirc
**
** Made by paute antoine
** Login   <paute_a@epitech.net>
**
** Started on  Fri Jun  9 21:23:12 2017 paute antoine
** Last update Sun Jun 25 17:07:43 2017 Dkamor
*/

#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "tools.h"
#include "get_next_line.h"
#include "client.h"

int	start_servering(t_socket *sock)
{
  sock->str = get_next_line(0);
  while (check_server(sock) == 1)
    {
      write(1, "wrong server\n", 14);
      sock->str = get_next_line(0);
    }
  return 0;
}

int	check_server2(t_socket *sock, char **tab)
{
  if (check_points(tab[1]) == 0)
   {
      tab = str_word_to_tab(sock->str, " :");
      if (tab[1] != NULL && tab[2] != NULL)
	sock->port = atoi(tab[2]);
      else
	return 1;
      sock->ip = tab[1];
    }
  else
    {
      sock->port = 6667;
      sock->ip = tab[1];
    }
  return 0;
}

int	check_server(t_socket *sock)
{
  char **tab;

  tab = str_word_to_tab(sock->str, " ");
  if (strcmp(tab[0], "SERVER") || strcmp(tab[0], "Server") ||
      strcmp(tab[0], "server") ||strcmp(tab[0], "/server"))
    {
      if (tab[1] == NULL)
	return (1);
      if (check_server2(sock, tab) == 1)
	return (1);
    }
  else
    return 1;
  return 0;
}

int	check_points(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    {
      if (str[i] == ':')
	return (0);
      i++;
    }
  return (1);
}
