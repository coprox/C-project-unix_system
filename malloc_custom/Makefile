LIB	= libmy_malloc.so

LDFLAGS	+= -shared

CFLAGS += -fpic -W -Wall -Wextra -Werror

SRC	= malloc.c \
	  free_calloc_realloc.c \
	  tools.c \
	  malloc_split.c

CC	= gcc

RM	= rm -f

OBJ	= $(SRC:.c=.o)


all : $(LIB)

$(LIB) : $(OBJ)
	$(CC) $(LDFLAGS)  -o $(LIB) $(OBJ)

clean :
	$(RM) $(LIB)

fclean : clean
	$(RM) $(OBJ)

re : clean fclean all

.PHONY : all clean fclean re
