/*
** malloc.h for y in /home/corentin.bellamy/rendu_sec/project/PSU_2016_malloc
** 
** Made by bellamy corentin
** Login   <corentin.bellamy@epitech.net>
** 
** Started on  Wed Feb  8 18:37:30 2017 bellamy corentin
** Last update Thu Feb  9 19:53:42 2017 bellamy corentin
*/
#ifndef MALLOC_H_
#define MALLOC_H_

#include <pthread.h>
#include <stdlib.h>

#define true 1
#define false 0

typedef struct		s_brick
{
  int			free;
  size_t		size;
}			t_brick;

void			*g_last_valid_adress;
void			*g_managed_memory_start;
long int		g_old_nb;
int			g_init_it;
pthread_mutex_t		g_thread;

#define BRICK_SIZE sizeof(t_brick)

void	*malloc(size_t);
void	free(void *);
void	*realloc(void *, size_t);
void	*calloc(size_t, size_t);
void	put_hexa(size_t, int);
void	split_block(size_t, t_brick **, void **);
void	show_alloc_mem();
void	lock_thread();
void	unlock_thread();

#endif /* !MALLOC_H_ */
