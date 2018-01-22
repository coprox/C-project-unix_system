/*
** malloc.c for y in /home/corentin.bellamy/rendu_sec/project/PSU_2016_malloc/test
** 
** Made by bellamy corentin
** Login   <corentin.bellamy@epitech.net>
** 
** Started on  Sun Jan 29 18:58:52 2017 bellamy corentin
** Last update Sun Feb 12 23:14:36 2017 bellamy corentin
*/

#include <string.h>
#include <unistd.h>
#include "malloc.h"

void			free(void *ptr)
{
  t_brick		*mem;
  void			*current_location;
  t_brick		*current_location_brick;

  current_location = g_managed_memory_start;
  mem = ptr - BRICK_SIZE;
  if (ptr >= g_managed_memory_start && ptr <= g_last_valid_adress)
    mem->free = true;
  while (current_location != g_last_valid_adress)
    {
      current_location_brick = (t_brick*)current_location;
      if (current_location_brick->free != true)
	return ;
      current_location += current_location_brick->size;
    }
  current_location_brick = (t_brick*)current_location;
  if (current_location_brick->free != true)
    return ;
  brk(g_managed_memory_start);
  g_init_it = false;
}

void			*realloc(void *ptr, size_t size)
{
  void			*tmp;

  free(ptr);
  tmp = malloc(size);
  if (ptr >= g_managed_memory_start && ptr <= g_last_valid_adress)
    memcpy(tmp, ptr, size);
  return (tmp);
}

void			*calloc(size_t nmemb, size_t size)
{
  void			*ptr;

  ptr = malloc(nmemb * size);
  return (memset(ptr, 0, nmemb * size));
}
