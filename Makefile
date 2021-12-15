SRCS_SERV= server.c
SRCS_USER= user.c

INCS= minitalk.h

OBJS_SERV= ${SRCS_SERV:.c=.o}
OBJS_USER= ${SRCS_USER:.c=.o}


CFLAGS= -Wall -Wextra -Werror
NAME_SERV= server
NAME_USER= user


all: $(NAME_SERV) $(NAME_USER)

.c.o:
	@echo Compiling $<
	gcc $(CFLAGS) -c $< -o ${<:.c=.o}

$(NAME_SERV): $(OBJS_SERV)
	gcc $(CFLAGS) libftprintf.a $(OBJS_SERV) -o $(NAME_SERV)

$(NAME_USER): $(OBJS_USER)
	gcc $(CFLAGS) libftprintf.a $(OBJS_USER) -o $(NAME_USER)

re: fclean all

clean:
	rm -f $(OBJS_SERV)
	rm -f $(OBJS_USER)

fclean: clean
	rm -f $(NAME_SERV)
	rm -f $(NAME_USER)

out:
	gcc $(CFLAGS) $(SRCS_SERV) $(SRCS_USER)
