SRCS_SERV= server.c
SRCS_USER= user.c

INCS_SERV= server.h
INCS_USER= user.h

OBJS_SERV= ${SRCS_SERV:.c=.o}
OBJS_USER= ${SRCS_USER:.c=.o}


CFLAGS= -Wall -Wextra -Werror
NAME_SERV= server
NAME_USER= user


all: $(NAME)

.c.o:
	@echo Compiling $<
	gcc $(CFLAGS) $< -o ${<:.c=.o}

$(NAME): $(OBJS)
	gcc $(CFLAGS) $(OBJS_SERV) $(NAME_SERV)
	gcc $(CFLAGS) $(OBJS_USER) $(NAME_USER)

re: fclean $(NAME)

clean:
	rm -f $(OBJS_SERV)
	rm -f $(OBJS_USER)

fclean: clean
	rm -f $(NAME_SERV)
	rm -f $(NAME_USER)

out:
	gcc $(CFLAGS) $(SRCS_SERV) $(SRCS_USER)
