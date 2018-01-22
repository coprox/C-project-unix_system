/*
** print_mem.c for y in /home/corentin.bellamy/rendu_sec/project/PSU_2016_malloc
** 
** Made by bellamy corentin
** Login   <corentin.bellamy@epitech.net>
** 
** Started on  Wed Feb  8 16:48:06 2017 bellamy corentin
** Last update Thu Feb  9 16:08:28 2017 bellamy corentin
*/

#include <unistd.h>
#include "malloc.h"

void		put_hexa(size_t nb, int check)
{
  char		stock;
  if (nb != 0)
    {
      (check == 1) ? put_hexa(nb / 16, 1) : put_hexa(nb / 10, 0);
      stock = (check == 1) ? ((nb % 16 > 9) ? (nb % 16) + 55
			      : (nb % 16) + 48) : (nb % 10) + 48;
      write(1, &stock, 1);
    }
}

void		show_alloc_mem()
{
  void		*current_location;
  t_brick	*current_location_brick;

  write(1, "break : 0x", 10);
  put_hexa((size_t)sbrk(0), 1);
  write(1, "\n", 1);
  current_location = g_managed_memory_start;
  while (current_location != g_last_valid_adress)
    {
      current_location_brick = (t_brick*)current_location;
      write(1, "0x", 2);
      put_hexa((size_t)current_location, 1);
      write(1, " - 0x", 5);
      put_hexa((size_t)current_location + current_location_brick->size, 1);
      write(1, " : ", 3);
      put_hexa(current_location_brick->size, 0);
      write(1, "\n", 1);
      current_location += current_location_brick->size;
    }
}

void		lock_thread()
{
  pthread_mutex_lock(&g_thread);
}

void		unlock_thread()
{
  pthread_mutex_unlock(&g_thread);
}

