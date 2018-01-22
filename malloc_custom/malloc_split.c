/*
** malloc_split.c for y in /home/corentin.bellamy/rendu_sec/project/PSU_2016_malloc
** 
** Made by bellamy corentin
** Login   <corentin.bellamy@epitech.net>
** 
** Started on  Thu Feb  9 14:01:48 2017 bellamy corentin
** Last update Thu Feb  9 19:42:25 2017 bellamy corentin
*/

#include "malloc.h"

void		split_block(size_t size, t_brick **current_location_brick,
			    void **current_location)
{
  void		*next_location;
  t_brick	*next_brick;

  next_location = *current_location + size;
  next_brick = (t_brick *)next_location;
  next_brick->size = (*current_location_brick)->size - size;
  next_brick->free = true;
  (*current_location_brick)->size = size;
  return ;
}
