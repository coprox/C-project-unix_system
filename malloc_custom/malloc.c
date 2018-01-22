/*
** malloc.c for y in /home/corentin.bellamy/rendu_sec/project/PSU_2016_malloc
** 
** Made by bellamy corentin
** Login   <corentin.bellamy@epitech.net>
** 
** Started on  Mon Feb  6 19:26:29 2017 bellamy corentin
** Last update Sun Feb 12 23:14:02 2017 bellamy corentin
*/
#include <stdio.h>
#include <unistd.h>
#include "malloc.h"

static int		malloc_init()
{
  if ((g_last_valid_adress = sbrk(0)) == (void*)-1)
    return (true);
  g_managed_memory_start = g_last_valid_adress;
  g_old_nb = 0;
  g_init_it = true;
  return (false);
}

static void		loop_malloc(size_t size, void **current_location,
				    t_brick **current_location_brick,
				    void **memory_location)
{
  while (*current_location != g_last_valid_adress)
    {
      *current_location_brick = (t_brick*)*current_location;
      if ((*current_location_brick)->free &&
	  (*current_location_brick)->size >= size)
	{
	  (*current_location_brick)->free = false;
	  *memory_location = *current_location;
	  if ((*current_location_brick)->size > size &&
	      (*current_location_brick)->size - size > BRICK_SIZE)
	    split_block(size, current_location_brick, current_location);
	  return ;
	}
      *current_location += (*current_location_brick)->size;
    }
}

static int		allocation_memory(int size, int get_page_size)
{
  long int		count;

  count = get_page_size;
  if (g_old_nb == size && size <= get_page_size
      && sbrk(get_page_size) == (void*)-1)
      return (true);
  else if (g_old_nb == size && size >= get_page_size)
    {
      while (count < g_old_nb)
	count += get_page_size;
      if (sbrk(count) == (void*)-1)
	return (true);
      g_old_nb = (g_old_nb - count) * -1;
    }
  else if (g_old_nb > get_page_size)
    {
      while (count < g_old_nb)
	count += get_page_size;
      if (sbrk(count - get_page_size) == (void*)-1)
	return (true);
       g_old_nb = (g_old_nb - count) * -1;
    }
  return (false);
}

static int		create_brick(size_t size, void **memory_location,
				     t_brick **current_location_brick)
{
 long int		get_page_size;

 get_page_size = getpagesize();
 g_old_nb += size;
 if (allocation_memory(size, get_page_size) == true)
   return (true);
 *memory_location = g_last_valid_adress;
 g_last_valid_adress += size;
 *current_location_brick = *memory_location;
 (*current_location_brick)->free = false;
 (*current_location_brick)->size = size;
 return (false);
}

void			*malloc(size_t size)
{
  void			*current_location;
  static int		check_init = false;
  t_brick		*current_location_brick;
  void			*memory_location;

  lock_thread();
  if (check_init == false)
    {
      g_init_it = false;
      check_init = true;
    }
  if (g_init_it == false && malloc_init() == true)
    return (NULL);
  size = size + BRICK_SIZE;
  memory_location = NULL;
  current_location = g_managed_memory_start;
  loop_malloc(size, &current_location,
	      &current_location_brick, &memory_location);
  if (memory_location == false &&
      create_brick(size, &memory_location,
		   &current_location_brick) == true)
    return (NULL);
  memory_location += BRICK_SIZE;
  unlock_thread();
  return (memory_location);
}
