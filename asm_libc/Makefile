##
## Makefile for makefile in /home/lak_r/rendu/Semester4/Assembly/asm_test
## 
## Made by lak_r
## Login   <remi.lak@epitech.eu>
## 
## Started on  Sat Mar 11 17:39:50 2017 lak_r
## Last update Fri Mar 24 23:46:15 2017 Dkamor
##

NAME		=	libasm.so

SRCS		=	\
			strchr.s \
			strstr.s \
			memmove.s \
			strlen.s \
			memset.s \
			strcmp.s \
			memcpy.s \
			strncmp.s \
			strcasecmp.s \
			rindex.s \
			strcspn.s \
			strpbrk.s \

OBJS		=	$(SRCS:.s=.o)

NASM		=	nasm

ASM_FLAGS	=	-f elf64

CC		=	ld

SHARED		=	-shared

RM		=	rm -rfv


%.o:%.s
			$(NASM) $(ASM_FLAGS) -o $@ $<

all:			$(NAME)

$(NAME):		$(OBJS)
			$(CC) -o $(NAME) $(OBJS) $(SHARED)

clean:
			$(RM) $(OBJS)

fclean:			clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:			all clean fclean re
