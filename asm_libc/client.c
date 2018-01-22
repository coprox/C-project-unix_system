/*
** client.c for ok in /home/wong_b/rendu/PSU_2016_zappy/src/client
**
** Made by Agassi Wong
** Login   <agassi.wong@epitech.eu>
**
** Started on  Sat Jun 24 16:01:46 2017 Agassi Wong
** Last update Sun Jun 25 20:22:40 2017 florian lentz
*/

#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "get_next_line.h"
#include "client.h"

void		print_err_client(const char *str)
{
  fprintf(stderr, "%s", str);
  exit(84);
}

void		print_usage(void)
{
  fprintf(stderr, "USAGE: ./zappy_client -p port -n name -h machine\n");
  fprintf(stderr, "\tport\t\tis the port number\n");
  fprintf(stderr, "\tname\t\tis the name of the team\n");
  fprintf(stderr, "\tmachine\t\tis the name of the machine; ");
  fprintf(stderr, "localhost by default\n");
  exit(84);
}

void		init_client(t_client *client)
{
  client->port = -1;
  client->send = NULL;
  client->command = NULL;
  client->name = NULL;
  client->machine = NULL;
}

static int	open_file(const char *team)
{
  int		fd;
  char		*buffer;

  if ((fd = open(FILE_TEAM, O_RDONLY)) == -1)
    return (1);
  while ((buffer = get_next_line(fd)))
    if ((!strcmp(team, buffer)))
      return (0);
  fprintf(stderr, "%s%s\n", WRONG_TEAM, team);
  return (1);
}

int		check_arg(char **argv, t_client *client)
{
  int		i;

  i = 0;
  while (argv[i] && argv[i + 1] != NULL)
    {
      if (strcmp(argv[i], "-p") == 0)
	client->port = atoi(argv[i + 1]);
      else if (strcmp(argv[i], "-n") == 0)
	  client->name = argv[i + 1];
      else if (strcmp(argv[i], "-h") == 0)
	  client->machine = argv[i + 1];
      ++i;
    }
  return (i != 6) ? 1 : open_file(client->name);
}

int		init_all(t_client *client)
{
  struct protoent	*pe;
  struct sockaddr_in	s_in;

  pe = getprotobyname("TCP");
  if (!pe)
    return (1);
  if ((client->fd = socket(AF_INET, SOCK_STREAM, pe->p_proto)) == -1)
    return (1);
  s_in.sin_family = AF_INET;
  s_in.sin_port = htons(client->port);
  s_in.sin_addr.s_addr = inet_addr(client->machine);
  if (connect(client->fd, (struct sockaddr *)&s_in, sizeof(s_in)) == -1)
    {
      if (close(client->fd) == -1)
	return (1);
      return (1);
    }
  return (0);
}

int		get_input(t_client *client)
{
  if ((client->command = get_next_line(0)) == NULL)
    return (1);
  return (0);
}

void		write_client(t_client *client)
{
  dprintf(client->fd, "%s\n", client->send);
}

int		check_commands(t_client *client)
{
  client->send = strdup(client->command);
  return (0);
}

int		main(int argc, char **argv)
{
  t_client	client;

  int		r;
  char		buf[256];

  memset(buf, 0, 256);
  if (argc < 2 || (strcmp(argv[1], "-help") == 0))
    print_usage();
  init_client(&client);
  if (check_arg(argv, &client))
    return (84);
  while (init_all(&client) == 1)
    print_err_client("Initialization failed\n");
  printf("Connection established : ip = %s port = %d fd = %d\n",
	 client.machine, client.port, client.fd);
  dprintf(client.fd, "%s\n", client.name);
  if ((r = read(client.fd, buf, 256)) >= 256)
    {
      dprintf(1, "The client is protected against buffer overflow\n");
      return (84);
    }
  dprintf(1, "%s", buf);
  return (0);
}
